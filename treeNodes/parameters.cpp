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

void Parameters_::getParameters(vector<std::pair<string, string>>& parameterVector){
    //If parameter list is empty
    if (parameterList != nullptr){
        parameterList->getParameters(parameterVector);
    }
}