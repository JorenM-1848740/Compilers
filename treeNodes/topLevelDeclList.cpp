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

void TopLevelDeclList_::saveFunction(vector<Scope>& scopeStack){
    //If there is at least one top level decleration
    if (topLevelDecl != nullptr){
        topLevelDeclList->saveFunction(scopeStack);
        topLevelDecl->saveFunction(scopeStack);
    }
}

void TopLevelDeclList_::typeCheck(vector<Scope>& scopeStack, vector<string>& typeErrors){
    //If there is at least one top level decleration
    if (topLevelDecl != nullptr){
        topLevelDeclList->typeCheck(scopeStack, typeErrors);
        topLevelDecl->typeCheck(scopeStack, typeErrors);
    }
}

void TopLevelDeclList_::interpret(vector<Scope>& scopeStack, vector<string>& typeErrors){
    if (topLevelDecl != nullptr){
        topLevelDeclList->interpret(scopeStack, typeErrors);
        topLevelDecl->interpret(scopeStack, typeErrors);
    }
}