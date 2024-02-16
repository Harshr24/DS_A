#include <stdio.h>
#include <string.h>

// Define a structure to represent a student
struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

// Function to add a new student to the database
void addStudent(struct Student *database, int *numStudents) {
    if (*numStudents < 50) {
        printf("\nEnter details for the new student:\n");

        printf("Enter name: ");
        scanf("%s", database[*numStudents].name);

        printf("Enter roll number: ");
        scanf("%d", &database[*numStudents].rollNumber);

        printf("Enter marks: ");
        scanf("%f", &database[*numStudents].marks);

        (*numStudents)++;
        printf("Student added successfully!\n");
    } else {
        printf("Database is full. Cannot add more students.\n");
    }
}

// Function to display all students in the database
void displayAllStudents(const struct Student *database, int numStudents) {
    printf("\nList of all students:\n");

    for (int i = 0; i < numStudents; ++i) {
        printf("Name: %s, Roll Number: %d, Marks: %.2f\n",
               database[i].name, database[i].rollNumber, database[i].marks);
    }
}

// Function to find a student by their roll number
void findStudent(const struct Student *database, int numStudents, int rollNumber) {
    int found = 0;

    for (int i = 0; i < numStudents; ++i) {
        if (database[i].rollNumber == rollNumber) {
            printf("Student found!\n");
            printf("Name: %s, Roll Number: %d, Marks: %.2f\n",
                   database[i].name, database[i].rollNumber, database[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", rollNumber);
    }
}

int main() {
    struct Student studentDatabase[50];
    int numStudents = 0;
    int choice;
    int rollNumber;

    do {
        printf("\nDatabase Application Menu:\n");
        printf("1. Add new student\n");
        printf("2. Display all students\n");
        printf("3. Find student by roll number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(studentDatabase, &numStudents);
                break;
            case 2:
                displayAllStudents(studentDatabase, numStudents);
                break;
            case 3:
                printf("Enter the roll number to find: ");
                scanf("%d", &rollNumber);
                findStudent(studentDatabase, numStudents, rollNumber);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
