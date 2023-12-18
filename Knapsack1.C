#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100

struct item {
    int id;
    int profit;
    int weight;
    float ratio;
};

int compare(const void* a, const void* b) {
    struct item* item1 = (struct item*) a;
    struct item* item2 = (struct item*) b;
    float ratio1 = item1->ratio;
    float ratio2 = item2->ratio;
    if (ratio1 < ratio2) {
        return 1;
    } else if (ratio1 > ratio2) {
        return -1;
    } else {
        return 0;
    }
}

void fractionalKnapsack(int n, int capacity, struct item items[]) {
    int i;
    float total_profit = 0.0;
    float fraction[MAX_N] = {0.0};

    for (i = 0; i < n; i++) {
        items[i].ratio = (float) items[i].profit / (float) items[i].weight;
    }

    qsort(items, n, sizeof(struct item), compare);

    for (i = 0; i < n; i++) {
        if (capacity == 0) {
            break;
        } else if (items[i].weight <= capacity) {
            fraction[items[i].id] = 1.0;
            total_profit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            fraction[items[i].id] = (float) capacity / (float) items[i].weight;
            total_profit += fraction[items[i].id] * items[i].profit;
            capacity = 0;
        }
    }

    printf("Selected items and their fractions:\n");
    for (i = 0; i < n; i++) {
        if (fraction[i] > 0.0) {
            printf("Item %d: %.2f\n", i, fraction[i]);
        }
    }
    printf("Maximum profit: %.2f\n", total_profit);
}

int main() {
    int n, capacity, i;
    struct item items[MAX_N];
    printf("\nHarsh Shetye_60009210068_Knapsack\n");

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the number of items: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the weight and profit of each item:\n");
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].id = i;
    }

    fractionalKnapsack(n, capacity, items);
    return 0;
}
