#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define node structure
struct Node {
    char name[50];
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(char *name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newNode->name, name);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a name into the BST
struct Node* insert(struct Node* root, char *name) {
    if (root == NULL) {
        return createNode(name);
    }

    if (strcmp(name, root->name) < 0)
        root->left = insert(root->left, name);
    else if (strcmp(name, root->name) > 0)
        root->right = insert(root->right, name);
    else
        printf("Duplicate name '%s' ignored.\n", name);

    return root;
}

// Inorder Traversal (Sorted order)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s ", root->name);
        inorder(root->right);
    }
}

// Preorder Traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%s ", root->name);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%s ", root->name);
    }
}

// Search function (returns 1 if found, 0 otherwise)
int search(struct Node* root, char *name) {
    if (root == NULL)
        return 0;

    if (strcmp(name, root->name) == 0)
        return 1;
    else if (strcmp(name, root->name) < 0)
        return search(root->left, name);
    else
        return search(root->right, name);
}

// Free all nodes (cleanup before exit)
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Trim newline from fgets input
void trimNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice;
    char name[50];

    while (1) {
        printf("\n\n--- Online Directory System (BST) ---\n");
        printf("1. Insert Name\n");
        printf("2. Inorder Traversal (Sorted)\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search Name\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter name to insert: ");
                fgets(name, sizeof(name), stdin);
                trimNewline(name);
                root = insert(root, name);
                printf("Inserted successfully.\n");
                break;

            case 2:
                printf("\nInorder Traversal (A–Z): ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("\nPreorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("\nPostorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Enter name to search: ");
                fgets(name, sizeof(name), stdin);
                trimNewline(name);
                if (search(root, name))
                    printf("✅ %s found in directory.\n", name);
                else
                    printf("❌ %s not found in directory.\n", name);
                break;

            case 6:
                printf("Exiting and freeing memory...\n");
                freeTree(root);
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
