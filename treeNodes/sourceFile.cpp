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

    try{
        scopeStack[0]->getFunctionSignature("main");
    }
    catch(exception e){
        typeErrors.push_back("There isn't a main function in this program!");
        return;
    }

    topLevelDeclList->typeCheck(scopeStack, typeErrors);
    scopeStack.pop_back();
}

void SourceFile_::interpret(){
    scopeStack.push_back(new Scope_());
    
    topLevelDeclList->saveFunction(scopeStack);
    topLevelDeclList->interpret(scopeStack, typeErrors);

    //Interpret main function
    string functionName = "main";
    Block functionBlock = scopeStack[0]->getFunctionBlock(functionName);
    bool halted = false;

    scopeStack.push_back(new Scope_());
    scopeStack[0]->pushCurrentFunctionStack(functionName);
    functionBlock->interpret(scopeStack, typeErrors, halted);
    scopeStack[0]->popCurrentFunctionStack();
    scopeStack.pop_back();

    scopeStack.pop_back();
}