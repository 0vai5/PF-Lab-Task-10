#include <stdio.h>

int isOdd(int n);

int isEven(int n) {
    printf("isEven (%d)", n);
    if (n == 0)
        return 1;
    printf(" -> ");
    if (n > 0)
        return isOdd(n - 1);
    else
        return isOdd(n + 1);
}

int isOdd(int n) {
    printf("isOdd (%d)", n);
    if (n == 0)
        return 0;
    printf(" -> ");
    if (n > 0)
        return isEven(n - 1);
    else
        return isEven(n + 1);
}

int main() {
    int sec;
    printf("Enter second: ");
    scanf("%d", &sec);

    int evenResult = isEven(sec);
    printf("\n");

    if (evenResult)
        printf("Second %d: GREEN\n", sec);
    else
        printf("Second %d: RED\n", sec);

    return 0;
}
