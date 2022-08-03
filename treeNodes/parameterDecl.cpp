#include "../absyn.hpp"


ParameterDecl_::ParameterDecl_(IdentifierList il, Type t){
    identifierList = il;
    type = t;
}
ParameterDecl_::ParameterDecl_(Type t){
    type = t;
}

void ParameterDecl_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "ParameterDecl" << "\n";
    if (identifierList != nullptr){
        identifierList->print(d+1);
    }
    type->print(d+1);
}

vector<std::pair<string, string>> ParameterDecl_::getParameters(){
    vector<std::pair<string, string>> params;
    //If there are no identifiers
    if (identifierList == nullptr){
        params.push_back(std::pair<string, string>("", type->getType()));
    }
    //If there are identifiers
    else{
        vector<string> identifiers;
        identifierList->getIdentifiers(identifiers);
        for (int i = 0; i < identifiers.size();++i){
            params.push_back(std::pair<string, string>(identifiers[i], type->getType()));
        }
    }   
    return params;
}
