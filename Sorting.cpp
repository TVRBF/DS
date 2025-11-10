#include <stdio.h>

int main() {
    int n, i, j, key;

    // Input number of products
    printf("Enter number of products: ");
    scanf("%d", &n);

    int price[n];

    // Input prices
    printf("Enter prices of products:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }

    // Insertion Sort Algorithm (Ascending Order)
    for (i = 1; i < n; i++) {
        key = price[i];
        j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && price[j] > key) {
            price[j + 1] = price[j];
            j--;
        }
        price[j + 1] = key;
    }

    // Display sorted prices (ascending)
    printf("\nSorted prices in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", price[i]);
    }

    // Display sorted prices (descending)
    printf("\n\nSorted prices in descending order:\n");
    for (i = n - 1; i >= 0; i--) {
        printf("%d ", price[i]);
    }

    printf("\n");
    return 0;
}
