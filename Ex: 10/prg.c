#include <stdio.h>
#include <string.h>

int tempCount = 1;

void generateTAC(char *lhs, char *rhs) {
    char op1[10], op2[10], op, t1[10], t2[10];
    // Supports expressions like: a = b + c
    if (sscanf(rhs, "%s %c %s", op1, &op, op2) == 3) {
        sprintf(t1, "t%d", tempCount++);
        printf("%s = %s %c %s\n", t1, op1, op, op2);
        printf("%s = %s\n", lhs, t1);
    } else {
        printf("%s = %s\n", lhs, rhs);
    }
}

int main() {
    char lhs[10], rhs[50];
    printf("Enter expression (e.g., a = b + c): ");
    scanf("%s = %[^\n]", lhs, rhs);
    generateTAC(lhs, rhs);
    return 0;
}
