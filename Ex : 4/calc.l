%{
#include <stdio.h>
#include <stdlib.h>

double result;  // To hold the result of the expression

// Function to evaluate arithmetic operations
double evaluate(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}
%}

%option noyywrap

%%

[0-9]+(\.[0-9]+)?  { result = atof(yytext); printf("Number: %s\n", yytext); }

"+"|"-"|"*"|"/"    { printf("Operator: %s\n", yytext); }

"("                { printf("Left Parenthesis\n"); }

")"                { printf("Right Parenthesis\n"); }

[ \t\n]            { /* Ignore whitespaces */ }

.                  { printf("Unknown symbol: %s\n", yytext); }

%%

int main() {
    printf("Enter an expression (e.g., 3 + 4 * 5):\n");
    printf("Press Ctrl+D to exit.\n");
    
    yylex();  // Tokenize input and process

    printf("\nResult: %lf\n", result);  // Output result
    
    return 0;
}
