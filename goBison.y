%{
#include <stdio.h>
#include "absyn.hpp"


void yyerror(const char* str);
extern int yylex();

SourceFile thesyntree;

%}
%code requires {
    #include "absyn.hpp"
}

%union {
  SourceFile sourceFile;
  PackageClause packageClause;
  TopLevelDecl topLevelDecl;
  TopLevelDeclList topLevelDeclList;
  VarDecl varDecl;
  FunctionDecl functionDecl;
  VarSpec varSpec;
  VarSpecList varSpecList;
  IdentifierList identifierList;
  ExpressionList expressionList;
  Type type;
  Signature signature;
  Block block;
  Parameters parameters;
  Result result;
  ParameterList parameterList;
  ParameterDecl parameterDecl;
  StatementList statementList;
  char* id;
}

// vul aan met tokendeclaraties
%token
  SEMICOLON COMMA
  INTLITERAL BOOLLITERAL
  INT BOOL
  PACKAGE RETURN VAR IF FOR FUNC ELSE
  LPAREN RPAREN LBRACE RBRACE
  PLUS MIN MUL DIV PLUSASSIGN MINASSIGN MULASSIGN DIVASSIGN ASSIGN UMINUS
  AND OR NOT INC DEC GT GE LT LE EQ NE

%token <id> IDENTIFIER
// vul aan met voorrangdeclaraties

%left OR
%left AND
%left EQ NE GT GE LT LE
%left PLUS MIN
%left MUL DIV

%right UMINUS

%defines
%define parse.error verbose

%type <sourceFile> SourceFile
%type <packageClause> PackageClause
%type <topLevelDecl> TopLevelDecl
%type <topLevelDeclList> TopLevelDeclList
%type <varDecl> VarDecl
%type <functionDecl> FunctionDecl
%type <varSpec> VarSpec
%type <varSpecList> VarSpecList
%type <identifierList> IdentifierList
%type <expressionList> ExpressionList
%type <type> Type
%type <signature> Signature
%type <block> Block
%type <parameters> Parameters
%type <result> Result
%type <parameterList> ParameterList
%type <parameterDecl> ParameterDecl
%type <statementList> StatementList

%%

SourceFile : PackageClause SEMICOLON TopLevelDeclList {puts("PackageClause SEMICOLON TopLevelDeclList"); 
$$ = new SourceFile_($1, $3); thesyntree = $$;}
  ;

TopLevelDeclList : {$$ = new TopLevelDeclList_();}
  | TopLevelDeclList TopLevelDecl SEMICOLON {puts("TopLevelDeclList TopLevelDecl SEMICOLON");
$$ = new TopLevelDeclList_($1, $2);}
  ;

// vul aan met producties
Block : LBRACE StatementList RBRACE {puts("LBRACE StatementList RBRACE");
$$ = new Block_($2);}
  ;

StatementList : 
  | StatementList Statement SEMICOLON {puts("StatementList Statement SEMICOLON");}
  ;

IdentifierList : IDENTIFIER {puts("IDENTIFIER");
$$ = new IdentifierList_($1);}
  | IdentifierList COMMA IDENTIFIER {puts("COMMA IDENTIFIER");
$$ = new IdentifierList_($1, $3);}
  ;

Type : INT {puts("INT");
$$ = new Type_("int");}
  | BOOL {puts("BOOL");
$$ = new Type_("bool");}
  //| LPAREN Type RPAREN {puts("LPAREN Type RPAREN");}
  ;

ExpressionList : Expression {puts("Expression");}
  | ExpressionList COMMA Expression {puts("COMMA Expression");}
  ;

/*
Declaration : VarDecl {puts("VarDecl");}
  ;
*/

TopLevelDecl : VarDecl {puts("VarDecl");
$$ = new TopLevelDecl_($1);}
  | FunctionDecl {puts("FunctionDecl");
$$ = new TopLevelDecl_($1);}
  ;

//VARIABLE DECLARATION

VarDecl : VAR VarSpec {puts("VAR VarSpec");
$$ = new VarDecl_($2);}
  | VAR LPAREN VarSpecList RPAREN {puts("VAR LPAREN VarSpecList RPAREN");
$$ = new VarDecl_($3);}
  ;

