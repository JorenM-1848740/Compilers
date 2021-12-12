#include "../absyn.hpp"

Unary_op_::Unary_op_(const char* uo){
    unary_op = uo;
}

void Unary_op_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "Unary_op: " << unary_op << "\n";
}