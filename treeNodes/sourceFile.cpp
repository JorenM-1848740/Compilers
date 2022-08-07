#include "../absyn.hpp"
#include "../treeClasses/scope.hpp"

SourceFile_::SourceFile_(PackageClause p, TopLevelDeclList t){
    packageClause = p;
    topLevelDeclList = t;
}

void SourceFile_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "SourceFile" << "\n";
    packageClause->print(d+1);
    topLevelDeclList->print(d+1);
}

void SourceFile_::printScopeStack(){
    cout << "\n\n\n";
    for (int i = 0; i < scopeStack.size();++i){
        cout << "Scope " << i << "\n";
        scopeStack.at(i)->print();
        cout << "\n";
    }
}

void SourceFile_::printTypeErrors(){
    for (int i = 0; i < typeErrors.size();++i){
        cout << "Error " << i+1 << ": " << typeErrors[i] << "\n";
    }
}


void SourceFile_::typeCheck(){

    packageClause->typeCheck(typeErrors);
    scopeStack.push_back(new Scope_());
    topLevelDeclList->saveFunction(scopeStack);
    topLevelDeclList->typeCheck(scopeStack, typeErrors);
    scopeStack.pop_back();
}

void SourceFile_::interpret(){
    scopeStack.push_back(new Scope_());
    topLevelDeclList->saveFunction(scopeStack);
    topLevelDeclList->interpret(scopeStack, typeErrors);
    scopeStack[0]->print();
    scopeStack.pop_back();
}