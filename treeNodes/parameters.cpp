#include "../absyn.hpp"

void Parameters_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "Parameters" << "\n";
    if (parameterList != nullptr){
        parameterList->print(d+1);
    }
}

Parameters_::Parameters_(ParameterList pl){
    parameterList = pl;
}
Parameters_::Parameters_(){

}