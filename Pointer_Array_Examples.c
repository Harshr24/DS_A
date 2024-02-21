#include <stdio.h>
#include <stdlib.h>

// Function to sort an array using pointers
void sortArray(int arr[], int size) {
    int* p; // Pointer to the current element
    int* q; // Pointer to the next element
    int temp; // Temporary variable for swapping
    for (int i = 0; i < size - 1; i++) {
        p = &arr[i]; // Point to the ith element
        for (int j = i + 1; j < size; j++) {
            q = &arr[j]; // Point to the jth element
            if (*p > *q) { // Compare the values pointed by p and q
                // Swap the values
                temp = *p;
                *p = *q;
                *q = temp;
            }
        }
    }
}

// Function to merge two sorted arrays using pointers
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int* p = arr1; // Pointer to the first element of arr1
    int* q = arr2; // Pointer to the first element of arr2
    int* r = result; // Pointer to the first element of result
    int i = 0, j = 0, k = 0; // Indices for arr1, arr2, and result
    while (i < size1 && j < size2) {
        if (*p < *q) { // Compare the values pointed by p and q
            // Copy the smaller value to result
            *r = *p;
            // Increment the pointers and indices
            p++;
            r++;
            i++;
        }
        else {
            // Copy the smaller or equal value to result
            *r = *q;
            // Increment the pointers and indices
            q++;
            r++;
            j++;
        }
    }
    // Copy the remaining elements of arr1 to result
    while (i < size1) {
        *r = *p;
        p++;
        r++;
        i++;
    }
    // Copy the remaining elements of arr2 to result
    while (j < size2) {
        *r = *q;
        q++;
        r++;
        j++;
    }
}

// Function to delete an element from an array using pointers
void deleteElement(int arr[], int* size, int pos) {
    int* p = &arr[pos]; // Pointer to the element to be deleted
    int* q = &arr[pos + 1]; // Pointer to the next element
    for (int i = pos; i < *size - 1; i++) {
        // Shift the elements to the left
        *p = *q;
        // Increment the pointers
        p++;
        q++;
    }
    // Decrement the size of the array
    (*size)--;
}

// Function to find duplicate elements in an array using pointers
void findDuplicates(int arr[], int size) {
    int* p; // Pointer to the current element
    int* q; // Pointer to the next element
    int flag = 0; // Flag to indicate if any duplicate is found
    printf("The duplicate elements are: ");
    for (int i = 0; i < size - 1; i++) {
        p = &arr[i]; // Point to the ith element
        for (int j = i + 1; j < size; j++) {
            q = &arr[j]; // Point to the jth element
            if (*p == *q) { // Compare the values pointed by p and q
                // Print the duplicate value
                printf("%d ", *p);
                flag = 1; // Set the flag to 1
            }
        }
    }
    if (flag == 0) // If no duplicate is found
        printf("None");
    printf("\n");
}

// Function to display the menu and get the user's choice
int displayMenu() {
    int choice;
    printf("Welcome to the pointer program!\n");
    printf("Please choose one of the following options:\n");
    printf("1. Sort an array using pointers\n");
    printf("2. Merge two sorted arrays using pointers\n");
    printf("3. Delete an element from an array using pointers\n");
    printf("4. Find duplicate elements in an array using pointers\n");
    printf("5. Exit the program\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int choice;
    do {
        choice = displayMenu();
        switch (choice) {
            case 1: {
                int arr[100];
                int size;
                printf("Enter the size of the array: ");
                scanf("%d", &size);
                printf("Enter the elements of the array: ");
                for (int i = 0; i < size; i++)
                    scanf("%d", &arr[i]);

                // Sort the array
                sortArray(arr, size);
                printf("Sorted array: ");
                for (int i = 0; i < size; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;
            }
            case 2: {
                int arr1[100], arr2[100], result[200];
                int size1, size2;
                printf("Enter the size of the first array: ");
                scanf("%d", &size1);
                printf("Enter the elements of the first array in sorted order: ");
                for (int i = 0; i < size1; i++)
                    scanf("%d", &arr1[i]);
                printf("Enter the size of the second array: ");
                scanf("%d", &size2);
                printf("Enter the elements of the second array in sorted order: ");
                for (int i = 0; i < size2; i++)
                    scanf("%d", &arr2[i]);

                // Merge the arrays
                mergeArrays(arr1, size1, arr2, size2, result);
                printf("Merged array: ");
                for (int i = 0; i < size1 + size2; i++)
                    printf("%d ", result[i]);
                printf("\n");
                break;
            }
            case 3: {
                int arr[100];
                int size;
                int pos;
                printf("Enter the size of the array: ");
                scanf("%d", &size);
                printf("Enter the elements of the array: ");
                for (int i = 0; i < size; i++)
                    scanf("%d", &arr[i]);
                printf("Enter the position of the element to be deleted: ");
                scanf("%d", &pos);

                // Delete the element
                deleteElement(arr, &size, pos);
                printf("Array after deletion: ");
                for (int i = 0; i < size; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;
            }
            case 4: {
                int arr[100];
                int size;
                printf("Enter the size of the array: ");
                scanf("%d", &size);
                printf("Enter the elements of the array: ");
                for (int i = 0; i < size; i++)
                    scanf("%d", &arr[i]);

                // Find duplicates
                findDuplicates(arr, size);
                break;
            }
            case 5: {
                printf("Thank you for using the pointer program. Goodbye!\n");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    } while (choice != 5);
    return 0;
}
