#include "../absyn.hpp"

UnaryExpr_::UnaryExpr_(PrimaryExpr pe){
    primaryExpr = pe;
}
UnaryExpr_::UnaryExpr_(Unary_op uo, UnaryExpr ue){
    unary_op = uo;
    unaryExpr = ue;
}

void UnaryExpr_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "UnaryExpr" << "\n";
    if(primaryExpr != nullptr){
        primaryExpr->print(d+1);
    }
    if(unary_op != nullptr){
        unary_op->print(d+1);
        unaryExpr->print(d+1);
    }

}

vector<string> UnaryExpr_::getType(vector<Scope>& scopeStack, vector<string>& typeErrors){
    //If there is a unary operator
    if (unary_op != nullptr){
        vector<string> type = unaryExpr->getType(scopeStack, typeErrors);
        string operatorName = unary_op->getOperatorName();
        //If single valued expression
        if (type.size() == 1){
            if ((operatorName == "plus" || operatorName == "min") && type[0] != "int"){
                typeErrors.push_back("Unary operator not specified for this type!");
            }
            else if (operatorName == "not" && type[0] != "bool"){
                typeErrors.push_back("Unary operator not specified for this type!");
            }
            return type;
        }
        else{
            typeErrors.push_back("Unary operators not defined for this expression!");
            return type;
        }
        
    }
    //If there is no unary operator
    else{
        return primaryExpr->getType(scopeStack, typeErrors);
    }
}

vector<string> UnaryExpr_::getValue(vector<Scope>& scopeStack, vector<string>& typeErrors){
    //If there is a unary operator
    if (unary_op != nullptr){  
        vector<string> value = unaryExpr->getValue(scopeStack, typeErrors);
        string operatorName = unary_op->getOperatorName();
        vector<string> returnValue;
        if (operatorName == "plus"){
            returnValue.push_back(value[0]);
        }
        if (operatorName == "min"){
            int newValue = -stoi(value[0]);
            returnValue.push_back(to_string(newValue));
        }
        if (operatorName == "not"){
            if (value[0] == "true"){
                returnValue.push_back("false");
            }
            else{
                returnValue.push_back("true");
            }
        }
        return returnValue;
    }    
    //If there is no unary operator
    else{
        return primaryExpr->getValue(scopeStack, typeErrors);
    }
}

string UnaryExpr_::getId(){
    if (primaryExpr != nullptr){
        return primaryExpr->getId();
    }
    else{
        return "";
    }
}