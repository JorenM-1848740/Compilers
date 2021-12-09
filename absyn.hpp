#ifndef ABSYN_HPP
#define ABSYN_HPP

#include <vector>
#include <string>
#include <iostream>

using namespace std;

extern int printWidth;

struct SourceFile_;
struct PackageClause_;
struct TopLevelDecl_;
struct TopLevelDeclList_;

typedef SourceFile_ *SourceFile;
typedef PackageClause_ *PackageClause;
typedef TopLevelDecl_ *TopLevelDecl;
typedef TopLevelDeclList_ *TopLevelDeclList;

struct SourceFile_ {
    PackageClause packageClause = nullptr;
    TopLevelDeclList topLevelDeclList = nullptr;

    SourceFile_(PackageClause p, TopLevelDeclList t);

    void print(int d);
};

struct PackageClause_{
    string packageName;

    PackageClause_(char* p);
    void print(int d); 
};

struct TopLevelDecl_{
    void print(int d);
};

struct TopLevelDeclList_{
    TopLevelDeclList topLevelDeclList = nullptr;
    TopLevelDecl topLevelDecl = nullptr;

    TopLevelDeclList_(TopLevelDeclList tl, TopLevelDecl t);
    TopLevelDeclList_();

    void print(int d);
};

/*
struct VarDecl_ : public TopLevelDecl_{

};

struct FunctionDecl : public TopLevelDecl_{

};
*/



#endif