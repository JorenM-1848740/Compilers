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