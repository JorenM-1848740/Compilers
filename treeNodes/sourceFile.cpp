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

void SourceFile_::printScopeStack(){
    for (int i = 0; i < scopeStack.size();++i){
        cout << "Scope " << i << "\n";
        scopeStack.at(i)->print();
        cout << "\n";
    }
}