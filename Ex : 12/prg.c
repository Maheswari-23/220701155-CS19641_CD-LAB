#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char lhs[10];
    char rhs1[10];
    char rhs2[10];
    char op;
    int isCopy; // 1 if it's a copy like t1 = t2
} Instruction;

Instruction code[MAX];
int n;

void inputCode() {
    printf("Enter number of TAC lines: ");
    scanf("%d", &n);
    printf("Enter TAC (e.g., t1 = a or t3 = t1 + b):\n");

    for (int i = 0; i < n; i++) {
        char equal;
        scanf("%s %c %s", code[i].lhs, &equal, code[i].rhs1);

        if (getchar() != '\n') {
            scanf(" %c %s", &code[i].op, code[i].rhs2);
            code[i].isCopy = 0;
        } else {
            code[i].rhs2[0] = '\0';
            code[i].op = '\0';
            code[i].isCopy = 1;
        }
    }
}

void applyCopyPropagation() {
    for (int i = 0; i < n; i++) {
        if (!code[i].isCopy) {
            for (int j = i - 1; j >= 0; j--) {
                // Replace rhs1
                if (strcmp(code[i].rhs1, code[j].lhs) == 0 && code[j].isCopy) {
                    strcpy(code[i].rhs1, code[j].rhs1);
                    break;
                }
            }
            for (int j = i - 1; j >= 0; j--) {
                // Replace rhs2
                if (strcmp(code[i].rhs2, code[j].lhs) == 0 && code[j].isCopy) {
                    strcpy(code[i].rhs2, code[j].rhs1);
                    break;
                }
            }
        }
    }
}

void printOptimizedCode() {
    printf("\nOptimized Code with Copy Propagation:\n");
    for (int i = 0; i < n; i++) {
        if (code[i].isCopy)
            printf("%s = %s\n", code[i].lhs, code[i].rhs1);
        else
            printf("%s = %s %c %s\n", code[i].lhs, code[i].rhs1, code[i].op, code[i].rhs2);
    }
}

int main() {
    inputCode();
    applyCopyPropagation();
    printOptimizedCode();
    return 0;
}
