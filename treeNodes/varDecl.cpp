#include "../absyn.hpp"

void VarDecl_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "VarDecl" << "\n";
    if (varSpec != nullptr){
        varSpec->print(d+1);
    };
    if (varSpecList != nullptr){
        varSpecList->print(d+1);
    }
}

VarDecl_::VarDecl_(VarSpec vs){
    varSpec = vs;
}
VarDecl_::VarDecl_(VarSpecList vsl){
    varSpecList = vsl;
}

void VarDecl_::typeCheck(vector<Scope>& scopeStack, vector<string>& typeErrors){
    //If there is only one var specification
    if (varSpec != nullptr){
        varSpec->typeCheck(scopeStack, typeErrors);
    }
    //If there are multiple var specifications
    if (varSpecList != nullptr){
        varSpecList->typeCheck(scopeStack, typeErrors);
    }
}