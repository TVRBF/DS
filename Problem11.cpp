#include <stdio.h>

int main() {
    int n, i, j, minIndex, temp;

    // Input number of products
    printf("Enter number of products: ");
    scanf("%d", &n);

    int price[n];

    // Input prices
    printf("Enter prices of products:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }

    // Selection Sort algorithm (Ascending Order)
    for (i = 0; i < n - 1; i++) {
        minIndex = i; // Assume current index has the minimum value

        for (j = i + 1; j < n; j++) {
            if (price[j] < price[minIndex]) {
                minIndex = j; // Update minimum index
            }
        }

        // Swap the found minimum element with the element at index i
        temp = price[i];
        price[i] = price[minIndex];
        price[minIndex] = temp;
    }

    // Display sorted prices in ascending order
    printf("\nSorted prices in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", price[i]);
    }

    // Optional: Display prices in descending order
    printf("\n\nSorted prices in descending order:\n");
    for (i = n - 1; i >= 0; i--) {
        printf("%d ", price[i]);
    }

    printf("\n");
    return 0;
}
