#include "../absyn.hpp"

void StatementList_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "StatementList" << "\n";
    if (statementList != nullptr){
        statementList->print(d+1);
    }
    if(statement != nullptr){
        statement->print(d+1);
    }
}

StatementList_::StatementList_(){

}
StatementList_::StatementList_(StatementList sl, Statement s){
    statementList = sl;
    statement = s;
}

bool StatementList_::terminates(){
    //If there are no statements
    if (statementList == nullptr){
        return false;
    }
    else{
        //Only check if last statement returns
        return (statement->terminates());
    }
}

void StatementList_::typeCheck(vector<Scope>& scopeStack, vector<string>& typeErrors){
    //If there are statements to typecheck
    if (statementList != nullptr){
        statementList->typeCheck(scopeStack, typeErrors);
        statement->typeCheck(scopeStack, typeErrors);
    }
}

void StatementList_::interpret(vector<Scope>& scopeStack, vector<string>& typeErrors, bool& halted){
    if (!halted){
        //If there are statements to interpret
        if (statementList != nullptr){
            statementList->interpret(scopeStack, typeErrors, halted);
            statement->interpret(scopeStack, typeErrors, halted);
        }
    }   
}