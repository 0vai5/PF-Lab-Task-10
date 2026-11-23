#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isMirrorRecursive(const char *s, int left, int right) {
    while (left < right && !isalnum((unsigned char)s[left])) {
        left++;
    }
    while (left < right && !isalnum((unsigned char)s[right])) {
        right--;
    }
    if (left >= right) {
        return 1;
    }
    if (tolower((unsigned char)s[left]) != tolower((unsigned char)s[right])) {
        return 0;
    }
    return isMirrorRecursive(s, left + 1, right - 1);
}

int main() {
    char code[200];

    printf("Enter code: ");
    if (fgets(code, sizeof(code), stdin) != NULL) {
        size_t len = strlen(code);
        if (len > 0 && code[len - 1] == '\n') {
            code[len - 1] = '\0';
        }

        if (isMirrorRecursive(code, 0, (int)strlen(code) - 1)) {
            printf("MIRROR CODE\n");
        } else {
            printf("Normal box\n");
        }
    }

    return 0;
}
