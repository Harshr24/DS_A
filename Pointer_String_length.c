#include <stdio.h>

// Function to calculate the length of a string using pointers
int stringLength(const char* str) {
    int len = 0;
    const char* p = str; // Pointer to the first character of the string
    while (*p != '\0') { // Loop until the null terminator is reached
        len++; // Increment the length
        p++; // Move the pointer to the next character
    }
    return len;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Call the string length function
    int len = stringLength(str);
    printf("The length of '%s' is %d.\n", str, len);

    return 0;
}
