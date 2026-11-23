#include <stdio.h>

struct Order {
    int id;
    char customer[50];
    float amount;
    char status; /* 'P' for Pending, 'D' for Discounted/Delivered */
};

void tryDiscountByValue(struct Order ord) {
    if (ord.amount >= 2000.0f) {
        ord.amount = ord.amount * 0.90f;
        ord.status = 'D';
    }
}

void applyDiscountByPointer(struct Order *ord) {
    if (ord->amount >= 2000.0f) {
        ord->amount = ord->amount * 0.90f;
        ord->status = 'D';
    }
}

int main() {
    struct Order orders[3] = {
        {1501, "Hamza", 2500.00f, 'P'},
        {1502, "Ayesha", 1800.00f, 'P'},
        {1503, "Bilal", 3200.00f, 'P'}
    };

    /* Demonstrate pass-by-value does not change original amount */
    tryDiscountByValue(orders[0]);
    printf("After tryDiscount: %.2f\n", orders[0].amount);

    float total = 0.0f;
    for (int i = 0; i < 3; i++) {
        applyDiscountByPointer(&orders[i]);
        total += orders[i].amount;
        printf("%d | %s | Rs %.2f | %c\n",
               orders[i].id,
               orders[i].customer,
               orders[i].amount,
               orders[i].status);
    }

    printf("Total: Rs %.2f\n", total);

    return 0;
}
