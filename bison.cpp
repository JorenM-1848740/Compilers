/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "goBison.y"

#include <stdio.h>
#include "absyn.hpp"


void yyerror(const char* str);
extern int yylex();

SourceFile thesyntree;


#line 82 "bison.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 129 "bison.cpp"

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

#line 219 "bison.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   369

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

#define YYUNDEFTOK  2
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   114,   114,   118,   119,   123,   127,   128,   132,   134,
     138,   140,   145,   147,   151,   153,   159,   161,   165,   166,
     170,   172,   174,   184,   188,   190,   194,   196,   200,   202,
     204,   207,   209,   213,   215,   223,   225,   227,   231,   233,
     237,   239,   243,   245,   247,   249,   251,   253,   255,   257,
     261,   263,   265,   267,   269,   271,   273,   275,   277,   279,
     281,   283,   285,   289,   291,   295,   297,   299,   306,   308,
     310,   312,   314,   316,   320,   322,   324,   326,   330,   332,
     336,   338,   340,   342,   344,   348,   350,   354,   356,   358,
     360,   362,   364,   368,   370,   372,   376,   378,   386
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "COMMA", "INT", "BOOL",
  "PACKAGE", "RETURN", "VAR", "IF", "FOR", "FUNC", "ELSE", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "PLUS", "MIN", "MUL", "DIV", "PLUSASSIGN",
  "MINASSIGN", "MULASSIGN", "DIVASSIGN", "ASSIGN", "UMINUS", "AND", "OR",
  "NOT", "INC", "DEC", "GT", "GE", "LT", "LE", "EQ", "NE", "IDENTIFIER",
  "INTLITERAL", "BOOLLITERAL", "$accept", "SourceFile", "TopLevelDeclList",
  "Block", "StatementList", "IdentifierList", "Type", "ExpressionList",
  "TopLevelDecl", "VarDecl", "VarSpecList", "VarSpec", "FunctionDecl",
  "Signature", "Result", "Parameters", "ParameterList", "ParameterDecl",
  "Operand", "Literal", "PrimaryExpr", "Arguments", "Expression",
  "UnaryExpr", "Unary_op", "Statement", "SimpleStmt", "IncDecStmt",
  "Assignment", "ReturnStmt", "IfStmt", "ForStmt", "ForClause",
  "PackageClause", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF (-142)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-76)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,   -30,    11,    18,  -142,  -142,  -142,    49,     5,   -11,
      50,  -142,  -142,  -142,  -142,   113,  -142,    46,  -142,    41,
      26,  -142,  -142,   246,    59,    10,    52,    86,  -142,    73,
    -142,   246,  -142,  -142,  -142,  -142,  -142,  -142,    94,  -142,
    -142,    76,   304,  -142,   246,   246,  -142,    90,  -142,     2,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,   260,   246,   117,
    -142,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,  -142,    94,  -142,    58,  -142,   209,  -142,
     304,    91,  -142,     8,     9,    51,    51,  -142,  -142,   331,
     325,   182,   182,   182,   182,   182,   182,  -142,  -142,   246,
     246,    63,  -142,  -142,   120,  -142,   134,    98,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,   215,  -142,   222,  -142,    94,
     157,   102,  -142,   157,   105,    52,   246,   246,   246,   246,
     246,  -142,  -142,  -142,  -142,    42,  -142,   112,   246,  -142,
      48,  -142,    94,    94,    94,    94,    94,   228,  -142,     4,
     283,   246,   178,  -142,  -142,  -142,   115,  -142,   246,     4,
    -142,  -142,  -142
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,    98,     1,     3,     2,     0,     0,
       0,    14,    15,    18,     8,     0,    16,     0,     4,     0,
       0,    10,    11,     0,    21,     0,     0,    24,    17,     0,
       9,     0,    65,    66,    67,    36,    38,    39,    20,    40,
      35,    63,    12,    50,     0,     0,    28,     0,    34,     0,
      31,     6,    23,    27,    25,    26,    19,     0,     0,     0,
      41,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,    22,    33,     0,    29,    74,    37,
      13,     0,    42,     0,     0,    53,    54,    55,    56,    52,
      51,    57,    58,    59,    60,    61,    62,    30,    32,    85,
      74,    74,     5,    71,     0,    68,    12,     0,    69,    76,
      77,    70,    72,    73,    46,     0,    44,     0,    43,    86,
      12,     0,    93,    12,     0,     0,     0,     0,     0,     0,
       0,    78,    79,     7,    48,     0,    47,    87,     0,    94,
       0,    95,    80,    81,    82,    83,    84,     0,    45,     0,
       0,    74,     0,    49,    89,    88,    90,    97,    74,     0,
      96,    92,    91
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -142,  -142,  -142,   -75,  -142,   -21,    -5,   -16,  -142,    37,
    -142,   107,  -142,  -142,  -142,   103,  -142,    53,  -142,  -142,
    -142,  -142,   -31,    89,  -142,  -142,   -99,  -142,  -142,  -142,
    -141,  -142,  -142,  -142
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,    52,    78,    15,    48,   104,    10,    11,
      19,    16,    12,    26,    54,    27,    49,    50,    39,    40,
      41,    60,    42,    43,    44,   107,   108,   109,   110,   111,
     112,   113,   125,     3
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,   121,   124,   103,    47,     1,    76,    38,   155,     4,
      24,     5,   115,   117,   100,    21,    22,    77,   162,    13,
      51,     6,    53,   116,   118,    46,   122,    80,    17,    74,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    75,    84,    14,   137,   147,   106,   139,    14,
     141,   151,   157,    18,    83,    47,    28,   148,     8,   160,
      25,     9,    31,    21,    22,    30,    32,    33,    51,   120,
     123,    63,    64,    97,   154,   156,    56,    31,    34,    51,
      14,    32,    33,   119,   161,    45,    80,    35,    36,    37,
      59,    21,    22,    34,    20,    21,    22,    14,    58,   135,
      25,   133,    35,    36,    37,   138,   114,   150,   140,   152,
     142,   143,   144,   145,   146,   105,    80,    20,    21,    22,
     106,    81,    21,    22,    58,   149,    29,   106,   159,    98,
      55,    31,    82,    73,     0,    32,    33,   -75,     0,    23,
       0,     0,   126,   127,   128,   129,   130,    34,     0,     0,
     -75,     0,    61,    62,    63,    64,    35,    36,    37,     0,
     -75,     0,    65,    66,     0,   131,   132,    67,    68,    69,
      70,    71,    72,    51,     0,    61,    62,    63,    64,     0,
       0,   158,     0,     0,     0,    65,    66,     0,   131,   132,
      67,    68,    69,    70,    71,    72,    61,    62,    63,    64,
      61,    62,    63,    64,     0,     0,    65,    66,     0,     0,
       0,    67,    68,    69,    70,    71,    72,    99,     8,   100,
     101,     0,     0,    31,     0,    51,   102,    32,    33,    31,
     134,     0,     0,    32,    33,     0,    31,   136,     0,    34,
      32,    33,    31,   153,     0,    34,    32,    33,    35,    36,
      37,     0,    34,     0,    35,    36,    37,     0,    34,     0,
      31,    35,    36,    37,    32,    33,     0,    35,    36,    37,
       0,     0,     0,     0,     0,    79,    34,     0,    61,    62,
      63,    64,     0,     0,     0,    35,    36,    37,    65,    66,
       0,     0,     0,    67,    68,    69,    70,    71,    72,    51,
       0,    61,    62,    63,    64,     0,     0,     0,     0,     0,
       0,    65,    66,     0,     0,     0,    67,    68,    69,    70,
      71,    72,    61,    62,    63,    64,     0,     0,     0,     0,
       0,     0,    65,    66,     0,     0,     0,    67,    68,    69,
      70,    71,    72,    61,    62,    63,    64,     0,     0,    61,
      62,    63,    64,    65,     0,     0,     0,     0,    67,    68,
      69,    70,    71,    72,    67,    68,    69,    70,    71,    72
};

