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