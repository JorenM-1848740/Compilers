#include "../absyn.hpp"
#include "../treeClasses/scope.hpp"

void FunctionDecl_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "FunctionDecl" << "\n";
    std::cout << std::string((d+1)*printWidth, ' ') << "FunctionName: " << functionName << "\n";
    signature->print(d+1);
    if (block != nullptr){
        block->print(d+1);
    }
}

FunctionDecl_::FunctionDecl_(const char* fn, Signature s, Block b){
    signature = s;
    block = b;
    functionName = fn;
}

FunctionDecl_::FunctionDecl_(const char* fn, Signature s){
    signature = s;
    functionName = fn;
}

void FunctionDecl_::saveSignatures(vector<Scope>& scopeStack){

    scopeStack.at(0)->addFunctionSignature(functionName, signature);
}