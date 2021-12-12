#include "../absyn.hpp"

void Signature_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "Signature" << "\n";
    parameters->print(d+1);
    if (result != nullptr){
        result->print(d+1);
    }
}

Signature_::Signature_(Parameters p, Result r){
    parameters = p;
    result = r;
}
Signature_::Signature_(Parameters p){
    parameters = p;
}