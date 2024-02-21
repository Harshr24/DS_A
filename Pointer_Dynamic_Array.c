#include <stdio.h>
#include <stdlib.h>

// Structure to represent a dynamic array
typedef struct {
    int* data; // Pointer to the array data
    int size; // Current size of the array
    int capacity; // Maximum capacity of the array
} DynamicArray;

// Function to create a new dynamic array with a given capacity
DynamicArray* createDynamicArray(int capacity) {
    // Allocate memory for the dynamic array structure
    DynamicArray* arr = (DynamicArray*)malloc(sizeof(DynamicArray));
    // Check if the allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    // Allocate memory for the array data
    arr->data = (int*)malloc(capacity * sizeof(int));
    // Check if the allocation was successful
    if (arr->data == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    // Initialize the size and capacity
    arr->size = 0;
    arr->capacity = capacity;
    // Return the pointer to the dynamic array
    return arr;
}

// Function to resize a dynamic array to a new capacity
void resizeDynamicArray(DynamicArray* arr, int newCapacity) {
    // Check if the new capacity is valid
    if (newCapacity <= 0) {
        printf("Invalid capacity.\n");
        return;
    }
    // Allocate memory for a new array data
    int* newData = (int*)malloc(newCapacity * sizeof(int));
    // Check if the allocation was successful
    if (newData == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    // Copy the old array data to the new array data
    for (int i = 0; i < arr->size; i++) {
        newData[i] = arr->data[i];
    }
    // Free the old array data
    free(arr->data);
    // Update the array data, capacity, and size
    arr->data = newData;
    arr->capacity = newCapacity;
    if (arr->size > newCapacity) {
        arr->size = newCapacity;
    }
}

// Function to append an element to the end of a dynamic array
void appendDynamicArray(DynamicArray* arr, int element) {
    // Check if the array is full
    if (arr->size == arr->capacity) {
        // Double the capacity
        int newCapacity = arr->capacity * 2;
        // Resize the array
        resizeDynamicArray(arr, newCapacity);
    }
    // Add the element to the end of the array
    arr->data[arr->size] = element;
    // Increment the size
    arr->size++;
}

// Function to insert an element at a given position in a dynamic array
void insertDynamicArray(DynamicArray* arr, int element, int pos) {
    // Check if the position is valid
    if (pos < 0 || pos > arr->size) {
        printf("Invalid position.\n");
        return;
    }
    // Check if the array is full
    if (arr->size == arr->capacity) {
        // Double the capacity
        int newCapacity = arr->capacity * 2;
        // Resize the array
        resizeDynamicArray(arr, newCapacity);
    }
    // Shift the elements to the right from the position
    for (int i = arr->size - 1; i >= pos; i--) {
        arr->data[i + 1] = arr->data[i];
    }
    // Insert the element at the position
    arr->data[pos] = element;
    // Increment the size
    arr->size++;
}

// Function to remove an element from a given position in a dynamic array
void removeDynamicArray(DynamicArray* arr, int pos) {
    // Check if the position is valid
    if (pos < 0 || pos >= arr->size) {
        printf("Invalid position.\n");
        return;
    }
    // Shift the elements to the left from the position
    for (int i = pos; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    // Decrement the size
    arr->size--;
    // Check if the array is too sparse
    if (arr->size < arr->capacity / 4) {
        // Halve the capacity
        int newCapacity = arr->capacity / 2;
        // Resize the array
        resizeDynamicArray(arr, newCapacity);
    }
}

// Function to get an element from a given position in a dynamic array
int getDynamicArray(DynamicArray* arr, int pos) {
    // Check if the position is valid
    if (pos < 0 || pos >= arr->size) {
        printf("Invalid position.\n");
        return -1;
    }
    // Return the element at the position
    return arr->data[pos];
}

// Function to set an element at a given position in a dynamic array
void setDynamicArray(DynamicArray* arr, int element, int pos) {
    // Check if the position is valid
    if (pos < 0 || pos >= arr->size) {
        printf("Invalid position.\n");
        return;
    }
    // Set the element at the position
    arr->data[pos] = element;
}

// Function to print a dynamic array
void printDynamicArray(DynamicArray* arr) {
    printf("Dynamic array: ");
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
    printf("Size: %d, Capacity: %d\n", arr->size, arr->capacity);
}

// Function to free a dynamic array
void freeDynamicArray(DynamicArray* arr) {
    // Free the array data
    free(arr->data);
    // Free the dynamic array structure
    free(arr);
}

// Function to display the menu and get the user's choice
int displayMenu() {
    int choice;
    printf("Welcome to the dynamic array program!\n");
    printf("Please choose one of the following options:\n");
    printf("1. Create a new dynamic array\n");
    printf("2. Append an element to the dynamic array\n");
    printf("3. Insert an element at a position in the dynamic array\n");
    printf("4. Remove an element from a position in the dynamic array\n");
    printf("5. Get an element from a position in the dynamic array\n");
    printf("6. Set an element at a position in the dynamic array\n");
    printf("7. Print the dynamic array\n");
    printf("8. Exit the program\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int choice;
    DynamicArray* arr = NULL; // Pointer to the dynamic array
    do {
        choice = displayMenu();
        switch (choice) {
            case 1: {
                int capacity;
                printf("Enter the initial capacity of the dynamic array: ");
                scanf("%d", &capacity);

                // Create a new dynamic array
                arr = createDynamicArray(capacity);
                printf("A new dynamic array with capacity %d is created.\n", capacity);
                break;
            }
            case 2: {
                int element;
                printf("Enter the element to be appended: ");
                scanf("%d", &element);

                // Append the element
                appendDynamicArray(arr, element);
                printf("%d is appended to the dynamic array.\n", element);
                break;
            }
            case 3: {
                int element, pos;
                printf("Enter the element to be inserted: ");
                scanf("%d", &element);
                printf("Enter the position to insert the element: ");
                scanf("%d", &pos);

                // Insert the element
                insertDynamicArray(arr, element, pos);
                printf("%d is inserted at position %d in the dynamic array.\n", element, pos);
                break;
            }
            case 4: {
                int pos;
                printf("Enter the position to remove the element: ");
                scanf("%d", &pos);

                // Remove the element
                int element = getDynamicArray(arr, pos);
                removeDynamicArray(arr, pos);
                printf("%d is removed from position %d in the dynamic array.\n", element, pos);
                break;
            }
            case 5: {
                int pos;
                printf("Enter the position to get the element: ");
                scanf("%d", &pos);

                // Get the element
                int element = getDynamicArray(arr, pos);
                printf("The element at position %d is %d.\n", pos, element);
                break;
            }
            case 6: {
                int element, pos;
                printf("Enter the element to be set: ");
                scanf("%d", &element);
                printf("Enter the position to set the element: ");
                scanf("%d", &pos);

                // Set the element
                setDynamicArray(arr, element, pos);
                printf("%d is set at position %d in the dynamic array.\n", element, pos);
                break;
            }
            case 7: {
                // Print the dynamic array
                printDynamicArray(arr);
                break;
            }
            case 8: {
                printf("Thank you for using the dynamic array program. Goodbye!\n");
