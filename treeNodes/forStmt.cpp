#include "../absyn.hpp"
#include "../treeClasses/scope.hpp"

ForStmt_::ForStmt_(Block b){
    block = b;
}
ForStmt_::ForStmt_(Expression e, Block b){
    expression = e;
    block = b;
}
ForStmt_::ForStmt_(ForClause fc, Block b){
    forClause = fc;
    block = b;
}

void ForStmt_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "ForStmt" << "\n";
    if (expression != nullptr){
        expression->print(d+1);
    }
    if(forClause != nullptr){
        forClause->print(d+1);
    }
    block->print(d+1);
}

bool ForStmt_::terminates(){
    //Based on go specs related to terminating statements
    if (expression == nullptr){
        if (forClause == nullptr){
            return true;
        }
        if (!forClause->hasCondition()){
            return true;
        }
    }
    return false;
}

void ForStmt_::typeCheck(vector<Scope>& scopeStack, vector<string>& typeErrors){
    //Expression case
    if (expression != nullptr){
        vector<string> expressionType = expression->getType(scopeStack, typeErrors);

        if (expressionType.size() != 1){
            typeErrors.push_back("Expression in for statement must be single valued!");
            return;
        }

        if (expressionType[0] != "bool"){
            typeErrors.push_back("Expression in for statement must be boolean!");
            return;
        }

        scopeStack.push_back(new Scope_());
        block->typeCheck(scopeStack, typeErrors);
        scopeStack.pop_back();
    }
    //For clause case
    else if (forClause != nullptr){
        forClause->typeCheck(scopeStack, typeErrors);

        scopeStack.push_back(new Scope_());
        block->typeCheck(scopeStack, typeErrors);
        scopeStack.pop_back();
    }
    //No expression case
    else{
        scopeStack.push_back(new Scope_());
        block->typeCheck(scopeStack, typeErrors);
        scopeStack.pop_back();
    }
}

void ForStmt_::interpret(vector<Scope>& scopeStack, vector<string>& typeErrors, bool& halted){
    if (!halted){
        //Expression case
        if (expression != nullptr){
            while (expression->getValue(scopeStack, typeErrors)[0] == "true" && !halted){
                scopeStack.push_back(new Scope_());
                block->interpret(scopeStack, typeErrors, halted);
                scopeStack.pop_back();
            }

        }
        //For clause case
        //Logic is implemented in this class in stead of forClause class
        else if (forClause != nullptr){
            //Interpret initial statement once
            forClause->simpleStmt1->interpret(scopeStack, typeErrors);
            while (forClause->expression->getValue(scopeStack, typeErrors)[0] == "true" && !halted){
                scopeStack.push_back(new Scope_());
                block->interpret(scopeStack, typeErrors, halted);
                scopeStack.pop_back();
                //Interpret post statement each iteration
                forClause->simpleStmt2->interpret(scopeStack, typeErrors);
            }

        }
        //No expression case
        else{
            while(!halted){
                scopeStack.push_back(new Scope_());
                block->interpret(scopeStack, typeErrors, halted);
                scopeStack.pop_back();
            }
        }




    }
}