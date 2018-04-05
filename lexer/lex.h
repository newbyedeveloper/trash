#define EOI 0			// End of Input
#define PLUS 1			// +
#define MINUS 2			// -
#define NUM 3			// Single Digit

extern char *yytext;    //-- In lex.c
extern int yyleng;      //||
extern int yylineno;    //--

int lex(void);
int match(int token);
void advance(void);
