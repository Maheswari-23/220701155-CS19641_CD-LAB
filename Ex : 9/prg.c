#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void generateAssembly(char* line) {
    char result[10], op1[10], op2[10], eq, op;
    if (sscanf(line, "%s = %s %c %s", result, op1, &op, op2) == 4) {
        printf("MOV AX, %s\n", op1);
        switch (op) {
            case '+': printf("ADD AX, %s\n", op2); break;
            case '-': printf("SUB AX, %s\n", op2); break;
            case '*': printf("MUL %s\n", op2); break;
            case '/': printf("DIV %s\n", op2); break;
        }
        printf("MOV %s, AX\n", result);
    } else if (sscanf(line, "%s = %s", result, op1) == 2) {
        printf("MOV AX, %s\n", op1);
        printf("MOV %s, AX\n", result);
    } else {
        printf("; Unrecognized instruction: %s\n", line);
    }
}

int main() {
    char line[100];
    printf("Enter TAC lines (Ctrl+D to end input):\n");
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = '\0';  // Remove newline
        if (strlen(line) > 0)
            generateAssembly(line);
    }
    return 0;
}
