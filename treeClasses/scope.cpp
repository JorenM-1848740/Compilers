#include "scope.hpp"
#include "../absyn.hpp"

string Scope_::getVariableValue(string identifier){
    return variableMap.at(identifier);
}

void Scope_::addVariableValue(string identifier, string value){
    variableMap.insert(std::pair<string, string>(identifier, value));
}

Signature Scope_::getFunctionSignature(string identifier){
    return functionMap.at(identifier);
}

void Scope_::addFunctionSignature(string identifier, Signature signature){
    functionMap.insert(std::pair<string, Signature>(identifier, signature));
}

void Scope_::print(){
    cout << "Variables:" << "\n";
    for(const auto& elem : variableMap){
        std::cout << "\tName: " << elem.first << " Value: " << elem.second;
    }
    cout << "Functions:" << "\n";
    for(const auto& elem : functionMap){
        std::cout << "\tName: " << elem.first << " Signature:";
    }
}

Scope_::Scope_(){

}