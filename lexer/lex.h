#define EOI 0
#define PLUS 1
#define MINUS 2
#define NUM_OR_ID 3

extern char *yytext;    //-- In lex.c
extern int yyleng;      //||
extern int yylineno;    //--

int lex(void);
int match(int token);
void advance(void);
