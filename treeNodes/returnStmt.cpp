#include "../absyn.hpp"
#include "../treeClasses/scope.hpp"

ReturnStmt_::ReturnStmt_(){

}
ReturnStmt_::ReturnStmt_(ExpressionList el){
    expressionList = el;
}

void ReturnStmt_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "ReturnStmt" << "\n";
    if (expressionList != nullptr){
        expressionList->print(d+1);
    }

}

void ReturnStmt_::typeCheck(vector<Scope>& scopeStack, vector<string>& typeErrors){

    string currentFunctionName = scopeStack[0]->getCurrentFunctionName();
    Signature currentFunctionSignature = scopeStack[0]->getFunctionSignature(currentFunctionName);
    vector<std::pair<string, string>> signatureResults = currentFunctionSignature->getResults();

    //If there is no result in the signature
    if (signatureResults.size() == 0){
        if (expressionList != nullptr){
            typeErrors.push_back("Too many return values!");
        }
        return;
    }
    //If the expression list is empty (check for named results in signature)
    else if (expressionList == nullptr){

        vector<string> allIdentifiersResults;
        for (int i = 0; i < signatureResults.size();++i){
            allIdentifiersResults.push_back(signatureResults[i].first);
        }

        bool namedResults = true;
        bool unnamedResults = true;

        for (int i = 0; i < allIdentifiersResults.size();++i){
            if (allIdentifiersResults[i] != ""){
                unnamedResults = false;
            }
            if (allIdentifiersResults[i] == ""){
                namedResults = false;
            }
        }

        if (!namedResults){
            typeErrors.push_back("Empty return statement only allowed when all result types are named!");
            return;
        }
    }
    else{
        vector<vector<string>> returnTypes;
        expressionList->getTypes(scopeStack, typeErrors, returnTypes);

        bool allSingleValued = true;
        for (int i = 0; i < returnTypes.size();++i){
            if (returnTypes[i].size() != 1){
                allSingleValued = false;
                break;
            }
        }
        bool singleMultiValued = false;
        if (returnTypes.size() == 1 && returnTypes[0].size() > 1){
            singleMultiValued = true;
        }

        //If single valued return values
        if (allSingleValued){
            //If return values are not the same size as signature results
            if (returnTypes.size() != signatureResults.size()){
                typeErrors.push_back("Return values not same size as signature results!");
                return;
            }
            else{
                for (int i = 0; i < returnTypes.size();++i){
                    //If types don't correspond
                    if (returnTypes[i][0] != signatureResults[i].second){
                        typeErrors.push_back("Return values not the same type as signature results!");
                        return;
                    }
                }
            }
        }
        //If one multi valued return value
        else if (singleMultiValued){
            if (returnTypes[0].size() != signatureResults.size()){
                typeErrors.push_back("Return values not same size as signature results!");
                return;
            }
            else{
                for (int i = 0; i < returnTypes[0].size();++i){
                    //If types don't correspond
                    if (returnTypes[0][i] != signatureResults[i].second){
                        typeErrors.push_back("Return values not the same type as signature results!");
                        return;
                    }
                }
            }
        }
        //Return values formated wrongly
        else{
            typeErrors.push_back("Incorrect return values!");
        }
    }

}

void ReturnStmt_::interpret(vector<Scope>& scopeStack, vector<string>& typeErrors, bool& halted){
    if (!halted){
        string currentFunctionName = scopeStack[0]->getCurrentFunctionName();
        Signature currentFunctionSignature = scopeStack[0]->getFunctionSignature(currentFunctionName);
        vector<std::pair<string, string>> signatureResults = currentFunctionSignature->getResults();

        //If there are no results in the signature
        if (signatureResults.size() == 0){
            halted = true;
            return;
        }
        //If there are no results in the result statement, use named parameters from signature
        else if (expressionList == nullptr){


            std::pair<string, string> typeValue;
            vector<string> returnValues;
            //Find variable in scope stack, starting from most recent scope
            for (int i = 0; i < signatureResults.size();++i){
                for (int j = 0; j < scopeStack.size();++j){
                    try{
                        typeValue = scopeStack[scopeStack.size()-1-j]->getVariableValue(signatureResults[i].first);
                        break;
                    }
                    catch (exception e){          
                    }           
                }
                returnValues.push_back(typeValue.second);
            }

            scopeStack[0]->setCurrentFunctionResultValues(returnValues);
            halted = true;
            return;
        }
        //If there are result values in the result statement
        else{
            vector<vector<string>> returnValues;
            vector<string> newReturnValues;
            expressionList->getValues(scopeStack, typeErrors, returnValues);

            bool allSingleValued = true;
            for (int i = 0; i < returnValues.size();++i){
                if (returnValues[i].size() != 1){
                    allSingleValued = false;
                    break;
                }
            }

            if (allSingleValued){
                for (int i = 0; i < returnValues.size();++i){
                    newReturnValues.push_back(returnValues[i][0]);
                }
            }
            //If single multi valued return value
            else{
                for (int i = 0; i < returnValues[0].size();++i){
                    newReturnValues.push_back(returnValues[0][i]);
                }
            }

            scopeStack[0]->setCurrentFunctionResultValues(newReturnValues);
            halted = true;
            return;
        }
    }
}