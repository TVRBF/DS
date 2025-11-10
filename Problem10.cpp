#include <stdio.h>

int main() {
    int n, i, j, temp;
    int swapped;

    // Input number of products
    printf("Enter number of products: ");
    scanf("%d", &n);

    int price[n];

    // Input prices
    printf("Enter prices of products:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }

    // Bubble Sort Algorithm (Ascending Order)
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (price[j] > price[j + 1]) {
                // Swap elements
                temp = price[j];
                price[j] = price[j + 1];
                price[j + 1] = temp;
                swapped = 1;
            }
        }

        // If no swaps were made in this pass, array is sorted
        if (swapped == 0)
            break;
    }

    // Display sorted prices
    printf("\nSorted prices in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", price[i]);
    }

    // Optional: Display in descending order too
    printf("\n\nSorted prices in descending order:\n");
    for (i = n - 1; i >= 0; i--) {
        printf("%d ", price[i]);
    }

    printf("\n");
    return 0;
}
