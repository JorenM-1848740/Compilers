#include "../absyn.hpp"

void FunctionDecl_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "FunctionDecl" << "\n";
    signature->print(d+1);
    if (block != nullptr){
        block->print(d+1);
    }
}

FunctionDecl_::FunctionDecl_(Signature s, Block b){
    signature = s;
    block = b;
}

FunctionDecl_::FunctionDecl_(Signature s){
    signature = s;
}