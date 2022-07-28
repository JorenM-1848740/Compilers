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
  Statement statement;
  SimpleStmt simpleStmt;
  ReturnStmt returnStmt;
  IfStmt ifStmt;
  ForStmt forStmt;
  IncDecStmt incDecStmt;
  Assignment assignment;
  ForClause forClause;
  Expression expression;
  Operand operand;
  Literal literal;
  PrimaryExpr primaryExpr;
  Arguments arguments;
  UnaryExpr unaryExpr;
  Unary_op unary_op;
  char* id;
}

// vul aan met tokendeclaraties
%token
  SEMICOLON COMMA
  INT BOOL
  PACKAGE RETURN VAR IF FOR FUNC ELSE
  LPAREN RPAREN LBRACE RBRACE
  PLUS MIN MUL DIV PLUSASSIGN MINASSIGN MULASSIGN DIVASSIGN ASSIGN UMINUS
  AND OR NOT INC DEC GT GE LT LE EQ NE

%token <id> IDENTIFIER
%token <id> INTLITERAL
%token <id> BOOLLITERAL
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
%type <statement> Statement
%type <simpleStmt> SimpleStmt
%type <returnStmt> ReturnStmt
%type <ifStmt> IfStmt
%type <forStmt> ForStmt
%type <incDecStmt> IncDecStmt
%type <assignment> Assignment
%type <forClause> ForClause
%type <expression> Expression
%type <operand> Operand
%type <literal> Literal
%type <primaryExpr> PrimaryExpr
%type <arguments> Arguments
%type <unaryExpr> UnaryExpr
%type <unary_op> Unary_op

%%

SourceFile : PackageClause SEMICOLON TopLevelDeclList {puts("PackageClause SEMICOLON TopLevelDeclList"); 
$$ = new SourceFile_($1, $3); thesyntree = $$;}
  ;

TopLevelDeclList : {$$ = new TopLevelDeclList_();}
  | TopLevelDeclList TopLevelDecl SEMICOLON {puts("TopLevelDeclList TopLevelDecl SEMICOLON");
$$ = new TopLevelDeclList_($1, $2);}
  ;

Block : LBRACE StatementList RBRACE {puts("LBRACE StatementList RBRACE");
$$ = new Block_($2);}
  ;

StatementList : {$$ = new StatementList_();}
  | StatementList Statement SEMICOLON {puts("StatementList Statement SEMICOLON");
$$ = new StatementList_($1, $2);}
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

ExpressionList : Expression {puts("Expression");
$$ = new ExpressionList_($1);}
  | ExpressionList COMMA Expression {puts("COMMA Expression");
$$ = new ExpressionList_($1, $3);}
  ;

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
$$ = new FunctionDecl_($2, $3);}
  | FUNC IDENTIFIER Signature Block {puts("FUNC FunctionName Signature FunctionBody");
$$ = new FunctionDecl_($2, $3, $4);}
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

Operand : Literal {puts("Literal");
$$ = new Operand_($1);}
  | IDENTIFIER {puts("OperandName");
$$ = new Operand_($1);}
  | LPAREN Expression RPAREN {puts("LPAREN Expression RPAREN");
$$ = new Operand_($2);}
  ;

Literal : INTLITERAL {puts("INTLITERAL");
$$ = new Literal_($1);}
  | BOOLLITERAL {puts("BOOLLITERAL");
$$ = new Literal_($1);}
  ;

PrimaryExpr : Operand {puts("Operand");
$$ = new PrimaryExpr_($1);}
  | PrimaryExpr Arguments {puts("PrimaryExpr Arguments");
$$ = new PrimaryExpr_($1, $2);}
  ;

Arguments : LPAREN RPAREN {puts("LPAREN RPAREN");
$$ = new Arguments_();}
  | LPAREN ExpressionList RPAREN {puts("LPAREN ExpressionList RPAREN");
$$ = new Arguments_($2);}
  | LPAREN Type RPAREN {puts("LPAREN Type RPAREN");
$$ = new Arguments_($2);}
  | LPAREN Type COMMA ExpressionList RPAREN {puts("LPAREN Type COMMA ExpressionList RPAREN");
$$ = new Arguments_($2, $4);}
  | LPAREN COMMA RPAREN {puts("LPAREN COMMA RPAREN");
$$ = new Arguments_();}
  | LPAREN ExpressionList COMMA RPAREN {puts("LPAREN ExpressionList COMMA RPAREN");
$$ = new Arguments_($2);}
  | LPAREN Type COMMA RPAREN {puts("LPAREN Type COMMA RPAREN");
$$ = new Arguments_($2);}
  | LPAREN Type COMMA ExpressionList COMMA RPAREN {puts("LPAREN Type COMMA ExpressionList COMMA RPAREN");
$$ = new Arguments_($2, $4);}
  ;

Expression : UnaryExpr {puts("UnaryExpr");
$$ = new Expression_($1);}
  | Expression OR Expression {puts("Expression OR Expression");
$$ = new Expression_($1, "or", $3);}
  | Expression AND Expression {puts("Expression AND Expression");
$$ = new Expression_($1, "and", $3);}
  | Expression PLUS Expression {puts("Expression PLUS Expression");
$$ = new Expression_($1, "plus", $3);}
  | Expression MIN Expression {puts("Expression MIN Expression");
$$ = new Expression_($1, "min", $3);}
  | Expression MUL Expression {puts("Expression MUL Expression");
$$ = new Expression_($1, "mul", $3);}
  | Expression DIV Expression {puts("Expression DIV Expression");
$$ = new Expression_($1, "div", $3);}
  | Expression GT Expression {puts("Expression GT Expression");
$$ = new Expression_($1, "gt", $3);}
  | Expression GE Expression {puts("Expression GE Expression");
$$ = new Expression_($1, "ge", $3);}
  | Expression LT Expression {puts("Expression LT Expression");
$$ = new Expression_($1, "lt", $3);}
  | Expression LE Expression {puts("Expression LE Expression");
$$ = new Expression_($1, "le", $3);}
  | Expression EQ Expression {puts("Expression EQ Expression");
$$ = new Expression_($1, "eq", $3);}
  | Expression NE Expression {puts("Expression NE Expression");
$$ = new Expression_($1, "ne", $3);}
  ;

