#include <stdio.h>

extern FILE *yyin;
extern int yyparse();

/* Array with tokens such that index = tokenid - 250*/
// char *tokens[] = {
// "SEMICOLON",
// "IDENTIFIER",
// "INT", "BOOL",
// "PACKAGE", "RETURN", "VAR", "IF", "FOR",
// "LPAREN", "RPAREN", "LBRACE", "RBRACE",
// "PLUS", "MIN", "MUL", "DIV", 
// "PLUSASSIGN", "MINASSIGN", "MULASSIGN", "DIVASSIGN",
// "AND", "OR", "NOT",
// "INC", "DEC",
// "GT", "GE", "LT", "LE", "EQ", "NE",
// "INTLITERAL", "BOOLLITERAL", "ASSIGN", "FUNC"
// }; 

int main(int argc, char* argv[])
{
  
  // int tokenid;
  yyin = fopen("testMain.go", "r");
  
  // /* If we de not explicitly bind yyin to a file, stdin is assumed. */
  // while (tokenid=yylex()){
  //   /* Token codes start from 250 */ 
  //   printf(" %s", tokens[tokenid-250]);

  //   /* Append value */
  //   if ( (tokenid == IDENTIFIER) || (tokenid == INTLITERAL) || (tokenid == BOOLLITERAL) ) 
  //     printf("=\"%s\"", yytext);
  //   printf("\n");
  // }
  // return 0;
  yyparse();
  return 0;
}
