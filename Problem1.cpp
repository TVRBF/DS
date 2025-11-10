#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int stack[MAX];
int top = -1;

// Push a parcel onto the stack
void push(int parcel_id) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot add more parcels.\n");
    } else {
        top++;
        stack[top] = parcel_id;
        printf("Parcel %d added.\n", parcel_id);
    }
}

// Pop a parcel from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow! No parcels to remove.\n");
    } else {
        printf("Parcel %d removed.\n", stack[top]);
        top--;
    }
}

// Display parcels in the stack
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Parcels in stack (top to bottom): ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, parcel_id;

    while (1) {
        printf("\n--- Parcel Handling System (Stack: LIFO) ---\n");
        printf("1. Push parcel\n");
        printf("2. Pop parcel\n");
        printf("3. Display parcels\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter parcel ID to push: ");
                scanf("%d", &parcel_id);
                push(parcel_id);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
