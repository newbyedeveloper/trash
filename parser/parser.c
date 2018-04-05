#include <stdio.h>
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
    //putchar(op);
  }  
}

void term(void)
{
  char digit;
  
  if (match(NUM))
  {
    digit = *yytext;
    advance();
    printf("%c ", digit);
    //putchar(digit);    
  }
}