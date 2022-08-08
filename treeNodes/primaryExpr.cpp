#include "../absyn.hpp"
#include "../treeClasses/scope.hpp"

PrimaryExpr_::PrimaryExpr_(Operand o){
    operand = o;
}
PrimaryExpr_::PrimaryExpr_(PrimaryExpr pe, Arguments a){
    primaryExpr = pe;
    arguments = a;
}

void PrimaryExpr_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "PrimaryExpr" << "\n";
    if (operand != nullptr){
        operand->print(d+1);
    }
    if(primaryExpr != nullptr){
        primaryExpr->print(d+1);
        arguments->print(d+1);
    }

}

vector<string> PrimaryExpr_::getType(vector<Scope>& scopeStack, vector<string>& typeErrors){
    //If expression is not a function call
    if (arguments == nullptr){
        return operand->getType(scopeStack, typeErrors);
    }
    //If expression is a function call
    else{
        vector<vector<string>> types = arguments->getArgumentTypes(scopeStack, typeErrors);

        bool allSingleValued = true;
        for (int i = 0; i < types.size();++i){
            if (types[i].size() != 1){
                allSingleValued = false;
                break;
            }
        }

        bool singleMultiValued = false;
        if (types.size() == 1 && types[0].size() > 1){
            singleMultiValued = true;
        }

        //If arguments are single valued expressions
        if(allSingleValued){
            string functionName = primaryExpr->getId();
            if (functionName != ""){
                //Search for function on scope stack
                try{
                    Signature signature = scopeStack[0]->getFunctionSignature(functionName);
                    vector<std::pair<string, string>> signatureParameters = signature->getParameters();
                    vector<std::pair<string, string>> signatureResults = signature->getResults();
                    //Check if arguments are same size as parameters
                    if (types.size() != signatureParameters.size()){
                        typeErrors.push_back("Argument list different size as parameter list!");
                        return {"undefined"};
                    }
                    else{
                        //Check if types correspond
                        for (int i = 0; i < types.size();++i){
                            if (types[i][0] != signatureParameters[i].second){
                                typeErrors.push_back("Argument types don't correspond with parameter types");
                                return {"undefined"};
                            }
                        }

                        //If everything is correct
                        vector<string> returnTypes;
                        for (int i = 0; i < signatureResults.size();++i){
                            returnTypes.push_back(signatureResults[i].second);
                        }

                        return returnTypes;
                    }

                }
                catch (exception e){
                    typeErrors.push_back("Function call references non existent function!");
                    return {"undefined"};
                }
                
            }
            else{
                typeErrors.push_back("Function name must be identifier!");
                return {"undefined"};
            }
        }
        else if (singleMultiValued){
            //Function call inside of function call
            string functionName = primaryExpr->getId();
            if (functionName != ""){
                //Search for function on scope stack
                try{
                    Signature signature = scopeStack[0]->getFunctionSignature(functionName);
                    vector<std::pair<string, string>> signatureParameters = signature->getParameters();
                    vector<std::pair<string, string>> signatureResults = signature->getResults();
                    //Check if arguments are same size as parameters
                    if (types[0].size() != signatureParameters.size()){
                        typeErrors.push_back("Argument list different size as parameter list!");
                        return {"undefined"};
                    }
                    else{
                        //Check if types correspond
                        for (int i = 0; i < types[0].size();++i){
                            if (types[0][i] != signatureParameters[i].second){
                                typeErrors.push_back("Argument types don't correspond with parameter types");
                                return {"undefined"};
                            }
                        }

                        //If everything is correct
                        vector<string> returnTypes;
                        for (int i = 0; i < signatureResults.size();++i){
                            returnTypes.push_back(signatureResults[i].second);
                        }

                        return returnTypes;
                    }

                }
                catch (exception e){
                    typeErrors.push_back("Function call references non existent function!");
                    return {"undefined"};
                }

            }
            else{
                typeErrors.push_back("Function name must be identifier!");
                return {"undefined"};
            }
            
        }
        else{
            typeErrors.push_back("Function arguments are not valid!");
            return {"undefined"};
        }

    }
}

vector<string> PrimaryExpr_::getValue(vector<Scope>& scopeStack, vector<string>& typeErrors){
    //If operand
    if (arguments == nullptr){
        return operand->getValue(scopeStack, typeErrors);
    }
    //If function call
    else{
        string functionName = primaryExpr->getId();
        Block functionBlock = scopeStack[0]->getFunctionBlock(functionName);
        Signature functionSignature = scopeStack[0]->getFunctionSignature(functionName);
        bool halted = false;
        vector<vector<string>> values = arguments->getArgumentValues(scopeStack, typeErrors);
        vector<std::pair<string, string>> identifiersAndTypes = functionSignature->getParameters();
        vector<std::pair<string, string>> resultIdentifiersAndTypes = functionSignature->getResults();

        scopeStack.push_back(new Scope_());

        //Add parameters to scope
        bool multiValued = false;
        if (values.size() == 1 && values[0].size() > 1){
            multiValued = true;
        }
        //If single valued expressions as arguments
        if (!multiValued){
            for (int i = 0; i < values.size();++i){
                scopeStack[scopeStack.size()-1]->addVariableValue(identifiersAndTypes[i].first, identifiersAndTypes[i].second, values[i][0]);              
            }
        }
        //If one multi valued expression as argument
        else{
            for (int i = 0; i < values[0].size();++i){
                scopeStack[scopeStack.size()-1]->addVariableValue(identifiersAndTypes[i].first, identifiersAndTypes[i].second, values[0][i]);              
            }
        }     

        //Add return parameters to scope
        //Check if they are named
        bool named = true;
        for (int i = 0; i < resultIdentifiersAndTypes.size();++i){
            if (resultIdentifiersAndTypes[i].first == ""){
                named = false;
                break;
            }
        }

        if (named){
            for (int i = 0; i < resultIdentifiersAndTypes.size();++i){
                if (resultIdentifiersAndTypes[i].second == "int"){
                    scopeStack[scopeStack.size()-1]->addVariableValue(resultIdentifiersAndTypes[i].first, resultIdentifiersAndTypes[i].second, "0");
                }
                else if (resultIdentifiersAndTypes[i].second == "bool"){
                    scopeStack[scopeStack.size()-1]->addVariableValue(resultIdentifiersAndTypes[i].first, resultIdentifiersAndTypes[i].second, "false");
                }
                else{
                    scopeStack[scopeStack.size()-1]->addVariableValue(resultIdentifiersAndTypes[i].first, resultIdentifiersAndTypes[i].second, "undefined");
                }
            }
        }

        //functionBlock->interpret(scopeStack, typeErrors, halted);
        scopeStack[scopeStack.size()-1]->print();
        scopeStack.pop_back();

        //Get result value of function
        vector<string> functionResult = scopeStack[0]->getCurrentFunctionResultValues();
        return functionResult;
    }
}

string PrimaryExpr_::getId(){
    if (operand != nullptr){
        return operand->getId();
    }
    else{
        return "";
    }
}