UnaryExpr : PrimaryExpr {puts("PrimaryExpr");
$$ = new UnaryExpr_($1);}
  | Unary_op UnaryExpr {puts("Unary_op UnaryExpr");
$$ = new UnaryExpr_($1, $2);}
  ;

Unary_op : PLUS %prec UMINUS {puts("PLUS");
$$ = new Unary_op_("plus");}
  | MIN %prec UMINUS {puts("MIN");
$$ = new Unary_op_("min");}
  | NOT %prec UMINUS {puts("NOT");
$$ = new Unary_op_("not");}
  ;
//////////////////////////////////////////////

//STATEMENTS

Statement : VarDecl {puts("VarDecl");
$$ = new Statement_($1);}
  | SimpleStmt {puts("SimpleStmt");
$$ = new Statement_($1);}
  | ReturnStmt {puts("ReturnStmt");
$$ = new Statement_($1);}
  | Block {puts("Block");
$$ = new Statement_($1);}
  | IfStmt {puts("IfStmt");
$$ = new Statement_($1);}
  | ForStmt {puts("ForStmt");
$$ = new Statement_($1);}
  ;

SimpleStmt :  {puts("EmptyStmt");
$$ = new SimpleStmt_();}
  | Expression {puts("ExpressionStmt");
$$ = new SimpleStmt_($1);}
  | IncDecStmt {puts("IncDecStmt");
$$ = new SimpleStmt_($1);}
  | Assignment {puts("Assignment");
$$ = new SimpleStmt_($1);}
  ;

IncDecStmt : Expression INC {puts("Expression INC");
$$ = new IncDecStmt_($1, "inc");}
  | Expression DEC {puts("Expression DEC");
$$ = new IncDecStmt_($1, "dec");}
  ;

Assignment : ExpressionList PLUSASSIGN ExpressionList {puts("ExpressionList PLUSASSIGN ExpressionList");
$$ = new Assignment_($1, "plusassign", $3);}
  | ExpressionList MINASSIGN ExpressionList {puts("ExpressionList MINASSIGN ExpressionList");
$$ = new Assignment_($1, "minassign", $3);}
  | ExpressionList MULASSIGN ExpressionList {puts("ExpressionList MULASSIGN ExpressionList");
$$ = new Assignment_($1, "mulassign", $3);}
  | ExpressionList DIVASSIGN ExpressionList {puts("ExpressionList DIVASSIGN ExpressionList");
$$ = new Assignment_($1, "divassign", $3);}
  | ExpressionList ASSIGN ExpressionList {puts("ExpressionList ASSIGN ExpressionList");
$$ = new Assignment_($1, "assign", $3);}
  ;

ReturnStmt : RETURN {puts("RETURN");
$$ = new ReturnStmt_();}
  | RETURN ExpressionList {puts("RETURN ExpressionList");
$$ = new ReturnStmt_($2);}
  ;

IfStmt : IF Expression Block {puts("IF Expression Block");
$$ = new IfStmt_($2, $3);}
  | IF Expression Block ELSE IfStmt {puts("IF Expression Block ELSE IfStmt");
$$ = new IfStmt_($2, $3, $5);}
  | IF Expression Block ELSE Block {puts("IF Expression Block ELSE Block");
$$ = new IfStmt_($2, $3, $5);}
  | IF SimpleStmt SEMICOLON Expression Block {puts("IF SimpleStmt SEMICOLON Expression Block");
$$ = new IfStmt_($2, $4, $5);}
  | IF SimpleStmt SEMICOLON Expression Block ELSE IfStmt {puts("IF SimpleStmt SEMICOLON Expression Block ELSE IfStmt");
$$ = new IfStmt_($2, $4, $5, $7);}
  | IF SimpleStmt SEMICOLON Expression Block ELSE Block {puts("IF SimpleStmt SEMICOLON Expression Block ELSE Block");
$$ = new IfStmt_($2, $4, $5, $7);}
  ;

ForStmt : FOR Block {puts("FOR Block");
$$ = new ForStmt_($2);}
  | FOR Expression Block {puts("FOR Condition Block");
$$ = new ForStmt_($2, $3);}
  | FOR ForClause Block {puts("FOR ForClause Block");
$$ = new ForStmt_($2, $3);}
  ;

ForClause : SimpleStmt SEMICOLON Expression SEMICOLON SimpleStmt {puts("InitStmt SEMICOLON Condition SEMICOLON PostStmt");
$$ = new ForClause_($1, $3, $5);}
  | SimpleStmt SEMICOLON SEMICOLON SimpleStmt {puts("InitStmt SEMICOLON SEMICOLON PostStmt");
$$ = new ForClause_($1, $4);}
  ;

//////////////////////////////////////////////

//PACKAGES

PackageClause : PACKAGE IDENTIFIER {puts("PACKAGE IDENTIFIER");
$$ = new PackageClause_($2);}
  ;

%%

void yyerror (const char *s)
{
  printf("%s", s);
}
