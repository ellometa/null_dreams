#include <stdio.h>
#include <string.h>
int main() {
    
    printf("\nEnter input you want:\n1. Compare two strings lengths.\n2. Copy one string to another.\n3Concatenate two strings.\n4. Compare two strings for equality.\n5. Reverse a given string.\n");

    int input = 0;
    scanf("%d", &input);

    switch (input) {
        case 1: {
            char name[100], name2[100];
            printf("\nEnter your first string: ");
            fgets(name, sizeof(name), stdin);

            printf("\nEnter your second string: ");
            fgets(name2, sizeof(name2), stdin);

            int len1 = strlen(name), len2 = strlen(name2);
            if (len1 > len2) {
                printf("\n%s with length %ld is greater than %s with length %ld", name, len1, name2, len2);
            } else if (len1 < len2) {
                printf("\n%s with length %ld is greater than %s with length %ld", name2, len2, name, len1);
            } else {
                printf("\n%s with length %ld is equal to %s with length %ld", name, len1, name2, len2);
            }
            break;
        }
        case 2: {
            char original[100], Cpy[100];
            printf("\nEnter string you want copied: ");
            fgets(original, sizeof(original), stdin);

            strcpy(Cpy, original);
            printf("\nCopied string: %s", Cpy);
            break;
        }
        case 3: {
            char cat1[100], cat2[100];
            printf("\nEnter your first string: ");
            fgets(cat1, sizeof(cat1), stdin);

            printf("\nEnter your second string: ");
            fgets(cat2, sizeof(cat2), stdin);

            strcat(cat1, cat2);
            printf("\nConcatenated string: %s", cat1);
            break;
        }
        case 4: {
            char c1[100], c2[100];
            printf("\nEnter your first string: ");
            fgets(c1, sizeof(c1), stdin);

            printf("\nEnter your second string: ");
            fgets(c2, sizeof(c2), stdin);

            if (strcmp(c1, c2) == 0) {
                printf("\nStrings are equal.");
            } else {
                printf("\nStrings are not equal.");
            }
            break;
        }
        case 5: {
            char rev[100];
            printf("\nEnter a string to reverse: ");
            fgets(rev, sizeof(rev), stdin);

            strrev(rev);
            printf("\nReversed String: %s", rev);
            break;
        }
    }

    return 0;
}


