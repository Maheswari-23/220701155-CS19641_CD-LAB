#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char lhs[10];
    char op1[10];
    char op2[10];
    char operator;
    int isUsed;
} Instruction;

Instruction code[MAX];
int count = 0;

int isSameExpr(Instruction a, Instruction b) {
    return (a.operator == b.operator &&
            strcmp(a.op1, b.op1) == 0 &&
            strcmp(a.op2, b.op2) == 0);
}

int findExpr(char *op1, char op, char *op2) {
    for (int i = 0; i < count; i++) {
        if (code[i].operator == op &&
            strcmp(code[i].op1, op1) == 0 &&
            strcmp(code[i].op2, op2) == 0) {
            return i;
        }
    }
    return -1;
}

void markUsed(char *var) {
    for (int i = 0; i < count; i++) {
        if (strcmp(code[i].op1, var) == 0 || strcmp(code[i].op2, var) == 0) {
            code[i].isUsed = 1;
            markUsed(code[i].lhs);  // Recursive check
        }
    }
}

void inputCode() {
    printf("Enter number of lines of TAC: ");
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        char eq, op;
        scanf("%s %c %s %c %s", code[i].lhs, &eq, code[i].op1, &op, code[i].op2);
        code[i].operator = op;
        code[i].isUsed = 0;
    }
}

void optimizeCode() {
    // Step 1: Common Subexpression Elimination
    for (int i = 0; i < count; i++) {
        int idx = findExpr(code[i].op1, code[i].operator, code[i].op2);
        if (idx != -1 && idx != i) {
            strcpy(code[i].op1, code[idx].lhs);
            strcpy(code[i].op2, "");
            code[i].operator = '=';
        }
    }

    // Step 2: Dead Code Elimination (only keep used results)
    char resultVar[10];
    printf("Enter the final result variable (e.g., x): ");
    scanf("%s", resultVar);
    markUsed(resultVar);
}

void printOptimizedCode() {
    printf("\nOptimized Code:\n");
    for (int i = 0; i < count; i++) {
        if (code[i].isUsed || strcmp(code[i].lhs, "x") == 0) {
            if (code[i].operator == '=')
                printf("%s = %s\n", code[i].lhs, code[i].op1);
            else
                printf("%s = %s %c %s\n", code[i].lhs, code[i].op1, code[i].operator, code[i].op2);
        }
    }
}

int main() {
    inputCode();
    optimizeCode();
    printOptimizedCode();
    return 0;
}