VarSpecList : {$$ = new VarSpecList_();}
  | VarSpecList VarSpec SEMICOLON {puts("VarSpecList SEMICOLON VarSpec");
$$ = new VarSpecList_($1, $2);}
  ;

VarSpec : IdentifierList ASSIGN ExpressionList {puts("IdentifierList ASSIGN ExpressionList");
$$ = new VarSpec_($1, $3);}
  | IdentifierList Type {puts("IdentifierList Type");
$$ = new VarSpec_($1, $2);}
  | IdentifierList Type ASSIGN ExpressionList {puts("IdentifierList Type ASSIGN ExpressionList");
$$ = new VarSpec_($1, $2, $4);}
  ;

//////////////////////////////////////////////



//FUNCTION DECLARATION

FunctionDecl : FUNC IDENTIFIER Signature {puts("FUNC FunctionName Signature");
$$ = new FunctionDecl_($3);}
  | FUNC IDENTIFIER Signature Block {puts("FUNC FunctionName Signature FunctionBody");
$$ = new FunctionDecl_($3, $4);}
  ;

Signature : Parameters {puts("Parameters");
$$ = new Signature_($1);}
  | Parameters Result {puts("Parameters Result");
$$ = new Signature_($1, $2);}
  ;

Result : Parameters {puts("Parameters");
$$ = new Result_($1);}
  | Type {puts("Type");
$$ = new Result_($1);}
  ;

Parameters : LPAREN RPAREN {puts("LPAREN RPAREN");
$$ = new Parameters_();}
  | LPAREN ParameterList RPAREN {puts("LPAREN ParameterList RPAREN");
$$ = new Parameters_($2);}
  | LPAREN ParameterList COMMA RPAREN {puts("LPAREN ParameterList COMMA RPAREN");
$$ = new Parameters_($2);}
  ;
ParameterList : ParameterDecl {puts("ParameterDecl");
$$ = new ParameterList_($1);}
  | ParameterList COMMA ParameterDecl {puts("ParameterList COMMA ParameterDecl");
$$ = new ParameterList_($1, $3);}
  ;

ParameterDecl : IdentifierList Type {puts("IdentifierList Type");
$$ = new ParameterDecl_($1, $2);}
  | Type {puts("Type");
$$ = new ParameterDecl_($1);}
  ;

//////////////////////////////////////////////

//EXPRESSIONS

Operand : Literal {puts("Literal");}
  | OperandName {puts("OperandName");}
  | LPAREN Expression RPAREN {puts("LPAREN Expression RPAREN");}
  ;

Literal : BasicLit {puts("BasicLit");}
  ;

BasicLit : INTLITERAL {puts("INTLITERAL");}
  | BOOLLITERAL {puts("BOOLLITERAL");}
  ;

OperandName : IDENTIFIER {puts("IDENTIFIER");}
  ;

PrimaryExpr : Operand {puts("Operand");}
  | PrimaryExpr Arguments {puts("PrimaryExpr Arguments");}
  ;

Arguments : LPAREN RPAREN {puts("LPAREN RPAREN");}
  | LPAREN ExpressionList RPAREN {puts("LPAREN ExpressionList RPAREN");}
  | LPAREN Type RPAREN {puts("LPAREN Type RPAREN");}
  | LPAREN Type COMMA ExpressionList RPAREN {puts("LPAREN Type COMMA ExpressionList RPAREN");}
  | LPAREN COMMA RPAREN {puts("LPAREN COMMA RPAREN");}
  | LPAREN ExpressionList COMMA RPAREN {puts("LPAREN ExpressionList COMMA RPAREN");}
  | LPAREN Type COMMA RPAREN {puts("LPAREN Type COMMA RPAREN");}
  | LPAREN Type COMMA ExpressionList COMMA RPAREN {puts("LPAREN Type COMMA ExpressionList COMMA RPAREN");}
  ;

Expression : UnaryExpr {puts("UnaryExpr");}
  | Expression OR Expression {puts("Expression OR Expression");}
  | Expression AND Expression {puts("Expression AND Expression");}
  | Expression PLUS Expression {puts("Expression PLUS Expression");}
  | Expression MIN Expression {puts("Expression MIN Expression");}
  | Expression MUL Expression {puts("Expression MUL Expression");}
  | Expression DIV Expression {puts("Expression DIV Expression");}
  | Expression GT Expression {puts("Expression GT Expression");}
  | Expression GE Expression {puts("Expression GE Expression");}
  | Expression LT Expression {puts("Expression LT Expression");}
  | Expression LE Expression {puts("Expression LE Expression");}
  | Expression EQ Expression {puts("Expression EQ Expression");}
  | Expression NE Expression {puts("Expression NE Expression");}
  ;

