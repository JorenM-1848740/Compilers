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

void ParameterList_::getParameters(vector<std::pair<string, string>>& parameterVector){
    vector<std::pair<string, string>> parameterSubVector;
    //If single parameter
    if (parameterList == nullptr){
        parameterSubVector = parameterDecl->getParameters();
        for (int i = 0; i < parameterSubVector.size();++i){
            parameterVector.push_back(parameterSubVector[i]);
        }       
    }
    else{
        parameterList->getParameters(parameterVector);
        parameterSubVector = parameterDecl->getParameters();
        for (int i = 0; i < parameterSubVector.size();++i){
            parameterVector.push_back(parameterSubVector[i]);
        }
    }
}