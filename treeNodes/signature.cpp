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

vector<std::pair<string, string>> Signature_::getParameters(){
    vector<std::pair<string, string>> parameterVector;
    parameters->getParameters(parameterVector);
    return parameterVector;
}

vector<std::pair<string, string>> Signature_::getResults(){
    vector<std::pair<string, string>> resultVector;
    if (result != nullptr){
        result->getParameters(resultVector);
    }
    return resultVector;

}