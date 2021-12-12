#include "../absyn.hpp"

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