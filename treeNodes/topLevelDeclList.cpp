#include "../absyn.hpp"

TopLevelDeclList_::TopLevelDeclList_(TopLevelDeclList tl, TopLevelDecl t){
    topLevelDeclList = tl;
    topLevelDecl = t;
}
TopLevelDeclList_::TopLevelDeclList_(){

}

void TopLevelDeclList_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "TopLevelDeclList" << "\n";
    if(topLevelDeclList != nullptr){
        topLevelDeclList->print(d+1);
    };
    if(topLevelDecl != nullptr){
        topLevelDecl->print(d+1);
    };
}