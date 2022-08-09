#include "../absyn.hpp"
#include "../treeClasses/scope.hpp"
#include <set>
#include <algorithm>

void FunctionDecl_::print(int d){
    std::cout << std::string(d*printWidth, ' ') << "FunctionDecl" << "\n";
    std::cout << std::string((d+1)*printWidth, ' ') << "FunctionName: " << functionName << "\n";
    signature->print(d+1);
    block->print(d+1);
}

FunctionDecl_::FunctionDecl_(const char* fn, Signature s, Block b){
    signature = s;
    block = b;
    functionName = fn;
}

void FunctionDecl_::saveFunction(vector<Scope>& scopeStack){
    scopeStack.at(0)->addFunction(functionName, signature, block);
}

void FunctionDecl_::typeCheck(vector<Scope>& scopeStack, vector<string>& typeErrors){

    //Typecheck signature
    vector<std::pair<string, string>> parameters = signature->getParameters();
    vector<std::pair<string, string>> results = signature->getResults();

    /*
    cout << "FunctionDecl " << functionName << "\n";
    cout << "Parameters: " << "\n";
    for (int i = 0; i < parameters.size();++i){
        cout << parameters[i].first << " " << parameters[i].second << "\n";
    }
    cout << "Results: " << "\n";
    for (int i = 0; i < results.size();++i){
        cout << results[i].first << " " << results[i].second << "\n";
    }
    */

   //Check if it's the main function
    if (functionName == "main"){
        if (!(parameters.size() == 0 && results.size() == 0)){
            typeErrors.push_back("Main function can't have parameters or return values!");
        }
    }

   //Check if everything is named or unnamed
   vector<string> allIdentifiersParams;
   for (int i = 0; i < parameters.size();++i){
    allIdentifiersParams.push_back(parameters[i].first);
   }

   bool namedParams = true;
   bool unnamedParams = true;

   for (int i = 0; i < allIdentifiersParams.size();++i){
    if (allIdentifiersParams[i] != ""){
        unnamedParams = false;
    }
    if (allIdentifiersParams[i] == ""){
        namedParams = false;
    }
   }

   if (!(namedParams)){
    typeErrors.push_back("Parameters of function must all be named!");
   }

   vector<string> allIdentifiersResults;
   for (int i = 0; i < results.size();++i){
    allIdentifiersResults.push_back(results[i].first);
   }

   bool namedResults = true;
   bool unnamedResults = true;

   for (int i = 0; i < allIdentifiersResults.size();++i){
    if (allIdentifiersResults[i] != ""){
        unnamedResults = false;
    }
    if (allIdentifiersResults[i] == ""){
        namedResults = false;
    }
   }

   if (!(namedResults || unnamedResults)){
    typeErrors.push_back("Results of function are not all named or all unnamed!");
   }

   //Check uniqueness of identifiers
   //Combine identifiers of parameters and results
    allIdentifiersParams.insert( allIdentifiersParams.end(), allIdentifiersResults.begin(), allIdentifiersResults.end() );
    //Remove entries without an identifier
    allIdentifiersParams.erase(std::remove(allIdentifiersParams.begin(), allIdentifiersParams.end(), ""), allIdentifiersParams.end());
    std::set<string> s(allIdentifiersParams.begin(), allIdentifiersParams.end());
    if (s.size() != allIdentifiersParams.size()){
        typeErrors.push_back("There are duplicate identifiers in the function signature!");
        return;
    }

    //Add signature to new scope
    scopeStack.push_back(new Scope_());
    for (int i = 0; i < parameters.size();++i){
        //If named
        if (parameters[i].first != ""){
            scopeStack[scopeStack.size()-1]->addVariableValue(parameters[i].first, parameters[i].second, "");
        }      
    }
    for (int i = 0; i < results.size();++i){
        //If named
        if (results[i].first != ""){
            scopeStack[scopeStack.size()-1]->addVariableValue(results[i].first, results[i].second, "");
        }      
    }

    //Check if there is a return statement
    //Only check if there is a return value in the signature
    if (results.size() != 0){
        bool containsReturn = block->terminates();
        if (containsReturn == false){
            typeErrors.push_back("There are not enough return statements in the function block!");
        }
    }   

    scopeStack[0]->pushCurrentFunctionStack(functionName);
    block->typeCheck(scopeStack, typeErrors);
    scopeStack[0]->popCurrentFunctionStack();

    //Remove scope
    scopeStack.pop_back();

}