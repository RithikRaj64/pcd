#include<stdio.h>
#include<string.h>

#define MAX_EXPRESSIONS 20
#define MAX_LENGTH 20

struct Expression {
    char left[MAX_LENGTH];
    char right[MAX_LENGTH];
    int flag;
};

int main() {
    struct Expression expressions[MAX_EXPRESSIONS];
    int i, j, n, found, hasCommonSubexpression;

    printf("Enter total number of expressions: ");
    scanf("%d", &n);

    printf("\nEnter L, R values:\n");
    for (i = 0; i < n; i++) {
        printf("\nLeft  : ");
        scanf("%s", expressions[i].left);
        printf("Right : ");
        scanf("%s", expressions[i].right);
        expressions[i].flag = 0;
    }

    printf("\nIntermediate code:");
    for (i = 0; i < n; i++) 
        printf("\n%s=%s", expressions[i].left, expressions[i].right);

    printf("\n\nAfter dead code elimination:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (strstr(expressions[j].right, expressions[i].left)) {
                expressions[i].flag = 1;
                break;
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (expressions[i].flag == 1) 
            printf("%s=%s\n", expressions[i].left, expressions[i].right);
    }

    printf("\nCommon Sub Expressions:\n");
    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < i; j++) {
            if (strcmp(expressions[i].right, expressions[j].right) == 0) {
                printf("%s=%s\n%s=%s\n", expressions[j].left, expressions[j].right, expressions[i].left, expressions[i].right);
                found = 1;
                break;
            }
        }
    }

    printf("\nAfter eliminating common sub-expressions:\n");
    for (i = 0; i < n; i++) {
        hasCommonSubexpression = 0;
        for (j = 0; j < i; j++) {
            if (strcmp(expressions[i].right, expressions[j].right) == 0) {
                hasCommonSubexpression = 1;
                break;
            }
        }
        if (!hasCommonSubexpression && expressions[i].flag) 
            printf("%s=%s\n", expressions[i].left, expressions[i].right);
    }

    return 0;
}
