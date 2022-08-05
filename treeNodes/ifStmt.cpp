#include "../absyn.hpp"
#include "../treeClasses/scope.hpp"

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

bool IfStmt_::terminates(){
    //Based on go specs related to terminating statements
    //If else case
    if (block1 != nullptr && block2 != nullptr){
        return (block1->terminates() && block2->terminates());
    }
    //if else if case
    else if (ifStmt != nullptr){
        return (block1->terminates() && ifStmt->terminates());
    }
    //if case
    else{
        return false;
    }
}

void IfStmt_::typeCheck(vector<Scope>& scopeStack, vector<string>& typeErrors){

    vector<string> expressionType = expression->getType(scopeStack, typeErrors);

    if (expressionType.size() != 1){
        typeErrors.push_back("Expression in if statement must be single valued!");
        return;
    }

    if (expressionType[0] != "bool"){
        typeErrors.push_back("Expression in if statement must be boolean!");
        return;
    }

    //If else case
    if (block1 != nullptr && block2 != nullptr){
        
        scopeStack.push_back(new Scope_());
        block1->typeCheck(scopeStack, typeErrors);
        scopeStack.pop_back();

        scopeStack.push_back(new Scope_());
        block2->typeCheck(scopeStack, typeErrors);
        scopeStack.pop_back();
    }
    //If else if case
    else if (ifStmt != nullptr){

        scopeStack.push_back(new Scope_());
        block1->typeCheck(scopeStack, typeErrors);
        scopeStack.pop_back();

        ifStmt->typeCheck(scopeStack, typeErrors);
    }
    //If case
    else{
        
        scopeStack.push_back(new Scope_());
        block1->typeCheck(scopeStack, typeErrors);
        scopeStack.pop_back();
    }
}