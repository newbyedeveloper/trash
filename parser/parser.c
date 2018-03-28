#include <stdio.h>
#include "../lexer/lex.h"

void expr(void);
void term(void);

void expr(void)
{
  char op;

  term();
  if (match(MINUS))
    op = '-';
  else if (match(PLUS))
    op = '+';

  if (match(PLUS) || match(MINUS))
    advance();
  else
    return;

  expr();

  printf(" %c", op);
}

void term(void)
{
  if (match(NUM_OR_ID))
  {
    printf(" %c", *yytext);
    advance();
  }
  else
    puts("Expected number or identifier");
}
