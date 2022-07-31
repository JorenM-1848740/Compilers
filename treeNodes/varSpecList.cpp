#include "../absyn.hpp"

void VarSpecList_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "VarSpecList" << "\n";
    if(varSpecList != nullptr){
        varSpecList->print(d+1);
    };
    if(varSpec != nullptr){
        varSpec->print(d+1);
    };

}

VarSpecList_::VarSpecList_(){

}
VarSpecList_::VarSpecList_(VarSpecList vsl, VarSpec vs){
    varSpecList = vsl;
    varSpec = vs;
}

void VarSpecList_::typeCheck(vector<Scope>& scopeStack, vector<string>& typeErrors){
    //If there are var specifications in the list
    if (varSpecList != nullptr){
        varSpecList->typeCheck(scopeStack, typeErrors);
        varSpec->typeCheck(scopeStack, typeErrors);
    }
}