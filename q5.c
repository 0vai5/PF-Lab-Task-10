#include <stdio.h>
#include <string.h>

struct Batter {
    char name[50];
    int runs;
    int balls;
};

int main() {
    struct Batter batters[5] = {
        {"Babar", 78, 52},
        {"Rizwan", 45, 40},
        {"Fakhar", 0, 0},
        {"Shadab", 23, 9},
        {"Saim", 12, 15}
    };

    int teamTotal = 0;
    int topScorerIdx = 0;
    int bestSrIdx = -1;
    double bestSr = -1.0;

    for (int i = 0; i < 5; i++) {
        teamTotal += batters[i].runs;

        if (batters[i].runs > batters[topScorerIdx].runs) {
            topScorerIdx = i;
        }

        if (batters[i].balls == 0) {
            printf("%s | %d (%d) | SR: DNB\n", batters[i].name, batters[i].runs, batters[i].balls);
        } else {
            double sr = ((double)batters[i].runs * 100.0) / batters[i].balls;
            printf("%s | %d (%d) | SR: %.2f\n", batters[i].name, batters[i].runs, batters[i].balls, sr);
            if (bestSrIdx == -1 || sr > bestSr) {
                bestSr = sr;
                bestSrIdx = i;
            }
        }
    }

    printf("\nTeam total: %d\n", teamTotal);
    printf("Top scorer: %s (%d)\n", batters[topScorerIdx].name, batters[topScorerIdx].runs);
    if (bestSrIdx != -1) {
        printf("Best strike rate: %s (%.2f)\n", batters[bestSrIdx].name, bestSr);
    }

    return 0;
}
