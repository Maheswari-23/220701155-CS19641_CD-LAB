#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[1000], str2[1000], result[1000];
    int choice;

    printf("String Operations Menu:\n");
    printf("1. Convert to Uppercase\n");
    printf("2. Check Substring (without strstr)\n");
    printf("3. Compare Two Strings\n");
    printf("4. Remove Spaces\n");
    printf("5. Frequency of Characters\n");
    printf("6. Concatenate Strings\n");
    printf("7. Replace Character\n");
    printf("Enter your choice (1-7): ");
    scanf("%d", &choice);
    getchar();  // consume newline

    switch (choice) {
        case 1: {
            printf("Enter a string: ");
            fgets(str, sizeof(str), stdin);
            for (int i = 0; str[i]; i++)
                str[i] = toupper(str[i]);
            printf("Uppercase: %s", str);
            break;
        }

        case 2: {
            char substr[100];
            int found = 0;
            printf("Enter main string: ");
            fgets(str, sizeof(str), stdin);
            printf("Enter substring to search: ");
            fgets(substr, sizeof(substr), stdin);

            // Remove newline characters
            str[strcspn(str, "\n")] = 0;
            substr[strcspn(substr, "\n")] = 0;

            int len1 = strlen(str);
            int len2 = strlen(substr);

            for (int i = 0; i <= len1 - len2; i++) {
                if (strncmp(&str[i], substr, len2) == 0) {
                    printf("Substring found at index %d\n", i);
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Substring not found.\n");
            break;
        }

        case 3: {
            printf("Enter first string: ");
            fgets(str, sizeof(str), stdin);
            printf("Enter second string: ");
            fgets(str2, sizeof(str2), stdin);

            str[strcspn(str, "\n")] = 0;
            str2[strcspn(str2, "\n")] = 0;

            if (strcmp(str, str2) == 0)
                printf("Strings are the same.\n");
            else
                printf("Strings are different.\n");
            break;
        }

        case 4: {
            printf("Enter a string: ");
            fgets(str, sizeof(str), stdin);
            int j = 0;
            for (int i = 0; str[i]; i++) {
                if (str[i] != ' ')
                    result[j++] = str[i];
            }
            result[j] = '\0';
            printf("String without spaces: %s\n", result);
            break;
        }

        case 5: {
            printf("Enter a string: ");
            fgets(str, sizeof(str), stdin);
            int freq[256] = {0};

            for (int i = 0; str[i]; i++)
                freq[(unsigned char)str[i]]++;

            printf("Character frequencies:\n");
            for (int i = 0; i < 256; i++) {
                if (freq[i] > 0)
                    printf("'%c': %d\n", i, freq[i]);
            }
            break;
        }

        case 6: {
            printf("Enter first string: ");
            fgets(str, sizeof(str), stdin);
            printf("Enter second string: ");
            fgets(str2, sizeof(str2), stdin);

            str[strcspn(str, "\n")] = 0;
            str2[strcspn(str2, "\n")] = 0;

            strcat(str, str2);
            printf("Concatenated string: %s\n", str);
            break;
        }

        case 7: {
            char oldChar, newChar;
            printf("Enter a string: ");
            fgets(str, sizeof(str), stdin);
            printf("Enter character to replace: ");
            scanf(" %c", &oldChar);
            printf("Enter replacement character: ");
            scanf(" %c", &newChar);

            for (int i = 0; str[i]; i++) {
                if (str[i] == oldChar)
                    str[i] = newChar;
            }
            printf("Modified string: %s\n", str);
            break;
        }

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
