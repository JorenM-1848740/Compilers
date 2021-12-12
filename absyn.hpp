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
struct Signature_;
struct Block_;
struct Parameters_;
struct Result_;
struct ParameterList_;
struct ParameterDecl_;
struct StatementList_;
struct Statement_;
struct SimpleStmt_;
struct ReturnStmt_;
struct IfStmt_;
struct ForStmt_;
struct IncDecStmt_;
struct Assignment_;
struct ForClause_;
struct Expression_;
struct Operand_;
struct Literal_;
struct PrimaryExpr_;
struct Arguments_;
struct UnaryExpr_;
struct Unary_op_;



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
typedef Statement_ *Statement;
typedef SimpleStmt_ *SimpleStmt;
typedef ReturnStmt_ *ReturnStmt;
typedef IfStmt_ *IfStmt;
typedef ForStmt_ *ForStmt;
typedef IncDecStmt_ *IncDecStmt;
typedef Assignment_ *Assignment;
typedef ForClause_ *ForClause;
typedef Expression_ *Expression;
typedef Operand_ *Operand;
typedef Literal_ *Literal;
typedef PrimaryExpr_ *PrimaryExpr;
typedef Arguments_ *Arguments;
typedef UnaryExpr_ *UnaryExpr;
typedef Unary_op_ *Unary_op;

struct SourceFile_ {
    PackageClause packageClause = nullptr;
    TopLevelDeclList topLevelDeclList = nullptr;

    SourceFile_(PackageClause p, TopLevelDeclList t);

    void print(int d);
};

struct PackageClause_{
    string packageName = "";

    PackageClause_(const char* p);
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
    ExpressionList expressionList = nullptr;
    Expression expression = nullptr;

    ExpressionList_(ExpressionList el, Expression e);
    ExpressionList_(Expression e);

    void print(int d);
};

struct IdentifierList_{

    IdentifierList identifierList = nullptr;
    string identifier = nullptr;

    IdentifierList_(IdentifierList il, string i);
    IdentifierList_(string i);

    void print(int d);
};

struct Type_{
    string type = "";

    Type_(const char* t);

    void print(int d);
};

struct FunctionDecl_{
    string functionName = "";
    Signature signature = nullptr;
    Block block = nullptr;

    FunctionDecl_(const char* fn, Signature s, Block b);
    FunctionDecl_(const char* fn, Signature s);

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
    StatementList statementList = nullptr;
    Statement statement = nullptr;

    StatementList_();
    StatementList_(StatementList sl, Statement s);

    void print(int d);
};

struct Statement_{

    VarDecl varDecl = nullptr;
    SimpleStmt simpleStmt = nullptr;
    ReturnStmt returnStmt = nullptr;
    Block block = nullptr;
    IfStmt ifStmt = nullptr;
    ForStmt forStmt = nullptr;

    Statement_(VarDecl vd);
    Statement_(SimpleStmt ss);
    Statement_(ReturnStmt rs);
    Statement_(Block b);
    Statement_(IfStmt is);
    Statement_(ForStmt fs);

    void print(int d);
};

struct SimpleStmt_{
    Expression expression = nullptr;
    IncDecStmt incDecStmt = nullptr;
    Assignment assignment = nullptr;

    SimpleStmt_();
    SimpleStmt_(Expression e);
    SimpleStmt_(IncDecStmt ids);
    SimpleStmt_(Assignment a);

    void print(int d);
};

struct ReturnStmt_{
    ExpressionList expressionList = nullptr;

    ReturnStmt_();
    ReturnStmt_(ExpressionList el);

    void print(int d);
};

struct IfStmt_{
    SimpleStmt simpleStmt = nullptr;
    Expression expression = nullptr;
    Block block1 = nullptr;
    IfStmt ifStmt = nullptr;
    Block block2 = nullptr;

    IfStmt_(Expression e, Block b);
    IfStmt_(Expression e, Block b, IfStmt is);
    IfStmt_(Expression e, Block b1, Block b2);
    IfStmt_(SimpleStmt ss, Expression e, Block b);
    IfStmt_(SimpleStmt ss, Expression e, Block b, IfStmt is);
    IfStmt_(SimpleStmt ss, Expression e, Block b1, Block b2);

    void print(int d);


};

struct ForStmt_{
    Block block = nullptr;
    Expression expression = nullptr;
    ForClause forClause = nullptr;

    ForStmt_(Block b);
    ForStmt_(Expression e, Block b);
    ForStmt_(ForClause fc, Block b);

    void print(int d);
};

struct IncDecStmt_{
    Expression expression = nullptr;
    string incDec = "";

    IncDecStmt_(Expression e, const char* id);

    void print(int d);
};

struct Assignment_{
    ExpressionList expressionList1 = nullptr;
    string assignOp = "";
    ExpressionList expressionList2 = nullptr;

    Assignment_(ExpressionList el1, const char* ao, ExpressionList el2);

    void print(int d);
};

struct ForClause_{
    SimpleStmt simpleStmt1 = nullptr;
    Expression expression = nullptr;
    SimpleStmt simpleStmt2 = nullptr;

    ForClause_(SimpleStmt ss1, SimpleStmt ss2);
    ForClause_(SimpleStmt ss1, Expression e, SimpleStmt ss2);

    void print(int d);
};

struct Expression_{
    UnaryExpr unaryExpr = nullptr;
    Expression expression1 = nullptr;
    Expression expression2 = nullptr;
    string op = "";

    Expression_(UnaryExpr ue);
    Expression_(Expression e1, const char* o, Expression e2);

    void print(int d);
};

struct Operand_{
    Literal literal = nullptr;
    string id = "";
    Expression expression = nullptr;

    Operand_(Literal l);
    Operand_(const char* i);
    Operand_(Expression e);

    void print(int d);
};

struct Literal_{
    string literal = "";

    Literal_(const char* l);

    void print(int d);
};

struct PrimaryExpr_{
    Operand operand = nullptr;
    PrimaryExpr primaryExpr = nullptr;
    Arguments arguments = nullptr;

    PrimaryExpr_(Operand o);
    PrimaryExpr_(PrimaryExpr pe, Arguments a);

    void print(int d);
};

struct Arguments_{
    ExpressionList expressionList = nullptr;
    Type type = nullptr;

    Arguments_();
    Arguments_(ExpressionList el);
    Arguments_(Type t);
    Arguments_(Type t, ExpressionList el);

    void print(int d);
};

struct UnaryExpr_{
    PrimaryExpr primaryExpr = nullptr;
    Unary_op unary_op = nullptr;
    UnaryExpr unaryExpr = nullptr;

    UnaryExpr_(PrimaryExpr pe);
    UnaryExpr_(Unary_op uo, UnaryExpr ue);

    void print(int d);
};

struct Unary_op_{
    string unary_op = "";

    Unary_op_(const char* uo);

    void print(int d);
};





#endif