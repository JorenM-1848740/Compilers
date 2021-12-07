%{
#include <stdio.h>


void yyerror(const char* str);
extern int yylex();

%}

// vul aan met tokendeclaraties
%token
  SEMICOLON COMMA
  IDENTIFIER INTLITERAL BOOLLITERAL
  INT BOOL
  PACKAGE RETURN VAR IF FOR FUNC ELSE
  LPAREN RPAREN LBRACE RBRACE
  PLUS MIN MUL DIV PLUSASSIGN MINASSIGN MULASSIGN DIVASSIGN ASSIGN UMINUS
  AND OR NOT INC DEC GT GE LT LE EQ NE
// vul aan met voorrangdeclaraties


%left OR
%left AND
%left EQ NE GT GE LT LE
%left PLUS MIN
%left MUL DIV



%right UMINUS


%defines
%define parse.error verbose

%%

SourceFile : PackageClause SEMICOLON SourceFileH1 {puts("PackageClause SEMICOLON SourceFileH1");;}
  ;

SourceFileH1 : 
  | SourceFileH1 TopLevelDecl SEMICOLON {puts("SourceFileH1 TopLevelDecl SEMICOLON");;}
  ;

// vul aan met producties
Block : LBRACE StatementList RBRACE {puts("LBRACE StatementList RBRACE");;}
  ;

StatementList : 
  | StatementList Statement SEMICOLON {puts("StatementList Statement SEMICOLON");;}
  ;

IdentifierList : IDENTIFIER {puts("IDENTIFIER");}
  | IdentifierList COMMA IDENTIFIER {puts("COMMA IDENTIFIER");}
  ;

Type : INT {puts("INT");}
  | BOOL {puts("BOOL");}
  | LPAREN Type RPAREN {puts("LPAREN Type RPAREN");}
  ;

ExpressionList : Expression {puts("Expression");}
  | ExpressionList COMMA Expression {puts("COMMA Expression");}
  ;

Declaration : VarDecl {puts("VarDecl");}
  ;

TopLevelDecl : Declaration {puts("Declaration");}
  | FunctionDecl {puts("FunctionDecl");}
  ;

//VARIABLE DECLARATION

VarDecl : VAR VarSpec {puts("VAR VarSpec");}
  | VAR LPAREN VarSpecList RPAREN {puts("VAR LPAREN VarSpecList RPAREN");}
  ;

VarSpecList : 
  | VarSpec SEMICOLON VarSpecList {puts("VarSpec SEMICOLON VarSpecList");}
  ;

VarSpec : IdentifierList ASSIGN ExpressionList {puts("IdentifierList ASSIGN ExpressionList");}
  | IdentifierList Type {puts("IdentifierList Type");}
  | IdentifierList Type ASSIGN ExpressionList {puts("IdentifierList Type ASSIGN ExpressionList");}
  ;

//////////////////////////////////////////////



//FUNCTION DECLARATION

FunctionDecl : FUNC FunctionName Signature {puts("FUNC FunctionName Signature");}
  | FUNC FunctionName Signature FunctionBody {puts("FUNC FunctionName Signature FunctionBody");}
  ;

FunctionName : IDENTIFIER {puts("IDENTIFIER");}
  ;

FunctionBody : Block {puts("Block");}
  ;

Signature : Parameters {puts("Parameters");}
  | Parameters Result {puts("Parameters Result");}
  ;

Result : Parameters {puts("Parameters");}
  | Type {puts("Type");}
  ;

Parameters : LPAREN RPAREN {puts("LPAREN RPAREN");}
  | LPAREN ParameterList RPAREN {puts("LPAREN ParameterList RPAREN");}
  | LPAREN ParameterList COMMA RPAREN {puts("LPAREN ParameterList COMMA RPAREN");}
  ;
ParameterList : ParameterDecl {puts("ParameterDecl");}
  | ParameterList COMMA ParameterDecl {puts("ParameterList COMMA ParameterDecl");}
  ;

ParameterDecl : IdentifierList Type {puts("IdentifierList Type");}
//  | Type {puts("Type");}
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

Statement : Declaration {puts("Declaration");}
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

PackageClause : PACKAGE PackageName {puts("PACKAGE PackageName");}
  ;

PackageName : IDENTIFIER {puts("IDENTIFIER");}
  ;

%%

void yyerror (const char *s)
{
  printf("%s", s);
}
