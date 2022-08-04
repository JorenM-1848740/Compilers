#include "../absyn.hpp"
#include "../treeClasses/scope.hpp"
#include <algorithm>

void VarSpec_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "VarSpec" << "\n";
    if (identifierList != nullptr){
        identifierList->print(d+1);
    }
    if (type != nullptr){
        type->print(d+1);
    }
    if (expressionList != nullptr){
        expressionList->print(d+1);
    }
}

VarSpec_::VarSpec_(IdentifierList il, ExpressionList el){
    identifierList = il;
    expressionList = el;
}
VarSpec_::VarSpec_(IdentifierList il, Type t){
    identifierList = il;
    type = t;
}
VarSpec_::VarSpec_(IdentifierList il, Type t, ExpressionList el){
    identifierList = il;
    type = t;
    expressionList = el;
}

void VarSpec_::typeCheck(vector<Scope>& scopeStack, vector<string>& typeErrors){
    //If vars are not initialised
    if (expressionList == nullptr){
        string typeName = type->getType();

        vector<string> identifierNames;
        identifierList->getIdentifiers(identifierNames);

        for (int i = 0; i < identifierNames.size();++i){
            //Add to most recent scope
            try{
                std::pair<string, string> checkValue = scopeStack.at(scopeStack.size()-1)->getVariableValue(identifierNames[i]);
                typeErrors.push_back("Variable is already declared in this scope!");
            }
            catch(exception e){
                scopeStack.at(scopeStack.size()-1)->addVariableValue(identifierNames[i], typeName, "");              
            }          
        }
    }
    //If vars are initialised without a type
    else if (type == nullptr){
        vector<string> identifierNames;
        identifierList->getIdentifiers(identifierNames);

        vector<vector<string>> types;
        expressionList->getTypes(scopeStack, typeErrors, types);
        
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

        //If single valued expressions
        if(allSingleValued){
            //Check if expression list is same size as identifier list
            if (types.size() == identifierNames.size()){
                for (int i = 0; i < identifierNames.size();++i){
                    //Add to most recent scope
                    try{
                        std::pair<string, string> checkValue = scopeStack.at(scopeStack.size()-1)->getVariableValue(identifierNames[i]);
                        typeErrors.push_back("Variable is already declared in this scope!");
                    }
                    catch(exception e){
                        scopeStack.at(scopeStack.size()-1)->addVariableValue(identifierNames[i], types[i][0], "");
                    }             
                }
            }
            else{
                typeErrors.push_back("Expression list and identifier list are not the same size!");
            }
        }    
        //If one multi valued expression
        else if (singleMultiValued){
            //If multi valued expression has equal values to identifier count
            if (types[0].size() == identifierNames.size()){
                for (int i = 0; i < identifierNames.size();++i){
                    //Add to most recent scope
                    try{
                        std::pair<string, string> checkValue = scopeStack.at(scopeStack.size()-1)->getVariableValue(identifierNames[i]);
                        typeErrors.push_back("Variable is already declared in this scope!");
                    }
                    catch(exception e){
                        scopeStack.at(scopeStack.size()-1)->addVariableValue(identifierNames[i], types[0][i], "");
                    }  

                }
            }
            else{
                typeErrors.push_back("Multi valued expression not the same size as identifier list!");
            }
        }  
        else{
            typeErrors.push_back("Incorrect var assignment!");
        }
    }
    //If vars are initialised with a type
    else{
        string typeName = type->getType();

        vector<string> identifierNames;
        identifierList->getIdentifiers(identifierNames);

        vector<vector<string>> types;
        expressionList->getTypes(scopeStack, typeErrors, types);
        
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

        //If single valued expressions       
        if (allSingleValued){
            //Check if expression list is same size as identifier list
            if (types.size() == identifierNames.size()){
                //Check if types correspond with given type
                for (int i = 0; i < types.size();++i){
                    if (types[i][0] != typeName){
                        typeErrors.push_back("Expression type does not match given type!");
                    }
                }

                for (int i = 0; i < identifierNames.size();++i){
                    //Add to most recent scope
                    try{
                        std::pair<string, string> checkValue = scopeStack.at(scopeStack.size()-1)->getVariableValue(identifierNames[i]);
                        typeErrors.push_back("Variable is already declared in this scope!");
                    }
                    catch(exception e){
                        scopeStack.at(scopeStack.size()-1)->addVariableValue(identifierNames[i], typeName, "");
                    }
                }
            }
            else{
                typeErrors.push_back("Expression list and identifier list are not the same size!");
            } 
        }   
        //If one multi valued expression  
        else if(singleMultiValued){
            //If multi valued expression has equal values to identifier count
            if (types[0].size() == identifierNames.size()){

                //Check if types correspond with given type
                for (int i = 0; i < types[0].size();++i){
                    if (types[0][i] != typeName){
                        typeErrors.push_back("Expression type does not match given type!");
                    }
                }

                for (int i = 0; i < identifierNames.size();++i){
                    //Add to most recent scope
                    try{
                        std::pair<string, string> checkValue = scopeStack.at(scopeStack.size()-1)->getVariableValue(identifierNames[i]);
                        typeErrors.push_back("Variable is already declared in this scope!");
                    }
                    catch(exception e){
                        scopeStack.at(scopeStack.size()-1)->addVariableValue(identifierNames[i], typeName, "");
                    }  

                }
            }
            else{
                typeErrors.push_back("Multi valued expression not the same size as identifier list!");
            }
        }
        else{
            typeErrors.push_back("Incorrect var assignment!");
        }
    }
}