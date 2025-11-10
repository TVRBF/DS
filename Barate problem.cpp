#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    int marks[3];
    int total;
    float average;
};

void input(struct Student s[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll number: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        s[i].total = 0;
        for (j = 0; j < 3; j++) {
            printf("Marks in subject %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].average = s[i].total / 3.0;
    }
}

void display(struct Student s[], int n) {
    int i;
    printf("\n%-5s %-20s %-10s %-10s\n", "Roll", "Name", "Total", "Average");
    for (i = 0; i < n; i++) {
        printf("%-5d %-20s %-10d %-10.2f\n",
               s[i].roll, s[i].name, s[i].total, s[i].average);
    }
}

void search(struct Student s[], int n, int rollNo) {
    int i;
    for (i = 0; i < n; i++) {
        if (s[i].roll == rollNo) {
            printf("\nStudent Found:\n");
            printf("Roll: %d\nName: %s\nTotal: %d\nAverage: %.2f\n",
                   s[i].roll, s[i].name, s[i].total, s[i].average);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", rollNo);
}

void sort(struct Student s[], int n) {
    int i, j;
    struct Student temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (s[j].total > s[i].total) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int main() {
    struct Student s[MAX];
    int n, choice, rollNo;

    printf("Enter number of students: ");
    scanf("%d", &n);

    input(s, n);

    do {
        printf("\n1. Display all\n2. Search by roll\n3. Sort by total\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(s, n);
                break;

            case 2:
                printf("Enter roll number to search: ");
                scanf("%d", &rollNo);
                search(s, n, rollNo);
                break;

            case 3:
                sort(s, n);
                printf("Sorted by total marks (highest to lowest).\n");
                break;

            case 4:
                printf("Exiting.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}
