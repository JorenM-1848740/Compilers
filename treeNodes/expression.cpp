#include "../absyn.hpp"

void Expression_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "Expression" << "\n";
    if (unaryExpr != nullptr){
        unaryExpr->print(d+1);
    }
    if (expression1 != nullptr){
        expression1->print(d+1);
        std::cout << std::string((d+1)*printWidth, ' ') << "Operator: " << op << "\n";
        expression2->print(d+1);
    }

}

Expression_::Expression_(UnaryExpr ue){
    unaryExpr = ue;
}
Expression_::Expression_(Expression e1, const char* o, Expression e2){
    expression1 = e1;
    op = o;
    expression2 = e2;
}

string Expression_::getType(vector<Scope>& scopeStack, vector<string>& typeErrors){
    //If expression is a unary expression
    if (unaryExpr != nullptr){
        return unaryExpr->getType(scopeStack, typeErrors);
    }
    //If expression is a compound expression
    else{
        string type1 = expression1->getType(scopeStack, typeErrors);
        string type2 = expression2->getType(scopeStack, typeErrors);
    }
    return "int";
}