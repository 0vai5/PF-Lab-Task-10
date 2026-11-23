#include <stdio.h>

int climbStairs(int n) {
    static int calls = 0;
    calls++;
    if (n == 0 || n == 1)
        return 1;
    if (n < 0)
        return 0;
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int countCallsOnly(int n, int reset) {
    static int calls = 0;
    if (reset) {
        calls = 0;
        return 0;
    }
    calls++;
    if (n == 0 || n == 1)
        return 1;
    if (n < 0)
        return 0;
    return countCallsOnly(n - 1, 0) + countCallsOnly(n - 2, 0);
}

int getCalls(int n) {
    static int totalCalls = 0;
    totalCalls = 0;
    return totalCalls;
}

/* Clean solution matching the required output for n = 4, 5, 6 */
int waysToClimb(int n, int *callCount) {
    (*callCount)++;
    if (n == 0 || n == 1)
        return 1;
    if (n < 0)
        return 0;
    return waysToClimb(n - 1, callCount) + waysToClimb(n - 2, callCount);
}

void solveStaircase(int n) {
    static int dummy = 0;
    (void)dummy;
    int calls = 0;
    int ways = waysToClimb(n, &calls);
    printf("n=%d | ways = %d | calls = %d\n", n, ways, calls);
}

int main() {
    int ns[] = {4, 5, 6};
    for (int i = 0; i < 3; i++) {
        solveStaircase(ns[i]);
    }
    return 0;
}
