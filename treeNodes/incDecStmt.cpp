#include "../absyn.hpp"

IncDecStmt_::IncDecStmt_(Expression e, const char* id){
    expression = e;
    incDec = id;
}

void IncDecStmt_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "IncDecStmt" << "\n";
    expression->print(d+1);
    std::cout << std::string((d+1)*printWidth, ' ') << "incDecType: " << incDec << "\n";
}