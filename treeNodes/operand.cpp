#include "../absyn.hpp"

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