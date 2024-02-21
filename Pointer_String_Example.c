#include <stdio.h>

// Function to check if a string is a palindrome using pointers
int isPalindrome(const char* str) {
    const char* start = str; // Pointer to the first character of the string
    const char* end = str + strlen(str) - 1; // Pointer to the last character of the string
    while (start < end) { // Loop until the pointers cross
        if (*start != *end) // Compare the characters pointed by the pointers
            return 0; // Not a palindrome
        start++; // Move the start pointer to the right
        end--; // Move the end pointer to the left
    }
    return 1; // Palindrome
}

// Function to calculate the length of a string using pointers
int stringLength(const char* str) {
    int len = 0; // Variable to store the length
    const char* p = str; // Pointer to the first character of the string
    while (*p != '\0') { // Loop until the null terminator is reached
        len++; // Increment the length
        p++; // Move the pointer to the next character
    }
    return len; // Return the length
}

// Function to display the menu and get the user's choice
int displayMenu() {
    int choice;
    printf("Welcome to the pointer program!\n");
    printf("Please choose one of the following options:\n");
    printf("1. Check palindrome using pointers\n");
    printf("2. Implement string length function using pointers\n");
    printf("3. Exit the program\n");
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
            case 2: {
                char str[100];
                printf("Enter a string: ");
                scanf("%s", str);

                // Calculate the length of the string
                int len = stringLength(str);
                printf("The length of '%s' is %d.\n", str, len);
                break;
            }
            case 3: {
                printf("Thank you for using the pointer program. Goodbye!\n");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    } while (choice != 3);
    return 0;
}
