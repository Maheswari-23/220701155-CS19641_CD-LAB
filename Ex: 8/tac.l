%{
#include "y.tab.h"
%}

%option noyywrap

%%

[ \t\n]                ;   // Skip whitespace
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return ID; }
[0-9]+                { yylval.str = strdup(yytext); return NUM; }

"="                   { return '='; }
"+"                   { return '+'; }
"-"                   { return '-'; }
"*"                   { return '*'; }
"/"                   { return '/'; }
";"                   { return ';'; }

.                     { printf("Invalid character: %s\n", yytext); }

%%
