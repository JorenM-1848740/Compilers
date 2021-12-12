#include "../absyn.hpp"

void Type_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "Type: " << type << "\n";
}

Type_::Type_(const char* t){
    type = t;
}