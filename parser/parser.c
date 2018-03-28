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
  term();
  rest();
}

void rest(void)
{
  if (match(EOI))
    return;
  else if (match(PLUS) || match(MINUS))
  {
  	advance();
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
