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
                //TODO: Not only identifier as function name? Pointers?
                typeErrors.push_back("TODO: not only identifier as function name (pointers)!");
                return {"undefined"};
            }
        }
        else{
            //TODO: Function call inside of function call
            typeErrors.push_back("Multi valued expressions not allowed in function call!");
            return {"undefined"};
        }

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