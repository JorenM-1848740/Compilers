/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_BISON_HPP_INCLUDED
# define YY_YY_BISON_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 12 "goBison.y"

    #include "absyn.hpp"

#line 52 "bison.hpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOLON = 258,
    COMMA = 259,
    INT = 260,
    BOOL = 261,
    PACKAGE = 262,
    RETURN = 263,
    VAR = 264,
    IF = 265,
    FOR = 266,
    FUNC = 267,
    ELSE = 268,
    LPAREN = 269,
    RPAREN = 270,
    LBRACE = 271,
    RBRACE = 272,
    PLUS = 273,
    MIN = 274,
    MUL = 275,
    DIV = 276,
    PLUSASSIGN = 277,
    MINASSIGN = 278,
    MULASSIGN = 279,
    DIVASSIGN = 280,
    ASSIGN = 281,
    UMINUS = 282,
    AND = 283,
    OR = 284,
    NOT = 285,
    INC = 286,
    DEC = 287,
    GT = 288,
    GE = 289,
    LT = 290,
    LE = 291,
    EQ = 292,
    NE = 293,
    IDENTIFIER = 294,
    INTLITERAL = 295,
    BOOLLITERAL = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "goBison.y"

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

#line 142 "bison.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_HPP_INCLUDED  */
