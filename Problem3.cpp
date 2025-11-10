#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXQ 50
#define MAXS 100

// -------------------- Parcel Handling (Queue) --------------------
int queue[MAXQ];
int front = 0, rear = 0;

void enqueue(int pid) {
    if (rear == MAXQ) {
        printf("Queue Overflow! Can't add parcel %d.\n", pid);
    } else {
        queue[rear++] = pid;
        printf("Parcel %d enqueued.\n", pid);
    }
}

void dequeue() {
    if (front == rear) {
        printf("Queue Underflow! No parcels to process.\n");
    } else {
        printf("Parcel %d dequeued (processed).\n", queue[front++]);
    }
}

void displayQueue() {
    if (front == rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Parcels in queue (front to rear): ");
        for (int i = front; i < rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// -------------------- Student Database --------------------
struct Student {
    int roll;
    char name[50];
    char program[50];
    char course[50];
    int marks[3];
    int total;
    float average;
};

void inputStudents(struct Student s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll number: ");
        scanf("%d", &s[i].roll);
        printf("Name: ");
        scanf(" %[^\n]", s[i].name);
        printf("Program: ");
        scanf(" %[^\n]", s[i].program);
        printf("Course: ");
        scanf(" %[^\n]", s[i].course);

        s[i].total = 0;
        for (int j = 0; j < 3; j++) {
            printf("Marks in subject %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }
        s[i].average = s[i].total / 3.0;
    }
}

void displayStudents(struct Student s[], int n) {
    printf("\n%-5s %-20s %-15s %-15s %-10s %-10s\n",
           "Roll", "Name", "Program", "Course", "Total", "Average");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-20s %-15s %-15s %-10d %-10.2f\n",
               s[i].roll, s[i].name, s[i].program, s[i].course,
               s[i].total, s[i].average);
    }
}

void searchStudent(struct Student s[], int n, int rollNo) {
    for (int i = 0; i < n; i++) {
        if (s[i].roll == rollNo) {
            printf("\nStudent Found:\n");
            printf("Roll: %d\nName: %s\nProgram: %s\nCourse: %s\nTotal: %d\nAverage: %.2f\n",
                   s[i].roll, s[i].name, s[i].program, s[i].course,
                   s[i].total, s[i].average);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", rollNo);
}

void sortStudents(struct Student s[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[j].total > s[i].total) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    printf("Students sorted by total marks (descending).\n");
}

// -------------------- Main Menu --------------------
int main() {
    struct Student students[MAXS];
    int n = 0; // number of students
    int choice, subChoice, pid, rollNo;

    while (1) {
        printf("\n=== Main Menu ===\n");
        printf("1. Parcel Handling System (Queue)\n");
        printf("2. Student Database System\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Parcel Handling
                do {
                    printf("\n--- Parcel Handling System ---\n");
                    printf("1. Enqueue parcel\n2. Dequeue parcel\n3. Display queue\n4. Back to Main Menu\nEnter choice: ");
                    scanf("%d", &subChoice);
                    switch (subChoice) {
                        case 1:
                            printf("Enter parcel ID to enqueue: ");
                            scanf("%d", &pid);
                            enqueue(pid);
                            break;
                        case 2:
                            dequeue();
                            break;
                        case 3:
                            displayQueue();
                            break;
                        case 4:
                            break;
                        default:
                            printf("Invalid choice.\n");
                    }
                } while (subChoice != 4);
                break;

            case 2: // Student Database
                if (n == 0) {
                    printf("Enter number of students: ");
                    scanf("%d", &n);
                    inputStudents(students, n);
                }
                do {
                    printf("\n--- Student Database ---\n");
                    printf("1. Display all\n2. Search by roll\n3. Sort by total\n4. Back to Main Menu\nEnter choice: ");
                    scanf("%d", &subChoice);
                    switch (subChoice) {
                        case 1:
                            displayStudents(students, n);
                            break;
                        case 2:
                            printf("Enter roll number to search: ");
                            scanf("%d", &rollNo);
                            searchStudent(students, n, rollNo);
                            break;
                        case 3:
                            sortStudents(students, n);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Invalid choice.\n");
                    }
                } while (subChoice != 4);
                break;

            case 3:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
