#include "../absyn.hpp"
#include "../treeClasses/scope.hpp"

IncDecStmt_::IncDecStmt_(Expression e, const char* id){
    expression = e;
    incDec = id;
}

void IncDecStmt_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "IncDecStmt" << "\n";
    expression->print(d+1);
    std::cout << std::string((d+1)*printWidth, ' ') << "incDecType: " << incDec << "\n";
}

void IncDecStmt_::typeCheck(vector<Scope>& scopeStack, vector<string>& typeErrors){
    //Expression must be an identifier
    string id = expression->getId();
    vector<string> type = expression->getType(scopeStack, typeErrors);
    //If expression is not an identifier
    if (id == ""){
        typeErrors.push_back("Increment or decrement only works on identifiers!");
    }
    //If type is not an int
    if (type[0] != "int"){
        typeErrors.push_back("Increment or decrement statement not defined for this type!");
    }       
}

void IncDecStmt_::interpret(vector<Scope>& scopeStack, vector<string>& typeErrors){
    string id = expression->getId();
    //Search for identifier
    std::pair<string, string> typeValue;
    int scopeLevel = 0;
    for (int i = 0; i < scopeStack.size();++i){
        try{
            typeValue = scopeStack[scopeStack.size()-1-i]->getVariableValue(id);
            break;
        }
        catch (exception e){          
        }        
        scopeLevel++;   
    }

    if (incDec == "inc"){
        scopeStack[scopeStack.size()-1-scopeLevel]->updateVariableValue(id, typeValue.first, to_string(stoi(typeValue.second) + 1));
    }
    else{
        scopeStack[scopeStack.size()-1-scopeLevel]->updateVariableValue(id, typeValue.first, to_string(stoi(typeValue.second) - 1));
    }
}
