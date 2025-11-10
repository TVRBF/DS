#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Function to push value onto the stack
void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    } else {
        printf("Stack Overflow!\n");
    }
}

// Function to pop value from the stack
int pop() {
    if (top >= 0)
        return stack[top--];
    else
        return -1;
}

int main() {
    int decimal, remainder, num;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    if (decimal == 0) {
        printf("Binary equivalent of 0 is: 0\n");
        return 0;
    }

    num = decimal;

    // Convert decimal to binary using a stack
    while (num > 0) {
        remainder = num % 2;
        push(remainder);
        num = num / 2;
    }

    // Display binary number
    printf("Binary equivalent of %d is: ", decimal);
    while (top != -1) {
        printf("%d", pop());
    }
    printf("\n");

    return 0;
}
