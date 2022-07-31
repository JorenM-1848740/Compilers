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

void TopLevelDeclList_::saveSignatures(vector<Scope>& scopeStack){
    //If there is at least one top level decleration
    if (topLevelDecl != nullptr){
        topLevelDecl->saveSignatures(scopeStack);
        topLevelDeclList->saveSignatures(scopeStack);
    }
}

void TopLevelDeclList_::typeCheck(vector<Scope>& scopeStack, vector<string>& typeErrors){
    //If there is at least one top level decleration
    if (topLevelDecl != nullptr){
        topLevelDecl->typeCheck(scopeStack, typeErrors);
        topLevelDeclList->typeCheck(scopeStack, typeErrors);
    }
}