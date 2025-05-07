%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tempCount = 0;

char* newTemp() {
    char* temp = (char*) malloc(10);
    sprintf(temp, "t%d", tempCount++);
    return temp;
}

void emit(char* res, char* op1, char op, char* op2) {
    printf("%s = %s %c %s\n", res, op1, op, op2);
}

void emitAssign(char* res, char* val) {
    printf("%s = %s\n", res, val);
}

%}

%union {
    char* str;
}

%token <str> ID NUM
%type <str> expr

%%

stmt:
    ID '=' expr ';' {
        emitAssign($1, $3);
    }
    ;

expr:
    expr '+' expr {
        char* temp = newTemp();
        emit(temp, $1, '+', $3);
        $$ = temp;
    }
    | expr '-' expr {
        char* temp = newTemp();
        emit(temp, $1, '-', $3);
        $$ = temp;
    }
    | expr '*' expr {
        char* temp = newTemp();
        emit(temp, $1, '*', $3);
        $$ = temp;
    }
    | expr '/' expr {
        char* temp = newTemp();
        emit(temp, $1, '/', $3);
        $$ = temp;
    }
    | ID { $$ = $1; }
    | NUM { $$ = $1; }
    ;

%%

int main() {
    printf("Enter an expression (e.g., a = b + c * d;):\n");
    yyparse();
    return 0;
}

int yyerror(char* s) {
    fprintf(stderr, "Syntax error: %s\n", s);
    return 1;
}
