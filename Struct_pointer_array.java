import java.util.Scanner;

class Student {
    String name;
    int rollNumber;
    float marks;
}

public class Struct_pointer_array {
    public static void addStudent(Student[] database, int numStudents) {
        if (numStudents < database.length) {
            Scanner scanner = new Scanner(System.in);

            System.out.println("\nEnter details for the new student:");

            System.out.print("Enter name: ");
            database[numStudents].name = scanner.next();

            System.out.print("Enter roll number: ");
            database[numStudents].rollNumber = scanner.nextInt();

            System.out.print("Enter marks: ");
            database[numStudents].marks = scanner.nextFloat();

            System.out.println("Student added successfully!");
            scanner.close();
        } else {
            System.out.println("Database is full. Cannot add more students.");
        }
    }

    public static void displayAllStudents(Student[] database, int numStudents) {
        System.out.println("\nList of all students:");

        for (int i = 0; i < numStudents; ++i) {
            System.out.println("Name: " + database[i].name + ", Roll Number: " +
                    database[i].rollNumber + ", Marks: " + database[i].marks);
        }
    }

    public static void findStudent(Student[] database, int numStudents, int rollNumber) {
        boolean found = false;

        for (int i = 0; i < numStudents; ++i) {
            if (database[i].rollNumber == rollNumber) {
                System.out.println("Student found!");
                System.out.println("Name: " + database[i].name + ", Roll Number: " +
                        database[i].rollNumber + ", Marks: " + database[i].marks);
                found = true;
                break;
            }
        }

        if (!found) {
            System.out.println("Student with Roll Number " + rollNumber + " not found.");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Student[] studentDatabase = new Student[50];
        int numStudents = 0;
        int choice;
        int rollNumber;

        for (int i = 0; i < studentDatabase.length; i++) {
            studentDatabase[i] = new Student();
        }

        do {
            System.out.println("\nDatabase Application Menu:");
            System.out.println("1. Add new student");
            System.out.println("2. Display all students");
            System.out.println("3. Find student by roll number");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    addStudent(studentDatabase, numStudents);
                    numStudents++;
                    break;
                case 2:
                    displayAllStudents(studentDatabase, numStudents);
                    break;
                case 3:
                    System.out.print("Enter the roll number to find: ");
                    rollNumber = scanner.nextInt();
                    findStudent(studentDatabase, numStudents, rollNumber);
                    break;
                case 4:
                    System.out.println("Exiting the program.");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }
        } while (choice != 4);
        scanner.close();
    }
}
