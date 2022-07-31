#ifndef SCOPE_HPP
#define SCOPE_HPP

#include <map>
#include <string>
using namespace std;

struct Signature_;
typedef Signature_ *Signature;

struct Scope_ {

    map<string, std::pair<string, string>> variableMap;
    map<string, Signature> functionMap;

    std::pair<string, string> getVariableValue(string identifier);

    void addVariableValue(string identifier, string type, string value);

    Signature getFunctionSignature(string identifier);

    void addFunctionSignature(string identifier, Signature signature);

    Scope_();

    void print();
};

#endif