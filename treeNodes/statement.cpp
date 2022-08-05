#include "../absyn.hpp"
#include "../treeClasses/scope.hpp"

Statement_::Statement_(VarDecl vd){
    varDecl = vd;
}
Statement_::Statement_(SimpleStmt ss){
    simpleStmt = ss;
}

Statement_::Statement_(ReturnStmt rs){
    returnStmt = rs;
}
Statement_::Statement_(Block b){
    block = b;
}
Statement_::Statement_(IfStmt is){
    ifStmt = is;
}
Statement_::Statement_(ForStmt fs){
    forStmt = fs;
}

void Statement_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "Statement" << "\n";
    if (varDecl != nullptr){
        varDecl->print(d+1);
    }
    if (simpleStmt != nullptr){
        simpleStmt->print(d+1);
    }
    if(returnStmt != nullptr){
        returnStmt->print(d+1);
    }
    if(block != nullptr){
        block->print(d+1);
    }
    if(ifStmt != nullptr){
        ifStmt->print(d+1);
    }
    if(forStmt != nullptr){
        forStmt->print(d+1);
    }
}

bool Statement_::terminates(){
    if (varDecl != nullptr){
        return false;
    }
    else if (simpleStmt != nullptr){
        return false;
    }
    else if (returnStmt != nullptr){
        return true;
    }
    else if (block != nullptr){
        return block->terminates();
    }
    else if (ifStmt != nullptr){
        return ifStmt->terminates();
    }
    //For statement case
    else{
        return forStmt->terminates();
    }
}

void Statement_::typeCheck(vector<Scope>& scopeStack, vector<string>& typeErrors){
    if (varDecl != nullptr){
        varDecl->typeCheck(scopeStack, typeErrors);
    }
    else if (simpleStmt != nullptr){
        simpleStmt->typeCheck(scopeStack, typeErrors);
    }
    else if (returnStmt != nullptr){
        returnStmt->typeCheck(scopeStack, typeErrors);
    }
    else if (block != nullptr){
        scopeStack.push_back(new Scope_());
        block->typeCheck(scopeStack, typeErrors);
        scopeStack.pop_back();
    }
    else if (ifStmt != nullptr){
        ifStmt->typeCheck(scopeStack, typeErrors);
    }
    //For statement case
    else{
        //TODO
        forStmt->typeCheck(scopeStack, typeErrors);
    }
}