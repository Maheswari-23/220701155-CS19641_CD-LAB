%{
#include <stdio.h>
#include <stdlib.h>
#include "lex.yy.c"
%}

%token VARIABLE

%%

start:  VARIABLE { 
            printf("Valid Variable: %s\n", yytext); 
        }
      | . { printf("Not a valid variable.\n"); exit(1); }
      ;

%%

int main() {
    printf("Enter a valid C variable: ");
    yyparse();
    return 0;
}

int yywrap() {
    return 1;
}
