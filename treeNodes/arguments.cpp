#include "../absyn.hpp"

Arguments_::Arguments_(){

}
Arguments_::Arguments_(ExpressionList el){
    expressionList = el;
}

void Arguments_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "Arguments" << "\n";
    if (type != nullptr){
        type->print(d+1);
    }
    if (expressionList != nullptr){
        expressionList->print(d+1);
    }
}

vector<vector<string>> Arguments_::getArgumentTypes(vector<Scope>& scopeStack, vector<string>& typeErrors){
    vector<vector<string>> types;
    if (expressionList == nullptr){
        return types;
    }
    else{
        expressionList->getTypes(scopeStack, typeErrors, types);
        return types;
    }
}

vector<vector<string>> Arguments_::getArgumentValues(vector<Scope>& scopeStack, vector<string>& typeErrors){
    vector<vector<string>> values;
    if (expressionList == nullptr){
        return values;
    }
    else{
        expressionList->getValues(scopeStack, typeErrors, values);
        return values;
    }
}