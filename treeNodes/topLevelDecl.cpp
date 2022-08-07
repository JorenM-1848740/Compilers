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

void TopLevelDecl_::saveFunction(vector<Scope>& scopeStack){
    //If declaration is a function declaration
    if (functionDecl != nullptr){
        functionDecl->saveFunction(scopeStack);
    }

}

void TopLevelDecl_::typeCheck(vector<Scope>& scopeStack, vector<string>& typeErrors){
    //If declaration is a function declaration
    if (functionDecl != nullptr){
        functionDecl->typeCheck(scopeStack, typeErrors);
    }

    //If declaration is a variable declaration
    if (varDecl != nullptr){
        varDecl->typeCheck(scopeStack, typeErrors);
    }
}

void TopLevelDecl_::interpret(vector<Scope>& scopeStack, vector<string>& typeErrors){
    //TODO: If declaration is a function declaration 
    if (functionDecl != nullptr){
        
    }

    //If declaration is a variable declaration
    if (varDecl != nullptr){
        varDecl->interpret(scopeStack, typeErrors);
    }
}