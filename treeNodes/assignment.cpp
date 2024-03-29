#include "../absyn.hpp"
#include "../treeClasses/scope.hpp"

Assignment_::Assignment_(ExpressionList el1, const char* ao, ExpressionList el2){
    expressionList1 = el1;
    assignOp = ao;
    expressionList2 = el2;
}

void Assignment_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "Assignment" << "\n";
    expressionList1->print(d+1);
    std::cout << std::string((d+1)*printWidth, ' ') << "AssignOp: " << assignOp << "\n";
    expressionList2->print(d+1);

}

void Assignment_::typeCheck(vector<Scope>& scopeStack, vector<string>& typeErrors){
    vector<vector<string>> types1;
    vector<vector<string>> types2;
    expressionList1->getTypes(scopeStack, typeErrors, types1);
    expressionList2->getTypes(scopeStack, typeErrors, types2);

    //Check if left side are identifiers
    vector<string> ids;
    expressionList1->getIds(ids);
    for (int i = 0; i < ids.size();++i){
        if (ids[i] == ""){
            typeErrors.push_back("One or more left hand side operands of assignment are not identifiers!");
            return;
        }
    } 
    
    bool allSingleValued = true;
    for (int i = 0; i < types2.size();++i){
        if (types2[i].size() != 1){
            allSingleValued = false;
            break;
        }
    }
    bool singleMultiValued = false;
    if (types2.size() == 1 && types2[0].size() > 1){
        singleMultiValued = true;
    }

    if (assignOp == "assign"){
        //If single valued expressions       
        if (allSingleValued){
            //Check if expression list is same size as identifier list
            if (types2.size() == ids.size()){
                //Check if types correspond with given type
                for (int i = 0; i < types2.size();++i){
                    if (types1[i][0] != types2[i][0]){
                        typeErrors.push_back("Left and right hand expressions don't have corresponding types!");
                        return;
                    }
                }
            }
            else{
                typeErrors.push_back("Expression list and identifier list are not the same size!");
                return;
            } 
        }   
        //If one multi valued expression  
        else if(singleMultiValued){
            //If multi valued expression has equal values to identifier count
            if (types2[0].size() == ids.size()){

                //Check if types correspond with given type
                for (int i = 0; i < types2[0].size();++i){
                    if (types2[0][i] != types1[i][0]){
                        typeErrors.push_back("Left and right hand expressions don't have corresponding types!");
                        return;
                    }
                }
            }
            else{
                typeErrors.push_back("Multi valued expression not the same size as identifier list!");
                return;
            }
        }
        else{
            typeErrors.push_back("Incorrect assignment!");
            return;
        }
    } 
    else{
        if (!(ids.size() == 1 && allSingleValued && types2.size() == 1)){
            typeErrors.push_back("Incorrect arithmetic assignment!");
            return;
        }
        else{
            if (!(types1[0][0] == "int" && types2[0][0] == "int")){
                typeErrors.push_back("Arithmetic assignment not defined for this type!");
                return;
            }
        }
    }   

}

void Assignment_::interpret(vector<Scope>& scopeStack, vector<string>& typeErrors){
    vector<vector<string>> values;
    vector<string> ids;
    expressionList1->getIds(ids);
    expressionList2->getValues(scopeStack, typeErrors, values);

    bool allSingleValued = true;
    for (int i = 0; i < values.size();++i){
        if (values[i].size() != 1){
            allSingleValued = false;
            break;
        }
    }

    if(allSingleValued){
        if (assignOp == "assign"){
            for (int i = 0; i < ids.size();++i){
                //Search for identifier in scope stack
                std::pair<string, string> typeValue;
                int scopeLevel = 0;
                for (int j = 0; j < scopeStack.size();++j){
                    try{
                        typeValue = scopeStack[scopeStack.size()-1-j]->getVariableValue(ids[i]);   
                        break;
                    }
                    catch (exception e){    
                                
                    }        
                    scopeLevel++; 
                }

                //Update scope stack
                scopeStack[scopeStack.size()-1-scopeLevel]->updateVariableValue(ids[i], typeValue.first, values[i][0]);

            }       
        }      
        else{
            //Search for identifier in scope stack
            std::pair<string, string> typeValue;
            int scopeLevel = 0;
            for (int j = 0; j < scopeStack.size();++j){
                try{
                    typeValue = scopeStack[scopeStack.size()-1-j]->getVariableValue(ids[0]);   
                    break;
                }
                catch (exception e){    
                            
                }        
                scopeLevel++; 
            }

            //Update scope stack
            if (assignOp == "plusassign"){
                values[0][0] = std::to_string(stoi(typeValue.second) + stoi(values[0][0]));
            }
            if (assignOp == "minassign"){
                values[0][0] = std::to_string(stoi(typeValue.second) - stoi(values[0][0]));
            }
            if (assignOp == "mulassign"){
                values[0][0] = std::to_string(stoi(typeValue.second) * stoi(values[0][0]));
            }
            if (assignOp == "divassign"){
                values[0][0] = std::to_string(stoi(typeValue.second) / stoi(values[0][0]));
            }
            scopeStack[scopeStack.size()-1-scopeLevel]->updateVariableValue(ids[0], typeValue.first, values[0][0]);
        }
    }
    //If one multi valued expression
    else{
        for (int i = 0; i < ids.size();++i){
            //Search for identifier in scope stack
            std::pair<string, string> typeValue;
            int scopeLevel = 0;
            for (int j = 0; j < scopeStack.size();++j){
                try{
                    typeValue = scopeStack[scopeStack.size()-1-j]->getVariableValue(ids[i]);
                    break;
                }
                catch (exception e){          
                }        
                scopeLevel++;   
            }

            //Update scope stack
            scopeStack[scopeStack.size()-1-scopeLevel]->updateVariableValue(ids[i], typeValue.first, values[0][i]);

        }     
    }


}

