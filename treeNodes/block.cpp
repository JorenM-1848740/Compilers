#include "../absyn.hpp"

void Block_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "Block" << "\n";
    statementList->print(d+1);
}

Block_::Block_(StatementList sl){
    statementList = sl;
}

void Block_::typeCheck(vector<Scope>& scopeStack, vector<string>& typeErrors){
    statementList->typeCheck(scopeStack, typeErrors);
}

bool Block_::terminates(){
    return statementList->terminates();
}