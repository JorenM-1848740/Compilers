#include "../absyn.hpp"

void ExpressionList_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "ExpressionList" << "\n";
    if (expressionList != nullptr){
        expressionList->print(d+1);
    }
    expression->print(d+1);
}

ExpressionList_::ExpressionList_(ExpressionList el, Expression e){
    expressionList = el;
    expression = e;
}
ExpressionList_::ExpressionList_(Expression e){
    expression = e;
}

void ExpressionList_::getTypes(vector<Scope>& scopeStack, vector<string>& typeErrors, vector<vector<string>>& types){
    if (expressionList == nullptr){
        types.push_back(expression->getType(scopeStack, typeErrors));
    }
    else{
        expressionList->getTypes(scopeStack, typeErrors, types);
        types.push_back(expression->getType(scopeStack, typeErrors));
    }
}