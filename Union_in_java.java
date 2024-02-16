import java.util.Scanner;

// Define a class to hold either an integer or a float
class Data {
    int intValue;
    float floatValue;
}

public class UnionArrayExample {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int size = scanner.nextInt();

        // Declare an array of class type to store a mix of integers and floats
        Data[] dataArray = new Data[size];

        // Input values for the array
        for (int i = 0; i < size; ++i) {
            System.out.print("Enter value " + (i + 1) + ": ");

            // Input choice (1 for integer, 2 for float)
            int choice;
            System.out.print("Enter choice (1 for integer, 2 for float): ");
            choice = scanner.nextInt();

            // Based on the choice, input either an integer or a float
            dataArray[i] = new Data();
            if (choice == 1) {
                System.out.print("Enter integer value: ");
                dataArray[i].intValue = scanner.nextInt();
            } else if (choice == 2) {
                System.out.print("Enter float value: ");
                dataArray[i].floatValue = scanner.nextFloat();
            } else {
                System.out.println("Invalid choice. Enter 1 for integer or 2 for float.");
                --i; // Decrement i to re-enter the current index
            }
        }

        // Display the values stored in the array
        System.out.println("\nValues stored in the array:");
        for (int i = 0; i < size; ++i) {
            if (dataArray[i].intValue != 0) {
                System.out.println("Integer value at index " + i + ": " + dataArray[i].intValue);
            } else if (dataArray[i].floatValue != 0.0f) {
                System.out.println("Float value at index " + i + ": " + String.format("%.2f", dataArray[i].floatValue));
            }
        }
    }
}
