#include "../absyn.hpp"

SimpleStmt_::SimpleStmt_(){

}
SimpleStmt_::SimpleStmt_(Expression e){
    expression = e;
}
SimpleStmt_::SimpleStmt_(IncDecStmt ids){
    incDecStmt = ids;
}
SimpleStmt_::SimpleStmt_(Assignment a){
    assignment = a;
}

void SimpleStmt_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "SimpleStmt" << "\n";
    if (expression != nullptr){
        expression->print(d+1);
    }
    if(incDecStmt != nullptr){
        incDecStmt->print(d+1);
    }
    if(assignment != nullptr){
        assignment->print(d+1);
    }
}

void SimpleStmt_::typeCheck(vector<Scope>& scopeStack, vector<string>& typeErrors){
    //If simple statement is an expression
    if (expression != nullptr){
        vector<string> type = expression->getType(scopeStack, typeErrors);
    }
    if (incDecStmt != nullptr){
        incDecStmt->typeCheck(scopeStack, typeErrors);
    }
    if (assignment != nullptr){
        assignment->typeCheck(scopeStack, typeErrors);
    }
}

void SimpleStmt_::interpret(vector<Scope>& scopeStack, vector<string>& typeErrors){
    if (expression != nullptr){
        expression->getValue(scopeStack, typeErrors);
    }
    if (incDecStmt != nullptr){
        incDecStmt->interpret(scopeStack, typeErrors);
    }
    if (assignment != nullptr){
        assignment->interpret(scopeStack, typeErrors);
    }
}