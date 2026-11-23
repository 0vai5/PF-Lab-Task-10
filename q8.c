#include <stdio.h>

const char *TOKEN_PREFIX = "FST-";

int nextToken(void) {
    static int currentToken = 1001;
    return currentToken++;
}

int main() {
    char names[3][100];

    for (int i = 0; i < 3; i++) {
        printf("Enter customer name: ");
        scanf("%99s", names[i]);
    }

    for (int i = 0; i < 3; i++) {
        int token = nextToken();
        printf("%s -> %s%d\n", names[i], TOKEN_PREFIX, token);
    }

    return 0;
}
