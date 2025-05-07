%{
#include <stdio.h>
#include <string.h>

int yylval;
%}

%option noyywrap

VARIABLE [a-zA-Z_][a-zA-Z0-9_]*  // Pattern for a valid variable

%%

{VARIABLE}   { yylval = 1; return VARIABLE; }  // Recognize the variable and return token
[ \t\n]      { /* Ignore whitespaces */ }
.            { printf("Invalid character: %s\n", yytext); return 0; }

%%

int main() {
    printf("Enter a variable: ");
    yylex();
    return 0;
}
