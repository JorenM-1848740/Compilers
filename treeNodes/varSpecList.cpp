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