UnaryExpr : PrimaryExpr {puts("PrimaryExpr");}
  | Unary_op UnaryExpr {puts("Unary_op UnaryExpr");}
  ;

/*
Binary_op : OR
  | AND
  | Rel_op
  | Add_op
  | Mul_op
  ;

Rel_op : EQ
  | NE
  | LT
  | LE
  | GT
  | GE
  ;

Add_op : PLUS
  | MIN
  ;

Mul_op : MUL
  | DIV
  ;
  */

Unary_op : PLUS %prec UMINUS {puts("PLUS");}
  | MIN %prec UMINUS {puts("MIN");}
  | NOT %prec UMINUS {puts("NOT");}
  ;
//////////////////////////////////////////////

//STATEMENTS

Statement : VarDecl {puts("VarDecl");}
  | SimpleStmt {puts("SimpleStmt");}
  | ReturnStmt {puts("ReturnStmt");}
  | Block {puts("Block");}
  | IfStmt {puts("IfStmt");}
  | ForStmt {puts("ForStmt");}
  ;

SimpleStmt : EmptyStmt {puts("EmptyStmt");}
  | ExpressionStmt {puts("ExpressionStmt");}
  | IncDecStmt {puts("IncDecStmt");}
  | Assignment {puts("Assignment");}
  ;

EmptyStmt : 
  ;

ExpressionStmt : Expression {puts("Expression");}
  ;

IncDecStmt : Expression INC {puts("Expression INC");}
  | Expression DEC {puts("Expression DEC");}
  ;

Assignment : ExpressionList Assign_op ExpressionList {puts("ExpressionList Assign_op ExpressionList");}
  ;

Assign_op : PLUSASSIGN {puts("PLUSASSIGN");}
  | MINASSIGN {puts("MINASSIGN");}
  | MULASSIGN {puts("MULASSIGN");}
  | DIVASSIGN {puts("DIVASSIGN");}
  ;

ReturnStmt : RETURN {puts("RETURN");}
  | RETURN ExpressionList {puts("RETURN ExpressionList");}
  ;

IfStmt : IF Expression Block {puts("IF Expression Block");}
  | IF Expression Block ELSE IfStmt {puts("IF Expression Block ELSE IfStmt");}
  | IF Expression Block ELSE Block {puts("IF Expression Block ELSE Block");}
  | IF SimpleStmt SEMICOLON Expression Block {puts("IF SimpleStmt SEMICOLON Expression Block");}
  | IF SimpleStmt SEMICOLON Expression Block ELSE IfStmt {puts("IF SimpleStmt SEMICOLON Expression Block ELSE IfStmt");}
  | IF SimpleStmt SEMICOLON Expression Block ELSE Block {puts("IF SimpleStmt SEMICOLON Expression Block ELSE Block");}
  ;

ForStmt : FOR Block {puts("FOR Block");}
  | FOR Condition Block {puts("FOR Condition Block");}
  | FOR ForClause Block {puts("FOR ForClause Block");}
  ;

Condition : Expression {puts("Expression");}
  ;

ForClause : InitStmt SEMICOLON Condition SEMICOLON PostStmt {puts("InitStmt SEMICOLON Condition SEMICOLON PostStmt");}
  | InitStmt SEMICOLON SEMICOLON PostStmt {puts("InitStmt SEMICOLON SEMICOLON PostStmt");}
  ;

InitStmt : SimpleStmt {puts("SimpleStmt");}
  ;

PostStmt : SimpleStmt {puts("SimpleStmt");}
  ;

//////////////////////////////////////////////

//PACKAGES

PackageClause : PACKAGE IDENTIFIER {puts("PACKAGE IDENTIFIER");
$$ = new PackageClause_($2);}
  ;

/*
PackageName : IDENTIFIER {puts("IDENTIFIER");}
  ;
*/

%%

void yyerror (const char *s)
{
  printf("%s", s);
}
