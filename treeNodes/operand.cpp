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

string Operand_::getType(vector<Scope>& scopeStack, vector<string>& typeErrors){
    //If operand is a literal
    if (literal != nullptr){
        return literal->getLiteralType();
    }
    //If operand is an expression
    else if (expression != nullptr){
        return expression->getType(scopeStack, typeErrors);
    }
    //If operand is an identifier
    else{
        bool found = false;
        std::pair<string, string> typeValue;
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
            return typeValue.first;
        }
        else{
            typeErrors.push_back("Variable is not declared!");
            return "";
        }

    }
}