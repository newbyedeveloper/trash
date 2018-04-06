#include <stdio.h>
#include <string.h>
#include "../lexer/lex.h"

//Grammar in grammar.txt

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
  char op;

  while (match(PLUS) || match(MINUS))
  {
    op = *yytext;
    advance();
    term();
    printf("%c ", op);
  }
}

void term(void)
{
  char number[yyleng+1];

  if (match(NUM))
  {
    memcpy(number, yytext, yyleng);
    number[yyleng] = '\0';
    advance();
    printf("%s ", number);
  }
  else
    puts("Expected number");
}
