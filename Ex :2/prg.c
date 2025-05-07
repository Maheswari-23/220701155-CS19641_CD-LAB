#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

const char *keywords[] = {
    "auto","break","case","char","const","continue","default","do","double","else",
    "enum","extern","float","for","goto","if","int","long","register","return",
    "short","signed","sizeof","static","struct","switch","typedef","union",
    "unsigned","void","volatile","while"
};

const char operators[] = "+-*/%=<>&|^!";
const char delimiters[] = " ,;\t\n";
const char specialSymbols[] = "(){}[]#\"";

int isKeyword(char *word) {
    for (int i = 0; i < sizeof(keywords)/sizeof(keywords[0]); i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch) {
    return strchr(operators, ch) != NULL;
}

int isDelimiter(char ch) {
    return strchr(delimiters, ch) != NULL;
}

int isSpecialSymbol(char ch) {
    return strchr(specialSymbols, ch) != NULL;
}

int main() {
    char code[1000];
    printf("Enter a C code snippet (end with $):\n");

    // Read until $ is encountered
    char ch;
    int i = 0;
    while ((ch = getchar()) != '$') {
        code[i++] = ch;
    }
    code[i] = '\0';

    printf("\n--- Token Analysis ---\n");

    char token[100];
    int j = 0;

    for (i = 0; code[i] != '\0'; i++) {
        ch = code[i];

        if (isDelimiter(ch) || isOperator(ch) || isSpecialSymbol(ch)) {
            if (j != 0) {
                token[j] = '\0';
                if (isKeyword(token))
                    printf("[Keyword]        : %s\n", token);
                else
                    printf("[Identifier]     : %s\n", token);
                j = 0;
            }

            if (isOperator(ch))
                printf("[Operator]       : %c\n", ch);
            else if (isSpecialSymbol(ch))
                printf("[Special Symbol] : %c\n", ch);
            else if (ch == ';' || ch == ',' || ch == '{' || ch == '}')
                printf("[Delimiter]      : %c\n", ch);
        } else if (!isspace(ch)) {
            token[j++] = ch;
        }
    }

    return 0;
}
