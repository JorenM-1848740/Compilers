#include "../absyn.hpp"

ReturnStmt_::ReturnStmt_(){

}
ReturnStmt_::ReturnStmt_(ExpressionList el){
    expressionList = el;
}

void ReturnStmt_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "ReturnStmt" << "\n";
    if (expressionList != nullptr){
        expressionList->print(d+1);
    }

}

void ReturnStmt_::typeCheck(vector<Scope>& scopeStack, vector<string>& typeErrors){
    
}