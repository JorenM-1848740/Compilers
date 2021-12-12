#include "../absyn.hpp"

Assignment_::Assignment_(ExpressionList el1, const char* ao, ExpressionList el2){
    expressionList1 = el1;
    assignOp = ao;
    expressionList2 = el2;
}

void Assignment_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "Assignment" << "\n";
    expressionList1->print(d+1);
    std::cout << std::string((d+1)*printWidth, ' ') << "AssignOp: " << assignOp << "\n";
    expressionList2->print(d+1);

}
