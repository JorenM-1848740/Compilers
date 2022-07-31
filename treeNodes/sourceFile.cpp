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

void SourceFile_::saveSignatures(){
    scopeStack.push_back(new Scope_());
    topLevelDeclList->saveSignatures(scopeStack);
}

void SourceFile_::typeCheck(){
    topLevelDeclList->typeCheck(scopeStack, typeErrors);
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