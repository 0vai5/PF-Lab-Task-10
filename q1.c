#include <stdio.h>

void printReverse(int n) {
    if (n == 0)
        return;
    printf("%d", n % 10);
    printReverse(n / 10);
}

int sumEvenDigits(int n) {
    if (n == 0)
        return 0;
    int lastDigit = n % 10;
    if (lastDigit % 2 == 0)
        return lastDigit + sumEvenDigits(n / 10);
    else
        return sumEvenDigits(n / 10);
}

int main() {
    int roll;
    printf("Enter roll number: ");
    scanf("%d", &roll);

    printf("Locker code: ");
    if (roll == 0) {
        printf("0");
    } else {
        if (roll < 0) {
            printf("-");
            roll = -roll;
        }
        printReverse(roll);
    }
    printf("\n");

    int evenSum = sumEvenDigits(roll < 0 ? -roll : roll);
    printf("Even-digit checksum: %d\n", evenSum);

    return 0;
}
