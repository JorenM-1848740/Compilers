#ifndef SCOPE_HPP
#define SCOPE_HPP

#include <map>
#include <string>
#include <vector>
using namespace std;

struct Signature_;
typedef Signature_ *Signature;

struct Block_;
typedef Block_ *Block;

struct Scope_ {

    map<string, std::pair<string, string>> variableMap;
    map<string, std::pair<Signature, Block>> functionMap;
    vector<string> currentFunctionStack;
    vector<string> currentFunctionResultValues;

    std::pair<string, string> getVariableValue(string identifier);
    void addVariableValue(string identifier, string type, string value);
    void updateVariableValue(string identifier, string type, string value);

    Signature getFunctionSignature(string identifier);
    Block getFunctionBlock(string identifier);
    void addFunction(string identifier, Signature signature, Block block);

    string getCurrentFunctionName(){
        return currentFunctionStack[currentFunctionStack.size()-1];
    }

    void pushCurrentFunctionStack(string s){
        currentFunctionStack.push_back(s);
    }

    void popCurrentFunctionStack(){
        currentFunctionStack.pop_back();
    }

    vector<string> getCurrentFunctionResultValues(){
        return currentFunctionResultValues;
    }

    void setCurrentFunctionResultValues(vector<string> result){
        currentFunctionResultValues = result;
    }

    Scope_();

    void print();
};

#endif