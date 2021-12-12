#include "../absyn.hpp"

void IdentifierList_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "IdentifierList" << "\n";
    std::cout << std::string((d+1)*printWidth, ' ') << "Identifier: " << identifier << "\n";
    if (identifierList != nullptr){
        identifierList->print(d+1);
    }

}

IdentifierList_::IdentifierList_(IdentifierList il, const char* i){
    identifierList = il;
    identifier = i;
}
IdentifierList_::IdentifierList_(const char* i){
    identifier = i;
}