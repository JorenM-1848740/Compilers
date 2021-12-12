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
struct VarDecl_;
struct FunctionDecl_;
struct VarSpec_;
struct VarSpecList_;
struct ExpressionList_;
struct IdentifierList_;
struct Type_;
struct FunctionDecl_;
struct Signature_;
struct Block_;
struct Parameters_;
struct Result_;
struct ParameterList_;
struct ParameterDecl_;
struct StatementList_;

typedef SourceFile_ *SourceFile;
typedef PackageClause_ *PackageClause;
typedef TopLevelDecl_ *TopLevelDecl;
typedef TopLevelDeclList_ *TopLevelDeclList;
typedef VarDecl_ *VarDecl;
typedef FunctionDecl_ *FunctionDecl;
typedef VarSpec_ *VarSpec;
typedef VarSpecList_ *VarSpecList;
typedef ExpressionList_ *ExpressionList;
typedef IdentifierList_ *IdentifierList;
typedef Type_ *Type;
typedef Signature_ *Signature;
typedef Block_ *Block;
typedef Parameters_ *Parameters;
typedef Result_ *Result;
typedef ParameterList_ *ParameterList;
typedef ParameterDecl_ *ParameterDecl;
typedef StatementList_ *StatementList;

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

struct TopLevelDeclList_{
    TopLevelDeclList topLevelDeclList = nullptr;
    TopLevelDecl topLevelDecl = nullptr;

    TopLevelDeclList_(TopLevelDeclList tl, TopLevelDecl t);
    TopLevelDeclList_();

    void print(int d);
};

struct TopLevelDecl_{
    VarDecl varDecl = nullptr;
    FunctionDecl functionDecl = nullptr;

    TopLevelDecl_(VarDecl vd);
    TopLevelDecl_(FunctionDecl fd);

    void print(int d);
};


struct VarDecl_{
    VarSpec varSpec = nullptr;
    VarSpecList varSpecList = nullptr;

    VarDecl_(VarSpec vs);
    VarDecl_(VarSpecList vsl);

    void print(int d);
};

struct VarSpec_{
    IdentifierList identifierList = nullptr;
    Type type = nullptr;
    ExpressionList expressionList = nullptr;

    VarSpec_(IdentifierList il, ExpressionList el);
    VarSpec_(IdentifierList il, Type t);
    VarSpec_(IdentifierList il, Type t, ExpressionList el);

    void print(int d);
};

struct VarSpecList_{

    VarSpecList varSpecList = nullptr;
    VarSpec varSpec = nullptr;
    
    VarSpecList_();
    VarSpecList_(VarSpecList vsl, VarSpec vs);

    void print(int d);
};

struct ExpressionList_{
    void print(int d);
};

struct IdentifierList_{

    IdentifierList identifierList;
    string identifier;

    IdentifierList_(IdentifierList il, string i);
    IdentifierList_(string i);

    void print(int d);
};

struct Type_{
    string type;

    Type_(const char* t);

    void print(int d);
};

struct FunctionDecl_{
    Signature signature = nullptr;
    Block block = nullptr;

    FunctionDecl_(Signature s, Block b);
    FunctionDecl_(Signature s);

    void print(int d);
};

struct Signature_{

    Parameters parameters = nullptr;
    Result result = nullptr;

    Signature_(Parameters p, Result r);
    Signature_(Parameters p);

    void print(int d);
};

struct Block_{

    StatementList statementList = nullptr;

    Block_(StatementList sl);

    void print(int d);
};

struct Parameters_{

    ParameterList parameterList = nullptr;

    Parameters_(ParameterList pl);
    Parameters_();

    void print(int d);


};

struct Result_{

    Parameters parameters = nullptr;
    Type type = nullptr;

    Result_(Parameters p);
    Result_(Type t);

    void print(int d);

};

struct ParameterList_{

    ParameterList parameterList = nullptr;
    ParameterDecl parameterDecl = nullptr;

    ParameterList_(ParameterList pl, ParameterDecl pd);
    ParameterList_(ParameterDecl pd);

    void print(int d);

};

struct ParameterDecl_{

    IdentifierList identifierList = nullptr;
    Type type = nullptr;

    ParameterDecl_(IdentifierList il, Type t);
    ParameterDecl_(Type t);

    void print(int d);
};

struct StatementList_{
    void print(int d);
};




#endif