#include "../absyn.hpp"

ForClause_::ForClause_(SimpleStmt ss1, SimpleStmt ss2){
    simpleStmt1 = ss1;
    simpleStmt2 = ss2;
}
ForClause_::ForClause_(SimpleStmt ss1, Expression e, SimpleStmt ss2){
    simpleStmt1 = ss1;
    expression = e;
    simpleStmt2 = ss2;
}

void ForClause_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "ForClause" << "\n";
    simpleStmt1->print(d+1);
    if(expression != nullptr){
        expression->print(d+1);
    }
    simpleStmt2->print(d+1);

}

bool ForClause_::hasCondition(){
    if (expression == nullptr){
        return false;
    }
    return true;
}

void ForClause_::typeCheck(vector<Scope>& scopeStack, vector<string>& typeErrors){
    simpleStmt1->typeCheck(scopeStack, typeErrors);
    simpleStmt2->typeCheck(scopeStack, typeErrors);
    if (expression != nullptr){
        vector<string> expressionType = expression->getType(scopeStack, typeErrors);

        if (expressionType.size() != 1){
            typeErrors.push_back("Expression in for clause must be single valued!");
            return;
        }

        if (expressionType[0] != "bool"){
            typeErrors.push_back("Expression in for clause must be boolean!");
            return;
        }
    }
}