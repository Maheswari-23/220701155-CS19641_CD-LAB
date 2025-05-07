%{
#include "y.tab.h"
%}

%option noyywrap

%%

[0-9]+      { yylval = atoi(yytext); return NUMBER; }
[+]         { return PLUS; }
[*]         { return MUL; }
[\n]        { return EOL; }
[ \t]       { /* ignore whitespace */ }

.           { printf("Invalid character: %s\n", yytext); }

%%
