#include "../absyn.hpp"
#include "../treeClasses/scope.hpp"
#include <algorithm>

void VarSpec_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "VarSpec" << "\n";
    if (identifierList != nullptr){
        identifierList->print(d+1);
    }
    if (type != nullptr){
        type->print(d+1);
    }
    if (expressionList != nullptr){
        expressionList->print(d+1);
    }
}

VarSpec_::VarSpec_(IdentifierList il, ExpressionList el){
    identifierList = il;
    expressionList = el;
}
VarSpec_::VarSpec_(IdentifierList il, Type t){
    identifierList = il;
    type = t;
}
VarSpec_::VarSpec_(IdentifierList il, Type t, ExpressionList el){
    identifierList = il;
    type = t;
    expressionList = el;
}

void VarSpec_::typeCheck(vector<Scope>& scopeStack, vector<string>& typeErrors){
    //If vars are not initialised
    if (expressionList == nullptr){
        string typeName = type->getType();
        vector<string> identifierNames;
        identifierList->getIdentifiers(identifierNames);
        //Reverse identifier names (parser goes from right to left)
        std::reverse(identifierNames.begin(), identifierNames.end());
        for (int i = 0; i < identifierNames.size();++i){
            //Add to most recent scope
            scopeStack.at(scopeStack.size()-1)->addVariableValue(identifierNames[i], typeName, "");
        }
        typeErrors.push_back("Testing: everything works!");
        typeErrors.push_back("Or does it...");
    }
    //If vars are initialised without a type
    else if (type == nullptr){

    }
    //If vars are initialised with a type
    else{

    }
}