%{
#include <stdio.h>
#include <stdlib.h>
%}

%token IF ELSE FOR WHILE SWITCH CASE DEFAULT BREAK
%token IDENTIFIER NUMBER OP
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON COLON

%%

program:
    statements
    ;

statements:
    statement
    | statements statement
    ;

statement:
    if_stmt
    | for_stmt
    | while_stmt
    | switch_stmt
    ;

if_stmt:
    IF LPAREN condition RPAREN block else_part
    ;

else_part:
    /* empty */
    | ELSE block
    | ELSE if_stmt
    ;

for_stmt:
    FOR LPAREN expr SEMICOLON condition SEMICOLON expr RPAREN block
    ;

while_stmt:
    WHILE LPAREN condition RPAREN block
    ;

switch_stmt:
    SWITCH LPAREN IDENTIFIER RPAREN LBRACE case_list default_case RBRACE
    ;

case_list:
    /* empty */
    | case_list CASE NUMBER COLON statements BREAK SEMICOLON
    ;

default_case:
    /* empty */
    | DEFAULT COLON statements
    ;

condition:
    expr OP expr
    ;

expr:
    IDENTIFIER
    | NUMBER
    ;

block:
    LBRACE statements RBRACE
    ;

%%

int main() {
    printf("Enter control structure code:\n");
    yyparse();
    printf("Syntax is valid.\n");
    return 0;
}

int yyerror(char *s) {
    fprintf(stderr, "Syntax error: %s\n", s);
    exit(1);
}
