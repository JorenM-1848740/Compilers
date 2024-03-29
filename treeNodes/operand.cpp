#include "../absyn.hpp"
#include "../treeClasses/scope.hpp"

Operand_::Operand_(Literal l){
    literal = l;
}
Operand_::Operand_(const char* i){
    id = i;
}
Operand_::Operand_(Expression e){
    expression = e;
}

void Operand_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "Operand"<< "\n";
    if (literal != nullptr){
        literal->print(d+1);
    }
    if(id != ""){
        std::cout << std::string((d+1)*printWidth, ' ') << "Identifier: "<< id << "\n";
    }
    if(expression != nullptr){
        expression->print(d+1);
    }
}

vector<string> Operand_::getType(vector<Scope>& scopeStack, vector<string>& typeErrors){
    vector<string> types;
    //If operand is a literal
    if (literal != nullptr){
        types.push_back(literal->getLiteralType());
        return types;
    }
    //If operand is an expression
    else if (expression != nullptr){
        return expression->getType(scopeStack, typeErrors);
    }
    //If operand is an identifier
    else{
        bool found = false;
        std::pair<string, string> typeValue;
        //Find variable in scope stack, starting from most recent scope
        for (int i = 0; i < scopeStack.size();++i){
            try{
                typeValue = scopeStack[scopeStack.size()-1-i]->getVariableValue(id);
                found = true;
                break;
            }
            catch (exception e){          
            }           
        }

        if (found){
            types.push_back(typeValue.first);
            return types;           
        }
        else{
            typeErrors.push_back("Variable is not declared!");
            return {"undefined"};
        }

    }
}

vector<string> Operand_::getValue(vector<Scope>& scopeStack, vector<string>& typeErrors){
    vector<string> returnValue;
    //If operand is a literal
    if (literal != nullptr){
        returnValue.push_back(literal->getLiteralValue());
        return returnValue;
    }
    //If operand is an expression
    else if (expression != nullptr){
        return expression->getValue(scopeStack, typeErrors);
    }
    //If operand is a variable
    else{
        std::pair<string, string> typeValue;
        //Find variable in scope stack, starting from most recent scope
        for (int i = 0; i < scopeStack.size();++i){
            try{
                typeValue = scopeStack[scopeStack.size()-1-i]->getVariableValue(id);
                break;
            }
            catch (exception e){          
            }           
        }
        returnValue.push_back(typeValue.second);  
        return returnValue;     
    }
}

string Operand_::getId(){
    if (expression != nullptr){
        return expression->getId();
    }
    else{
        return id;
    }
}