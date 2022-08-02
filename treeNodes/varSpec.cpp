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
    }
    //If vars are initialised without a type
    else if (type == nullptr){
        vector<string> identifierNames;
        identifierList->getIdentifiers(identifierNames);
        //Reverse identifier names (parser goes from right to left)
        std::reverse(identifierNames.begin(), identifierNames.end());

        vector<string> types;
        expressionList->getTypes(scopeStack, typeErrors, types);
        //Reverse expression names (parser goes from right to left)
        std::reverse(types.begin(), types.end());

        if (types.size() == identifierNames.size()){
            for (int i = 0; i < identifierNames.size();++i){
                //Add to most recent scope
                scopeStack.at(scopeStack.size()-1)->addVariableValue(identifierNames[i], types.at(i), "");
            }
        }
        else{
            typeErrors.push_back("Expression list and identifier list are not the same size!");
        }
    }
    //If vars are initialised with a type
    else{
        string typeName = type->getType();

        vector<string> identifierNames;
        identifierList->getIdentifiers(identifierNames);
        //Reverse identifier names (parser goes from right to left)
        std::reverse(identifierNames.begin(), identifierNames.end());

        vector<string> types;
        expressionList->getTypes(scopeStack, typeErrors, types);
        //Reverse expression names (parser goes from right to left)
        std::reverse(types.begin(), types.end());

        //Check if expression list is same size as identifier list
        if (types.size() == identifierNames.size()){
            //Check if types correspond with given type
            for (int i = 0; i < types.size();++i){
                if (types.at(i) != typeName){
                    typeErrors.push_back("Expression type does not match given type!");
                }
            }

            for (int i = 0; i < identifierNames.size();++i){
                //Add to most recent scope
                scopeStack.at(scopeStack.size()-1)->addVariableValue(identifierNames[i], typeName, "");
            }
        }
        else{
            typeErrors.push_back("Expression list and identifier list are not the same size!");
        }      
    }
}