/* #include <stdio.h>
#include <stdlib.h>

void coinChange(int coins[], int n, int amount) {
    //coins must be sorted in descending order.
    printf("Coins used:\n");
    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            printf("%d ", coins[i]);
        }
    }
    printf("\n");
}

int main() {
    int coins[] = {25, 10, 5, 1}; // Coin denominations
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 49;

    coinChange(coins, n, amount);

    return 0;
} */