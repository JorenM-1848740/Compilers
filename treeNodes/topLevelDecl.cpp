#include "../absyn.hpp"

TopLevelDecl_::TopLevelDecl_(VarDecl vd){
    varDecl = vd;
};

TopLevelDecl_::TopLevelDecl_(FunctionDecl fd){
    functionDecl = fd;
};

void TopLevelDecl_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "TopLevelDecl" << "\n";
    if (varDecl != nullptr){
        varDecl->print(d+1);
    };
    if(functionDecl != nullptr){
        functionDecl->print(d+1);
    };
}