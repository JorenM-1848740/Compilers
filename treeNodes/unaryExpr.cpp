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