#include "../absyn.hpp"

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