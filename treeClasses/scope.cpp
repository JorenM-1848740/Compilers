#include "scope.hpp"
#include "../absyn.hpp"

std::pair<string, string> Scope_::getVariableValue(string identifier){
    return variableMap.at(identifier);
}

void Scope_::addVariableValue(string identifier, string type, string value){
    variableMap.insert(std::pair<string, std::pair<string, string>>(identifier, std::pair<string, string>(type, value)));
}

Signature Scope_::getFunctionSignature(string identifier){
    return functionMap.at(identifier).first;
}

Block Scope_::getFunctionBlock(string identifier){
    return functionMap.at(identifier).second;
}

void Scope_::addFunction(string identifier, Signature signature, Block block){
    functionMap.insert(std::pair<string, std::pair<Signature, Block>>(identifier, std::pair<Signature, Block>(signature, block)));
}

void Scope_::print(){
    cout << "Variables:" << "\n";
    for(const auto& elem : variableMap){
        std::cout << "\tName: " << elem.first << " | Type: " << elem.second.first << " | Value: " << elem.second.second << "\n";
    }
    cout << "Functions:" << "\n";
    for(const auto& elem : functionMap){
        std::cout << "\tName: " << elem.first << " | Signature: " << "\n";
    }
}

Scope_::Scope_(){

}