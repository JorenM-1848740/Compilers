#include "../absyn.hpp"

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