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

vector<string> Expression_::getType(vector<Scope>& scopeStack, vector<string>& typeErrors){
    //If expression is a unary expression
    if (unaryExpr != nullptr){
        return unaryExpr->getType(scopeStack, typeErrors);
    }
    //If expression is a compound expression
    else{
        vector<string> type1 = expression1->getType(scopeStack, typeErrors);
        vector<string> type2 = expression2->getType(scopeStack, typeErrors);
        //If single valued expression
        if (type1.size() == 1 && type2.size() == 1){
            if (op == "gt" || op == "ge" || op == "lt" || op == "le"){
                if (!(type1[0] == "int" && type2[0] == "int")){
                    typeErrors.push_back("Binary operator not supported for this type!");
                }
            }
            if (op == "eq" || op == "ne"){
                if (type1[0] != type2[0]){
                    typeErrors.push_back("Can't compare different types!");
                }
            }
            if (op == "plus" || op == "min" || op == "mul" || op == "div"){
                if (!(type1[0] == "int" && type2[0] == "int")){
                    typeErrors.push_back("Arithmetic operators not defined for this type!");
                }
            }
            if (op == "or" || op == "and"){
                if (!(type1[0] == "bool" && type2[0] == "bool")){
                    typeErrors.push_back("Logical operator not defined for this type!");
                }
            }
            return type1;
        }
        else{
            typeErrors.push_back("Binary operators not defined for this expression!");
            return type1;
        }        
    }
}