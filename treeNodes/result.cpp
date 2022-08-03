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

void Result_::getParameters(vector<std::pair<string, string>>& parameterVector){
    
    //If return is a single type
    if (type != nullptr){
        parameterVector.push_back(std::pair<string, string>("", type->getType()));
    }
    //all other cases
    else{       
        parameters->getParameters(parameterVector);
    }
}