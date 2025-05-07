%{
#include "y.tab.h"
%}

%option noyywrap

%%

"if"                { return IF; }
"else"              { return ELSE; }
"for"               { return FOR; }
"while"             { return WHILE; }
"switch"            { return SWITCH; }
"case"              { return CASE; }
"default"           { return DEFAULT; }
"break"             { return BREAK; }

[a-zA-Z_][a-zA-Z0-9_]*    { return IDENTIFIER; }
[0-9]+                   { return NUMBER; }

"=="|"!="|"<="|">="|"&&"|"||"|"="|"+"|"-"|"*"|"/"|"<"|">" { return OP; }

"("         { return LPAREN; }
")"         { return RPAREN; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
";"         { return SEMICOLON; }
":"         { return COLON; }

[ \t\n]+    ;  // Ignore whitespace

.           { printf("Invalid character: %s\n", yytext); }

%%
