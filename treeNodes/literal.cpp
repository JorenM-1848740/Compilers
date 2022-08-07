#include "../absyn.hpp"

Literal_::Literal_(const char* l, const char* lt){
    literal = l;
    literalType = lt;
}

void Literal_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "Literal: "<< literal << "\n";
}

string Literal_::getLiteralType(){
    return literalType;
}

string Literal_::getLiteralValue(){
    return literal;
}
