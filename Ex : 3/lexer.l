%{
#include <stdio.h>
#include <string.h>

// List of C keywords
char *keywords[] = {
  "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
  "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register",
  "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
  "union", "unsigned", "void", "volatile", "while"
};

int isKeyword(char *word) {
  for (int i = 0; i < sizeof(keywords)/sizeof(keywords[0]); i++) {
    if (strcmp(word, keywords[i]) == 0)
      return 1;
  }
  return 0;
}
%}

%option noyywrap

DIGIT      [0-9]
ID         [a-zA-Z_][a-zA-Z0-9_]*
COMMENT1   \/\/.*             // single-line
COMMENT2   \/\*([^*]|\*+[^*/])*\*+\/
OPERATOR   (\+|\-|\*|\/|==|=|!=|<=|>=|<|>)
DELIM      [\[\]{}();,]

%%

{COMMENT1}     { printf("[Comment]         : %s\n", yytext); }
{COMMENT2}     { printf("[Comment]         : %s\n", yytext); }
{ID}           {
                  if (isKeyword(yytext))
                    printf("[Keyword]         : %s\n", yytext);
                  else
                    printf("[Identifier]      : %s\n", yytext);
               }
{DIGIT}+       { printf("[Constant]        : %s\n", yytext); }
{OPERATOR}     { printf("[Operator]        : %s\n", yytext); }
{DELIM}        { printf("[Delimiter]       : %s\n", yytext); }
[\n\t ]         ;   // skip whitespace
.              { printf("[Unknown Symbol]  : %s\n", yytext); }

%%

int main() {
    printf("Enter C code (Ctrl+D to end):\n");
    yylex();
    return 0;
}
