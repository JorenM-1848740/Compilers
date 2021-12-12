%{
/* 
go.lex: lex-file for go basisniveau
*/

#include "bison.hpp"

  /* Keep track of current position of lex for error messages, i.e. 
     the position just *after* the last token read */
  int line_nr = 1;
  int col_nr = 0; 
  int lexPos = 1;

  int lastTokenType = 0;

  void ADJUST() {col_nr = lexPos; lexPos += yyleng;}

%}

unicode_letter [a-zA-Z]
unicode_digit [0-9]
letter {unicode_letter}|_

decimal_digit [0-9]
decimal_digits {decimal_digit}(_?{decimal_digit})*

decimal_lit 0|([1-9](_?{decimal_digits})?)
identifier {letter}({letter}|{unicode_digit})*
bool_lit true|false

whitespace (" "|"\t"|"\r")

%%

\n {
  line_nr++;
  col_nr = 0;
  lexPos = 1;

  if(lastTokenType == IDENTIFIER || lastTokenType == INTLITERAL || lastTokenType == RETURN || lastTokenType == INC ||
      lastTokenType == DEC || lastTokenType == RPAREN || lastTokenType == RBRACE){
    lastTokenType = SEMICOLON;
    return SEMICOLON;
  }
}

\; {
  ADJUST();
  lastTokenType = SEMICOLON;
  return SEMICOLON;
}

package {
  ADJUST();
  lastTokenType = PACKAGE;
  return PACKAGE;
}

, {
  ADJUST();
  lastTokenType == COMMA;
  return COMMA;
}

= {
  ADJUST();
  lastTokenType = ASSIGN;
  return ASSIGN;
}

\+ {
  ADJUST();
  lastTokenType = PLUS;
  return PLUS;
}

- {
  ADJUST();
  lastTokenType = MIN;
  return MIN;
}

\* {
  ADJUST();
  lastTokenType = MUL;
  return MUL;
}

\/ {
  ADJUST();
  lastTokenType = DIV;
  return DIV;
}

\+= {
  ADJUST();
  lastTokenType = PLUSASSIGN;
  return PLUSASSIGN;
}

-= {
  ADJUST();
  lastTokenType = MINASSIGN;
  return MINASSIGN;
}

\*= {
  ADJUST();
  lastTokenType = MULASSIGN;
  return MULASSIGN;
}

\/= {
  ADJUST();
  lastTokenType = DIVASSIGN;
  return DIVASSIGN;
}

&& {
  ADJUST();
  lastTokenType = AND;
  return AND;
}

\|\| {
  ADJUST();
  lastTokenType = OR;
  return OR;
}

! {
  ADJUST();
  lastTokenType = NOT;
  return NOT;
}

\( {
  ADJUST();
  lastTokenType = LPAREN;
  return LPAREN;
}

\) {
  ADJUST();
  lastTokenType = RPAREN;
  return RPAREN;
}

\{ {
  ADJUST();
  lastTokenType = LBRACE;
  return LBRACE;
}

\} {
  ADJUST();
  lastTokenType = RBRACE;
  return RBRACE;
}

\+\+ {
  ADJUST();
  lastTokenType = INC;
  return INC;
}

-- {
  ADJUST();
  lastTokenType = DEC;
  return DEC;
}

\> {
  ADJUST();
  lastTokenType = GT;
  return GT;
}

\< {
  ADJUST();
  lastTokenType = LT;
  return LT;
}

\>\= {
  ADJUST();
  lastTokenType = GE;
  return GE;
}

\<\= {
  ADJUST();
  lastTokenType = LE;
  return LE;
}

== {
  ADJUST();
  lastTokenType = EQ;
  return EQ;
}

!= {
  ADJUST();
  lastTokenType = NE;
  return NE;
}

if {
  ADJUST();
  lastTokenType = IF;
  return IF;
}

for {
  ADJUST();
  lastTokenType = FOR;
  return FOR;
}

else {
  ADJUST();
  lastTokenType = ELSE;
  return ELSE;
}

var {
  ADJUST();
  lastTokenType = VAR;
  return VAR;
}

return {
  ADJUST();
  lastTokenType = RETURN;
  return RETURN;
}

int {
  ADJUST();
  lastTokenType = INT;
  return INT;
}

bool {
  ADJUST();
  lastTokenType = BOOL;
  return BOOL;
}

func {
  ADJUST();
  lastTokenType = FUNC;
  return FUNC;
}

{bool_lit} {
  ADJUST();
  lastTokenType = BOOLLITERAL;
  char* s = (char*) malloc(yyleng+1);
  strcpy(s, yytext);
  yylval.id = s;
  return BOOLLITERAL;
}

{decimal_lit} {
  ADJUST();
  lastTokenType = INTLITERAL;
  char* s = (char*) malloc(yyleng+1);
  strcpy(s, yytext);
  yylval.id = s;
  return INTLITERAL;
}

{identifier} {
  ADJUST();
  lastTokenType = IDENTIFIER;
  char* s = (char*) malloc(yyleng+1);
  strcpy(s, yytext);
  yylval.id = s;
  return IDENTIFIER;
}

{whitespace} {
  ADJUST();
}

.      {
  ADJUST();
  if (yytext[0] < ' '){ /* non-printable char */
    /*yyerror*/ fprintf(stderr,"illegal character: ^%c",yytext[0] + '@'); 
  }
  else {
    if (yytext[0] > '~') {
      /* non-printable char printed as octal int padded with zeros, eg \012*/
      /*yyerror(*/fprintf(stderr,"illegal character: \\%03o", (int) yytext[0]);
    }
    else {
      /*yyerror(*/fprintf(stderr,"illegal character: %s",yytext);
    }
  }
  /* lex read exactly one char; the illegal one */
  fprintf(stderr," at line %d column %d\n", line_nr, col_nr);
			       }
%%

/* Function called by (f)lex when EOF is read. If yywrap returns a
   true (non-zero) (f)lex will terminate and continue otherwise.*/
int yywrap(){
  return (1);
}
