#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Node structure
struct Node {
    char line[100];
    struct Node* next;
};

struct Node* head = NULL; // Start of the linked list

// Function to insert at the front
void insert_front(char text[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newNode->line, text);
    newNode->next = head;
    head = newNode;
}

// Function to insert at the end
void insert_end(char text[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newNode->line, text);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Function to insert at a specific position
void insert_at_pos(char text[], int pos) {
    if (pos <= 0) {
        printf("Invalid position! Position must be >= 1.\n");
        return;
    }

    if (pos == 1) {
        insert_front(text);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newNode->line, text);

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position! List has fewer lines.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to display all lines
void display() {
    struct Node* temp = head;
    int i = 1;

    if (temp == NULL) {
        printf("\nText is empty.\n");
        return;
    }

    printf("\nCurrent Text (Top to Bottom):\n");
    printf("---------------------------------\n");

    while (temp != NULL) {
        printf("%d: %s\n", i++, temp->line);
        temp = temp->next;
    }
}

// Main menu
int main() {
    int choice, pos;
    char text[100];

    while (1) {
        printf("\n========= TEXT EDITOR MENU =========\n");
        printf("1. Insert Line at Front\n");
        printf("2. Insert Line at End\n");
        printf("3. Insert Line at Position\n");
        printf("4. Display Text\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            exit(0);
        }

        getchar(); // clear newline

        switch (choice) {
            case 1:
                printf("Enter line: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = '\0';
                insert_front(text);
                break;

            case 2:
                printf("Enter line: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = '\0';
                insert_end(text);
                break;

            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                getchar();
                printf("Enter line: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = '\0';
                insert_at_pos(text, pos);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting text editor. Goodbye!\n");
                // Free all nodes before exit
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
