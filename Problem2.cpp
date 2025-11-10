#include <stdio.h>
#include <string.h>

#define MAX 50
#define SUBJECTS 5

// Structure to store student information
struct Student {
    int roll_no;
    char name[50];
    char program[50];
    char course[50];
    int marks[SUBJECTS];
    int total;
    float average;
};

// Function declarations
void inputStudents(struct Student s[], int n);
void displayStudents(struct Student s[], int n);
void searchStudent(struct Student s[], int n, int roll);
void sortStudents(struct Student s[], int n);

int main() {
    struct Student students[MAX];
    int n, choice, roll;

    printf("Enter number of students: ");
    scanf("%d", &n);

    inputStudents(students, n);

    while (1) {
        printf("\n===== Student Database Menu =====\n");
        printf("1. Display all students\n");
        printf("2. Search by Roll Number\n");
        printf("3. Sort by Total Marks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayStudents(students, n);
                break;
            case 2:
                printf("Enter roll number to search: ");
                scanf("%d", &roll);
                searchStudent(students, n, roll);
                break;
            case 3:
                sortStudents(students, n);
                printf("Students sorted by total marks (descending).\n");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

// Function to input student details
void inputStudents(struct Student s[], int n) {
    for (int i = 0; i < n; i++) {
        s[i].total = 0;

        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &s[i].roll_no);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Program: ");
        scanf("%s", s[i].program);
        printf("Course: ");
        scanf("%s", s[i].course);

        printf("Enter marks for %d subjects: ", SUBJECTS);
        for (int j = 0; j < SUBJECTS; j++) {
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }
        s[i].average = s[i].total / (float)SUBJECTS;
    }
}

// Function to display all students
void displayStudents(struct Student s[], int n) {
    printf("\n%-10s %-15s %-10s %-10s %-10s %-10s\n", 
           "RollNo", "Name", "Program", "Course", "Total", "Average");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-10d %-15s %-10s %-10s %-10d %-10.2f\n",
               s[i].roll_no, s[i].name, s[i].program, s[i].course,
               s[i].total, s[i].average);
    }
}

// Function to search for a student by roll number
void searchStudent(struct Student s[], int n, int roll) {
    for (int i = 0; i < n; i++) {
        if (s[i].roll_no == roll) {
            printf("\nStudent found:\n");
            printf("Roll No: %d\nName: %s\nProgram: %s\nCourse: %s\nTotal: %d\nAverage: %.2f\n",
                   s[i].roll_no, s[i].name, s[i].program, s[i].course, s[i].total, s[i].average);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll);
}

// Function to sort students by total marks (descending)
void sortStudents(struct Student s[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i].total < s[j].total) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}
