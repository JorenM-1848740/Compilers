#ifndef SCOPE_HPP
#define SCOPE_HPP

#include <map>
#include <string>
//#include "../absyn.hpp"
using namespace std;

struct Signature_;
typedef Signature_ *Signature;

struct Scope_;
typedef Scope_ *Scope;

struct Scope_ {

    map<string, string> variableMap;
    map<string, Signature> functionMap;

    string getVariableValue(string identifier);

    void addVariableValue(string identifier, string value);

    Signature getFunctionSignature(string identifier);

    void addFunctionSignature(string identifier, Signature signature);

    Scope_();

    void print();
};

#endif