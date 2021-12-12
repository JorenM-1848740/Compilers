#include "../absyn.hpp"


ParameterDecl_::ParameterDecl_(IdentifierList il, Type t){
    identifierList = il;
    type = t;
}
ParameterDecl_::ParameterDecl_(Type t){
    type = t;
}

void ParameterDecl_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "ParameterDecl" << "\n";
    if (identifierList != nullptr){
        identifierList->print(d+1);
    }
    type->print(d+1);
}
