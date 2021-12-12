#include "../absyn.hpp"

IfStmt_::IfStmt_(Expression e, Block b){
    expression = e;
    block1 = b;
}
IfStmt_::IfStmt_(Expression e, Block b, IfStmt is){
    expression = e;
    block1 = b;
    ifStmt = is;
}
IfStmt_::IfStmt_(Expression e, Block b1, Block b2){
    expression = e;
    block1 = b1;
    block2 = b2;
}
IfStmt_::IfStmt_(SimpleStmt ss, Expression e, Block b){
    simpleStmt = ss;
    expression = e;
    block1 = b;
}
IfStmt_::IfStmt_(SimpleStmt ss, Expression e, Block b, IfStmt is){
    simpleStmt = ss;
    expression = e;
    block1 = b;
    ifStmt = is;
}
IfStmt_::IfStmt_(SimpleStmt ss, Expression e, Block b1, Block b2){
    simpleStmt = ss;
    expression = e;
    block1 = b1;
    block2 = b2;
}

void IfStmt_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "IfStmt" << "\n";
    if (simpleStmt != nullptr){
        simpleStmt->print(d+1);
    }
    if (expression != nullptr){
        expression->print(d+1);
    }
    if (block1 != nullptr){
        block1->print(d+1);
    }
    if (ifStmt != nullptr){
        ifStmt->print(d+1);
    }
    if (block2 != nullptr){
        block2->print(d+1);
    }
}