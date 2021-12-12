#include "../absyn.hpp"


Result_::Result_(Parameters p){
    parameters = p;
}
Result_::Result_(Type t){
    type = t;
}

void Result_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "Result" << "\n";
    if (parameters != nullptr){
        parameters->print(d+1);
    }
    if(type != nullptr){
        type->print(d+1);
    }
}