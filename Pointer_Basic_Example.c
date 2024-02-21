#include <stdio.h>

// Function to swap two integers using pointers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to reverse an integer array using pointers
void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

// Function to find maximum and minimum elements in an array using pointers
void findMinMax(int arr[], int size, int* max, int* min) {
    *max = *min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > *max)
            *max = arr[i];
        if (arr[i] < *min)
            *min = arr[i];
    }
}

// Function to check if a string is a palindrome using pointers
int isPalindrome(const char* str) {
    const char* start = str;
    const char* end = str + strlen(str) - 1;
    while (start < end) {
        if (*start != *end)
            return 0; // Not a palindrome
        start++;
        end--;
    }
    return 1; // Palindrome
}

// Function to display the menu and get the user's choice
int displayMenu() {
    int choice;
    printf("Welcome to the pointer program!\n");
    printf("Please choose one of the following options:\n");
    printf("1. Swap two numbers using pointers\n");
    printf("2. Reverse an array using pointers\n");
    printf("3. Find maximum and minimum element in an array using pointers\n");
    printf("4. Check palindrome using pointers\n");
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
                int num1, num2;
                printf("Enter two integers: ");
                scanf("%d %d", &num1, &num2);

                // Swap the numbers
                swap(&num1, &num2);
                printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);
                break;
            }
            case 2: {
                int arr[100];
                int arrSize;
                printf("Enter the size of the array: ");
                scanf("%d", &arrSize);
                printf("Enter the elements of the array: ");
                for (int i = 0; i < arrSize; i++)
                    scanf("%d", &arr[i]);

                // Reverse the array
                reverseArray(arr, arrSize);
                printf("Reversed array: ");
                for (int i = 0; i < arrSize; i++)
                    printf("%d ", arr[i]);
                printf("\n");
                break;
            }
            case 3: {
                int arr[100];
                int arrSize;
                printf("Enter the size of the array: ");
                scanf("%d", &arrSize);
                printf("Enter the elements of the array: ");
                for (int i = 0; i < arrSize; i++)
                    scanf("%d", &arr[i]);

                // Find maximum and minimum elements
                int max, min;
                findMinMax(arr, arrSize, &max, &min);
                printf("Max element: %d, Min element: %d\n", max, min);
                break;
            }
            case 4: {
                char str[100];
                printf("Enter a string: ");
                scanf("%s", str);

                // Check if the string is a palindrome
                if (isPalindrome(str))
                    printf("'%s' is a palindrome.\n", str);
                else
                    printf("'%s' is not a palindrome.\n", str);
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
