#include "../absyn.hpp"

void Block_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "Block" << "\n";
    statementList->print(d+1);
}

Block_::Block_(StatementList sl){
    statementList = sl;
}