#include "../absyn.hpp"

ForStmt_::ForStmt_(Block b){
    block = b;
}
ForStmt_::ForStmt_(Expression e, Block b){
    expression = e;
    block = b;
}
ForStmt_::ForStmt_(ForClause fc, Block b){
    forClause = fc;
    block = b;
}

void ForStmt_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "ForStmt" << "\n";
    if (expression != nullptr){
        expression->print(d+1);
    }
    if(forClause != nullptr){
        forClause->print(d+1);
    }
    block->print(d+1);
}

bool ForStmt_::terminates(){
    //Based on go specs related to terminating statements
    if (expression == nullptr){
        if (forClause == nullptr){
            return true;
        }
        if (!forClause->hasCondition()){
            return true;
        }
    }
    return false;
}