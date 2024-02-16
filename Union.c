#include <stdio.h>

// Define a union to hold either an integer or a float
union Data {
    int intValue;
    float floatValue;
};

int main() {
    int size;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Declare an array of union type to store a mix of integers and floats
    union Data dataArray[size];

    // Input values for the array
    for (int i = 0; i < size; ++i) {
        printf("Enter value %d: ", i + 1);

        // Input choice (1 for integer, 2 for float)
        int choice;
        printf("Enter choice (1 for integer, 2 for float): ");
        scanf("%d", &choice);

        // Based on the choice, input either an integer or a float
        if (choice == 1) {
            printf("Enter integer value: ");
            scanf("%d", &dataArray[i].intValue);
        } else if (choice == 2) {
            printf("Enter float value: ");
            scanf("%f", &dataArray[i].floatValue);
        } else {
            printf("Invalid choice. Enter 1 for integer or 2 for float.\n");
            --i; // Decrement i to re-enter the current index
        }
    }

    // Display the values stored in the array
    printf("\nValues stored in the array:\n");
    for (int i = 0; i < size; ++i) {
        if (sizeof(dataArray[i]) == sizeof(int)) {
            printf("Integer value at index %d: %d\n", i, dataArray[i].intValue);
        } else if (sizeof(dataArray[i]) == sizeof(float)) {
            printf("Float value at index %d: %.2f\n", i, dataArray[i].floatValue);
        }
    }

    return 0;
}
