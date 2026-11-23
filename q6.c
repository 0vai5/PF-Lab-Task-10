#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Member {
    char name[50];
    int id;
};

struct Book {
    char title[60];
    struct Member member;
    struct Date dueDate;
    struct Date returnDate;
};

long toDays(struct Date d) {
    return (long)d.year * 360L + (long)d.month * 30L + (long)d.day;
}

int main() {
    const int FINE_PER_DAY = 20;

    struct Book books[4] = {
        {"C Programming", {"Ali", 101}, {10, 11, 2026}, {15, 11, 2026}},
        {"Data Structures", {"Sara", 102}, {28, 11, 2026}, {2, 12, 2026}},
        {"Discrete Math", {"Usman", 103}, {20, 12, 2026}, {18, 12, 2026}},
        {"Calculus", {"Hira", 104}, {29, 12, 2026}, {3, 1, 2027}}
    };

    long totalFine = 0;

    for (int i = 0; i < 4; i++) {
        long dueTotal = toDays(books[i].dueDate);
        long retTotal = toDays(books[i].returnDate);
        long lateDays = retTotal - dueTotal;

        if (lateDays < 0) {
            lateDays = 0;
        }

        long fine = lateDays * FINE_PER_DAY;
        totalFine += fine;

        printf("%s (%d) | %s | Late: %ld days | Fine: Rs %ld\n",
               books[i].member.name,
               books[i].member.id,
               books[i].title,
               lateDays,
               fine);
    }

    printf("\nTotal fine collected: Rs %ld\n", totalFine);

    return 0;
}
