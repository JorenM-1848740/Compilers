#include "../absyn.hpp"

Literal_::Literal_(const char* l){
    literal = l;
}

void Literal_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "Literal: "<< literal << "\n";
}