static const yytype_int16 yycheck[] =
{
      31,   100,   101,    78,    25,     7,     4,    23,   149,    39,
      15,     0,     4,     4,    10,     5,     6,    15,   159,    14,
      16,     3,    27,    15,    15,    15,   101,    58,    39,    45,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    47,    59,    39,   120,     4,    78,   123,    39,
     125,     3,   151,     3,    59,    76,    15,    15,     9,   158,
      14,    12,    14,     5,     6,    39,    18,    19,    16,   100,
     101,    20,    21,    15,   149,   150,     3,    14,    30,    16,
      39,    18,    19,    99,   159,    26,   117,    39,    40,    41,
      14,     5,     6,    30,     4,     5,     6,    39,     4,   115,
      14,     3,    39,    40,    41,     3,    15,   138,     3,   140,
     126,   127,   128,   129,   130,    78,   147,     4,     5,     6,
     151,     4,     5,     6,     4,    13,    19,   158,    13,    76,
      27,    14,    15,    44,    -1,    18,    19,     3,    -1,    26,
      -1,    -1,    22,    23,    24,    25,    26,    30,    -1,    -1,
      16,    -1,    18,    19,    20,    21,    39,    40,    41,    -1,
       3,    -1,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    16,    -1,    18,    19,    20,    21,    -1,
      -1,     3,    -1,    -1,    -1,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    18,    19,    20,    21,
      18,    19,    20,    21,    -1,    -1,    28,    29,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,     8,     9,    10,
      11,    -1,    -1,    14,    -1,    16,    17,    18,    19,    14,
      15,    -1,    -1,    18,    19,    -1,    14,    15,    -1,    30,
      18,    19,    14,    15,    -1,    30,    18,    19,    39,    40,
      41,    -1,    30,    -1,    39,    40,    41,    -1,    30,    -1,
      14,    39,    40,    41,    18,    19,    -1,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    15,    30,    -1,    18,    19,
      20,    21,    -1,    -1,    -1,    39,    40,    41,    28,    29,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    38,    16,
      -1,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38,    18,    19,    20,    21,    -1,    -1,    18,
      19,    20,    21,    28,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    33,    34,    35,    36,    37,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    43,    75,    39,     0,     3,    44,     9,    12,
      50,    51,    54,    14,    39,    47,    53,    39,     3,    52,
       4,     5,     6,    26,    48,    14,    55,    57,    15,    53,
      39,    14,    18,    19,    30,    39,    40,    41,    49,    60,
      61,    62,    64,    65,    66,    26,    15,    47,    48,    58,
      59,    16,    45,    48,    56,    57,     3,    64,     4,    14,
      63,    18,    19,    20,    21,    28,    29,    33,    34,    35,
      36,    37,    38,    65,    49,    48,     4,    15,    46,    15,
      64,     4,    15,    48,    49,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    15,    59,     8,
      10,    11,    17,    45,    49,    51,    64,    67,    68,    69,
      70,    71,    72,    73,    15,     4,    15,     4,    15,    49,
      64,    68,    45,    64,    68,    74,    22,    23,    24,    25,
      26,    31,    32,     3,    15,    49,    15,    45,     3,    45,
       3,    45,    49,    49,    49,    49,    49,     4,    15,    13,
      64,     3,    64,    15,    45,    72,    45,    68,     3,    13,
      68,    45,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    46,    46,    47,    47,
      48,    48,    49,    49,    50,    50,    51,    51,    52,    52,
      53,    53,    53,    54,    55,    55,    56,    56,    57,    57,
      57,    58,    58,    59,    59,    60,    60,    60,    61,    61,
      62,    62,    63,    63,    63,    63,    63,    63,    63,    63,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    66,    66,    66,    67,    67,
      67,    67,    67,    67,    68,    68,    68,    68,    69,    69,
      70,    70,    70,    70,    70,    71,    71,    72,    72,    72,
      72,    72,    72,    73,    73,    73,    74,    74,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     3,     3,     0,     3,     1,     3,
       1,     1,     1,     3,     1,     1,     2,     4,     0,     3,
       3,     2,     4,     4,     1,     2,     1,     1,     2,     3,
       4,     1,     3,     2,     1,     1,     1,     3,     1,     1,
       1,     2,     2,     3,     3,     5,     3,     4,     4,     6,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     1,     1,     2,     2,
       3,     3,     3,     3,     3,     1,     2,     3,     5,     5,
       5,     7,     7,     2,     3,     3,     5,     4,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 114 "goBison.y"
                                                      {puts("PackageClause SEMICOLON TopLevelDeclList"); 
(yyval.sourceFile) = new SourceFile_((yyvsp[-2].packageClause), (yyvsp[0].topLevelDeclList)); thesyntree = (yyval.sourceFile);}
#line 1554 "bison.cpp"
    break;

  case 3:
#line 118 "goBison.y"
                   {(yyval.topLevelDeclList) = new TopLevelDeclList_();}
#line 1560 "bison.cpp"
    break;

  case 4:
#line 119 "goBison.y"
                                            {puts("TopLevelDeclList TopLevelDecl SEMICOLON");
(yyval.topLevelDeclList) = new TopLevelDeclList_((yyvsp[-2].topLevelDeclList), (yyvsp[-1].topLevelDecl));}
#line 1567 "bison.cpp"
    break;

  case 5:
#line 123 "goBison.y"
                                    {puts("LBRACE StatementList RBRACE");
(yyval.block) = new Block_((yyvsp[-1].statementList));}
#line 1574 "bison.cpp"
    break;

  case 6:
#line 127 "goBison.y"
                {(yyval.statementList) = new StatementList_();}
#line 1580 "bison.cpp"
    break;

  case 7:
#line 128 "goBison.y"
                                      {puts("StatementList Statement SEMICOLON");
(yyval.statementList) = new StatementList_((yyvsp[-2].statementList), (yyvsp[-1].statement));}
#line 1587 "bison.cpp"
    break;

  case 8:
#line 132 "goBison.y"
                            {puts("IDENTIFIER");
(yyval.identifierList) = new IdentifierList_((yyvsp[0].id));}
#line 1594 "bison.cpp"
    break;

  case 9:
#line 134 "goBison.y"
                                    {puts("COMMA IDENTIFIER");
(yyval.identifierList) = new IdentifierList_((yyvsp[-2].identifierList), (yyvsp[0].id));}
#line 1601 "bison.cpp"
    break;

  case 10:
#line 138 "goBison.y"
           {puts("INT");
(yyval.type) = new Type_("int");}
#line 1608 "bison.cpp"
    break;

  case 11:
#line 140 "goBison.y"
         {puts("BOOL");
(yyval.type) = new Type_("bool");}
#line 1615 "bison.cpp"
    break;

  case 12:
#line 145 "goBison.y"
                            {puts("Expression");
(yyval.expressionList) = new ExpressionList_((yyvsp[0].expression));}
#line 1622 "bison.cpp"
    break;

  case 13:
#line 147 "goBison.y"
                                    {puts("COMMA Expression");
(yyval.expressionList) = new ExpressionList_((yyvsp[-2].expressionList), (yyvsp[0].expression));}
#line 1629 "bison.cpp"
    break;

  case 14:
#line 151 "goBison.y"
                       {puts("VarDecl");
(yyval.topLevelDecl) = new TopLevelDecl_((yyvsp[0].varDecl));}
#line 1636 "bison.cpp"
    break;

  case 15:
#line 153 "goBison.y"
                 {puts("FunctionDecl");
(yyval.topLevelDecl) = new TopLevelDecl_((yyvsp[0].functionDecl));}
#line 1643 "bison.cpp"
    break;

  case 16:
#line 159 "goBison.y"
                      {puts("VAR VarSpec");
(yyval.varDecl) = new VarDecl_((yyvsp[0].varSpec));}
#line 1650 "bison.cpp"
    break;

  case 17:
#line 161 "goBison.y"
                                  {puts("VAR LPAREN VarSpecList RPAREN");
(yyval.varDecl) = new VarDecl_((yyvsp[-1].varSpecList));}
#line 1657 "bison.cpp"
    break;

  case 18:
#line 165 "goBison.y"
              {(yyval.varSpecList) = new VarSpecList_();}
#line 1663 "bison.cpp"
    break;

  case 19:
#line 166 "goBison.y"
                                  {puts("VarSpecList SEMICOLON VarSpec");
(yyval.varSpecList) = new VarSpecList_((yyvsp[-2].varSpecList), (yyvsp[-1].varSpec));}
#line 1670 "bison.cpp"
    break;

  case 20:
#line 170 "goBison.y"
                                               {puts("IdentifierList ASSIGN ExpressionList");
(yyval.varSpec) = new VarSpec_((yyvsp[-2].identifierList), (yyvsp[0].expressionList));}
#line 1677 "bison.cpp"
    break;

  case 21:
#line 172 "goBison.y"
                        {puts("IdentifierList Type");
(yyval.varSpec) = new VarSpec_((yyvsp[-1].identifierList), (yyvsp[0].type));}
#line 1684 "bison.cpp"
    break;

  case 22:
#line 174 "goBison.y"
                                              {puts("IdentifierList Type ASSIGN ExpressionList");
(yyval.varSpec) = new VarSpec_((yyvsp[-3].identifierList), (yyvsp[-2].type), (yyvsp[0].expressionList));}
#line 1691 "bison.cpp"
    break;

  case 23:
#line 184 "goBison.y"
                                               {puts("FUNC FunctionName Signature FunctionBody");
(yyval.functionDecl) = new FunctionDecl_((yyvsp[-2].id), (yyvsp[-1].signature), (yyvsp[0].block));}
#line 1698 "bison.cpp"
    break;

  case 24:
#line 188 "goBison.y"
                       {puts("Parameters");
(yyval.signature) = new Signature_((yyvsp[0].parameters));}
#line 1705 "bison.cpp"
    break;

  case 25:
#line 190 "goBison.y"
                      {puts("Parameters Result");
(yyval.signature) = new Signature_((yyvsp[-1].parameters), (yyvsp[0].result));}
#line 1712 "bison.cpp"
    break;

  case 26:
#line 194 "goBison.y"
                    {puts("Parameters");
(yyval.result) = new Result_((yyvsp[0].parameters));}
#line 1719 "bison.cpp"
    break;

  case 27:
#line 196 "goBison.y"
         {puts("Type");
(yyval.result) = new Result_((yyvsp[0].type));}
#line 1726 "bison.cpp"
    break;

  case 28:
#line 200 "goBison.y"
                           {puts("LPAREN RPAREN");
(yyval.parameters) = new Parameters_();}
#line 1733 "bison.cpp"
    break;

  case 29:
#line 202 "goBison.y"
                                {puts("LPAREN ParameterList RPAREN");
(yyval.parameters) = new Parameters_((yyvsp[-1].parameterList));}
#line 1740 "bison.cpp"
    break;

  case 30:
#line 204 "goBison.y"
                                      {puts("LPAREN ParameterList COMMA RPAREN");
(yyval.parameters) = new Parameters_((yyvsp[-2].parameterList));}
#line 1747 "bison.cpp"
    break;

  case 31:
#line 207 "goBison.y"
                              {puts("ParameterDecl");
(yyval.parameterList) = new ParameterList_((yyvsp[0].parameterDecl));}
#line 1754 "bison.cpp"
    break;

  case 32:
#line 209 "goBison.y"
                                      {puts("ParameterList COMMA ParameterDecl");
(yyval.parameterList) = new ParameterList_((yyvsp[-2].parameterList), (yyvsp[0].parameterDecl));}
#line 1761 "bison.cpp"
    break;

  case 33:
#line 213 "goBison.y"
                                    {puts("IdentifierList Type");
(yyval.parameterDecl) = new ParameterDecl_((yyvsp[-1].identifierList), (yyvsp[0].type));}
#line 1768 "bison.cpp"
    break;

  case 34:
#line 215 "goBison.y"
         {puts("Type");
(yyval.parameterDecl) = new ParameterDecl_((yyvsp[0].type));}
#line 1775 "bison.cpp"
    break;

  case 35:
#line 223 "goBison.y"
                  {puts("Literal");
(yyval.operand) = new Operand_((yyvsp[0].literal));}
#line 1782 "bison.cpp"
    break;

  case 36:
#line 225 "goBison.y"
               {puts("OperandName");
(yyval.operand) = new Operand_((yyvsp[0].id));}
#line 1789 "bison.cpp"
    break;

  case 37:
#line 227 "goBison.y"
                             {puts("LPAREN Expression RPAREN");
(yyval.operand) = new Operand_((yyvsp[-1].expression));}
#line 1796 "bison.cpp"
    break;

  case 38:
#line 231 "goBison.y"
                     {puts("INTLITERAL");
(yyval.literal) = new Literal_((yyvsp[0].id), "int");}
#line 1803 "bison.cpp"
    break;

  case 39:
#line 233 "goBison.y"
                {puts("BOOLLITERAL");
(yyval.literal) = new Literal_((yyvsp[0].id), "bool");}
#line 1810 "bison.cpp"
    break;

  case 40:
#line 237 "goBison.y"
                      {puts("Operand");
(yyval.primaryExpr) = new PrimaryExpr_((yyvsp[0].operand));}
#line 1817 "bison.cpp"
    break;

  case 41:
#line 239 "goBison.y"
                          {puts("PrimaryExpr Arguments"); //Function call
(yyval.primaryExpr) = new PrimaryExpr_((yyvsp[-1].primaryExpr), (yyvsp[0].arguments));}
#line 1824 "bison.cpp"
    break;

  case 42:
#line 243 "goBison.y"
                          {puts("LPAREN RPAREN");
(yyval.arguments) = new Arguments_();}
#line 1831 "bison.cpp"
    break;

  case 43:
#line 245 "goBison.y"
                                 {puts("LPAREN ExpressionList RPAREN");
(yyval.arguments) = new Arguments_((yyvsp[-1].expressionList));}
#line 1838 "bison.cpp"
    break;

  case 44:
#line 247 "goBison.y"
                       {puts("LPAREN Type RPAREN");
(yyval.arguments) = new Arguments_((yyvsp[-1].type));}
#line 1845 "bison.cpp"
    break;

  case 45:
#line 249 "goBison.y"
                                            {puts("LPAREN Type COMMA ExpressionList RPAREN");
(yyval.arguments) = new Arguments_((yyvsp[-3].type), (yyvsp[-1].expressionList));}
#line 1852 "bison.cpp"
    break;

  case 46:
#line 251 "goBison.y"
                        {puts("LPAREN COMMA RPAREN");
(yyval.arguments) = new Arguments_();}
#line 1859 "bison.cpp"
    break;

  case 47:
#line 253 "goBison.y"
                                       {puts("LPAREN ExpressionList COMMA RPAREN");
(yyval.arguments) = new Arguments_((yyvsp[-2].expressionList));}
#line 1866 "bison.cpp"
    break;

  case 48:
#line 255 "goBison.y"
                             {puts("LPAREN Type COMMA RPAREN");
(yyval.arguments) = new Arguments_((yyvsp[-2].type));}
#line 1873 "bison.cpp"
    break;

  case 49:
#line 257 "goBison.y"
                                                  {puts("LPAREN Type COMMA ExpressionList COMMA RPAREN");
(yyval.arguments) = new Arguments_((yyvsp[-4].type), (yyvsp[-2].expressionList));}
#line 1880 "bison.cpp"
    break;

  case 50:
#line 261 "goBison.y"
                       {puts("UnaryExpr");
(yyval.expression) = new Expression_((yyvsp[0].unaryExpr));}
#line 1887 "bison.cpp"
    break;

  case 51:
#line 263 "goBison.y"
                             {puts("Expression OR Expression");
(yyval.expression) = new Expression_((yyvsp[-2].expression), "or", (yyvsp[0].expression));}
#line 1894 "bison.cpp"
    break;

  case 52:
#line 265 "goBison.y"
                              {puts("Expression AND Expression");
(yyval.expression) = new Expression_((yyvsp[-2].expression), "and", (yyvsp[0].expression));}
#line 1901 "bison.cpp"
    break;

  case 53:
#line 267 "goBison.y"
                               {puts("Expression PLUS Expression");
(yyval.expression) = new Expression_((yyvsp[-2].expression), "plus", (yyvsp[0].expression));}
#line 1908 "bison.cpp"
    break;

  case 54:
#line 269 "goBison.y"
                              {puts("Expression MIN Expression");
(yyval.expression) = new Expression_((yyvsp[-2].expression), "min", (yyvsp[0].expression));}
#line 1915 "bison.cpp"
    break;

  case 55:
#line 271 "goBison.y"
                              {puts("Expression MUL Expression");
(yyval.expression) = new Expression_((yyvsp[-2].expression), "mul", (yyvsp[0].expression));}
#line 1922 "bison.cpp"
    break;

  case 56:
#line 273 "goBison.y"
                              {puts("Expression DIV Expression");
(yyval.expression) = new Expression_((yyvsp[-2].expression), "div", (yyvsp[0].expression));}
#line 1929 "bison.cpp"
    break;

  case 57:
#line 275 "goBison.y"
                             {puts("Expression GT Expression");
(yyval.expression) = new Expression_((yyvsp[-2].expression), "gt", (yyvsp[0].expression));}
#line 1936 "bison.cpp"
    break;

  case 58:
#line 277 "goBison.y"
                             {puts("Expression GE Expression");
(yyval.expression) = new Expression_((yyvsp[-2].expression), "ge", (yyvsp[0].expression));}
#line 1943 "bison.cpp"
    break;

  case 59:
#line 279 "goBison.y"
                             {puts("Expression LT Expression");
(yyval.expression) = new Expression_((yyvsp[-2].expression), "lt", (yyvsp[0].expression));}
#line 1950 "bison.cpp"
    break;

  case 60:
#line 281 "goBison.y"
                             {puts("Expression LE Expression");
(yyval.expression) = new Expression_((yyvsp[-2].expression), "le", (yyvsp[0].expression));}
#line 1957 "bison.cpp"
    break;

  case 61:
#line 283 "goBison.y"
                             {puts("Expression EQ Expression");
(yyval.expression) = new Expression_((yyvsp[-2].expression), "eq", (yyvsp[0].expression));}
#line 1964 "bison.cpp"
    break;

  case 62:
#line 285 "goBison.y"
                             {puts("Expression NE Expression");
(yyval.expression) = new Expression_((yyvsp[-2].expression), "ne", (yyvsp[0].expression));}
#line 1971 "bison.cpp"
    break;

  case 63:
#line 289 "goBison.y"
                        {puts("PrimaryExpr");
(yyval.unaryExpr) = new UnaryExpr_((yyvsp[0].primaryExpr));}
#line 1978 "bison.cpp"
    break;

  case 64:
#line 291 "goBison.y"
                       {puts("Unary_op UnaryExpr");
(yyval.unaryExpr) = new UnaryExpr_((yyvsp[-1].unary_op), (yyvsp[0].unaryExpr));}
#line 1985 "bison.cpp"
    break;

  case 65:
#line 295 "goBison.y"
                             {puts("PLUS");
(yyval.unary_op) = new Unary_op_("plus");}
#line 1992 "bison.cpp"
    break;

  case 66:
#line 297 "goBison.y"
                     {puts("MIN");
(yyval.unary_op) = new Unary_op_("min");}
#line 1999 "bison.cpp"
    break;

  case 67:
#line 299 "goBison.y"
                     {puts("NOT");
(yyval.unary_op) = new Unary_op_("not");}
#line 2006 "bison.cpp"
    break;

  case 68:
#line 306 "goBison.y"
                    {puts("VarDecl");
(yyval.statement) = new Statement_((yyvsp[0].varDecl));}
#line 2013 "bison.cpp"
    break;

  case 69:
#line 308 "goBison.y"
               {puts("SimpleStmt");
(yyval.statement) = new Statement_((yyvsp[0].simpleStmt));}
#line 2020 "bison.cpp"
    break;

  case 70:
#line 310 "goBison.y"
               {puts("ReturnStmt");
(yyval.statement) = new Statement_((yyvsp[0].returnStmt));}
#line 2027 "bison.cpp"
    break;

  case 71:
#line 312 "goBison.y"
          {puts("Block");
(yyval.statement) = new Statement_((yyvsp[0].block));}
#line 2034 "bison.cpp"
    break;

  case 72:
#line 314 "goBison.y"
           {puts("IfStmt");
(yyval.statement) = new Statement_((yyvsp[0].ifStmt));}
#line 2041 "bison.cpp"
    break;

  case 73:
#line 316 "goBison.y"
            {puts("ForStmt");
(yyval.statement) = new Statement_((yyvsp[0].forStmt));}
#line 2048 "bison.cpp"
    break;

  case 74:
#line 320 "goBison.y"
              {puts("EmptyStmt");
(yyval.simpleStmt) = new SimpleStmt_();}
#line 2055 "bison.cpp"
    break;

  case 75:
#line 322 "goBison.y"
               {puts("ExpressionStmt");
(yyval.simpleStmt) = new SimpleStmt_((yyvsp[0].expression));}
#line 2062 "bison.cpp"
    break;

  case 76:
#line 324 "goBison.y"
               {puts("IncDecStmt");
(yyval.simpleStmt) = new SimpleStmt_((yyvsp[0].incDecStmt));}
#line 2069 "bison.cpp"
    break;

  case 77:
#line 326 "goBison.y"
               {puts("Assignment");
(yyval.simpleStmt) = new SimpleStmt_((yyvsp[0].assignment));}
#line 2076 "bison.cpp"
    break;

  case 78:
#line 330 "goBison.y"
                            {puts("Expression INC");
(yyval.incDecStmt) = new IncDecStmt_((yyvsp[-1].expression), "inc");}
#line 2083 "bison.cpp"
    break;

  case 79:
#line 332 "goBison.y"
                   {puts("Expression DEC");
(yyval.incDecStmt) = new IncDecStmt_((yyvsp[-1].expression), "dec");}
#line 2090 "bison.cpp"
    break;

  case 80:
#line 336 "goBison.y"
                                                      {puts("ExpressionList PLUSASSIGN ExpressionList");
(yyval.assignment) = new Assignment_((yyvsp[-2].expressionList), "plusassign", (yyvsp[0].expressionList));}
#line 2097 "bison.cpp"
    break;

  case 81:
#line 338 "goBison.y"
                                            {puts("ExpressionList MINASSIGN ExpressionList");
(yyval.assignment) = new Assignment_((yyvsp[-2].expressionList), "minassign", (yyvsp[0].expressionList));}
#line 2104 "bison.cpp"
    break;

  case 82:
#line 340 "goBison.y"
                                            {puts("ExpressionList MULASSIGN ExpressionList");
(yyval.assignment) = new Assignment_((yyvsp[-2].expressionList), "mulassign", (yyvsp[0].expressionList));}
#line 2111 "bison.cpp"
    break;

  case 83:
#line 342 "goBison.y"
                                            {puts("ExpressionList DIVASSIGN ExpressionList");
(yyval.assignment) = new Assignment_((yyvsp[-2].expressionList), "divassign", (yyvsp[0].expressionList));}
#line 2118 "bison.cpp"
    break;

  case 84:
#line 344 "goBison.y"
                                         {puts("ExpressionList ASSIGN ExpressionList");
(yyval.assignment) = new Assignment_((yyvsp[-2].expressionList), "assign", (yyvsp[0].expressionList));}
#line 2125 "bison.cpp"
    break;

  case 85:
#line 348 "goBison.y"
                    {puts("RETURN");
(yyval.returnStmt) = new ReturnStmt_();}
#line 2132 "bison.cpp"
    break;

  case 86:
#line 350 "goBison.y"
                          {puts("RETURN ExpressionList");
(yyval.returnStmt) = new ReturnStmt_((yyvsp[0].expressionList));}
#line 2139 "bison.cpp"
    break;

  case 87:
#line 354 "goBison.y"
                             {puts("IF Expression Block");
(yyval.ifStmt) = new IfStmt_((yyvsp[-1].expression), (yyvsp[0].block));}
#line 2146 "bison.cpp"
    break;

  case 88:
#line 356 "goBison.y"
                                    {puts("IF Expression Block ELSE IfStmt");
(yyval.ifStmt) = new IfStmt_((yyvsp[-3].expression), (yyvsp[-2].block), (yyvsp[0].ifStmt));}
#line 2153 "bison.cpp"
    break;

  case 89:
#line 358 "goBison.y"
                                   {puts("IF Expression Block ELSE Block");
(yyval.ifStmt) = new IfStmt_((yyvsp[-3].expression), (yyvsp[-2].block), (yyvsp[0].block));}
#line 2160 "bison.cpp"
    break;

  case 90:
#line 360 "goBison.y"
                                             {puts("IF SimpleStmt SEMICOLON Expression Block");
(yyval.ifStmt) = new IfStmt_((yyvsp[-3].simpleStmt), (yyvsp[-1].expression), (yyvsp[0].block));}
#line 2167 "bison.cpp"
    break;

  case 91:
#line 362 "goBison.y"
                                                         {puts("IF SimpleStmt SEMICOLON Expression Block ELSE IfStmt");
(yyval.ifStmt) = new IfStmt_((yyvsp[-5].simpleStmt), (yyvsp[-3].expression), (yyvsp[-2].block), (yyvsp[0].ifStmt));}
#line 2174 "bison.cpp"
    break;

  case 92:
#line 364 "goBison.y"
                                                        {puts("IF SimpleStmt SEMICOLON Expression Block ELSE Block");
(yyval.ifStmt) = new IfStmt_((yyvsp[-5].simpleStmt), (yyvsp[-3].expression), (yyvsp[-2].block), (yyvsp[0].block));}
#line 2181 "bison.cpp"
    break;

  case 93:
#line 368 "goBison.y"
                    {puts("FOR Block");
(yyval.forStmt) = new ForStmt_((yyvsp[0].block));}
#line 2188 "bison.cpp"
    break;

  case 94:
#line 370 "goBison.y"
                         {puts("FOR Condition Block");
(yyval.forStmt) = new ForStmt_((yyvsp[-1].expression), (yyvsp[0].block));}
#line 2195 "bison.cpp"
    break;

  case 95:
#line 372 "goBison.y"
                        {puts("FOR ForClause Block");
(yyval.forStmt) = new ForStmt_((yyvsp[-1].forClause), (yyvsp[0].block));}
#line 2202 "bison.cpp"
    break;

  case 96:
#line 376 "goBison.y"
                                                                 {puts("InitStmt SEMICOLON Condition SEMICOLON PostStmt");
(yyval.forClause) = new ForClause_((yyvsp[-4].simpleStmt), (yyvsp[-2].expression), (yyvsp[0].simpleStmt));}
#line 2209 "bison.cpp"
    break;

  case 97:
#line 378 "goBison.y"
                                              {puts("InitStmt SEMICOLON SEMICOLON PostStmt");
(yyval.forClause) = new ForClause_((yyvsp[-3].simpleStmt), (yyvsp[0].simpleStmt));}
#line 2216 "bison.cpp"
    break;

  case 98:
#line 386 "goBison.y"
                                   {puts("PACKAGE IDENTIFIER");
(yyval.packageClause) = new PackageClause_((yyvsp[0].id));}
#line 2223 "bison.cpp"
    break;


#line 2227 "bison.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 390 "goBison.y"


void yyerror (const char *s)
{
  printf("%s", s);
}
