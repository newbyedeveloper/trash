#include <stdio.h>
#include "../lexer/lex.h"

/*    
	expr ::= term rest
	rest ::= + expr | - expr | &
	term ::= NUM_OR_ID 
*/

void expr(void);
void rest(void);
void term(void);

void expr(void)
{
  while (!match(EOI))
  {
	term();
    rest();
  }
}

void rest(void)
{
  if (match(PLUS) || match(MINUS))
  {
	advance();
    /*if (!match(NUM_OR_ID))
      puts("Expected number or identifier");
    else
      printf("%2.*s", yytext, yyleng);
    */
	expr();
  }  
}

void term(void)
{
  if (match(NUM_OR_ID))
  {
	advance();
  }
  else
    puts("Expected number or identifier");
}
