#include "../absyn.hpp"

UnaryExpr_::UnaryExpr_(PrimaryExpr pe){
    primaryExpr = pe;
}
UnaryExpr_::UnaryExpr_(Unary_op uo, UnaryExpr ue){
    unary_op = uo;
    unaryExpr = ue;
}

void UnaryExpr_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "UnaryExpr" << "\n";
    if(primaryExpr != nullptr){
        primaryExpr->print(d+1);
    }
    if(unary_op != nullptr){
        unary_op->print(d+1);
        unaryExpr->print(d+1);
    }

}

string UnaryExpr_::getType(vector<Scope>& scopeStack, vector<string>& typeErrors){
    //If there is a unary operator
    if (unary_op != nullptr){
        string type = unaryExpr->getType(scopeStack, typeErrors);
        string operatorName = unary_op->getOperatorName();
        if ((operatorName == "plus" || operatorName == "min") && type != "int"){
            typeErrors.push_back("Unary operator not specified for this type!");
        }
        else if (operatorName == "not" && type != "bool"){
            typeErrors.push_back("Unary operator not specified for this type!");
        }
        return type;
    }
    //If there is no unary operator
    else{
        return primaryExpr->getType(scopeStack, typeErrors);
    }
}