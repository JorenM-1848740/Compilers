#include "../absyn.hpp"

ParameterList_::ParameterList_(ParameterList pl, ParameterDecl pd){
    parameterList = pl;
    parameterDecl = pd;
}
ParameterList_::ParameterList_(ParameterDecl pd){
    parameterDecl = pd;
}

void ParameterList_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "ParameterList" << "\n";
    if (parameterList != nullptr){
        parameterList->print(d+1);
    }
    parameterDecl->print(d+1);
}