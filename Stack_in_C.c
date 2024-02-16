#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1) 
	{
        printf("Error: Stack overflow!\n");
    }
    stack[++top] = value;
}

int pop() 
{
    if (top == -1) 
	{
        printf("Error: Stack underflow!\n");
    }
    return stack[top--];
}

void peep() 
{
    if (top == -1) 
	{
        printf("Error: Stack is empty!\n");
        return;
    }

    for (int i = 0; i <= top; i++) 
    {
        printf("%d | ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("1. Push\n2. Pop\n3. Peep\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                value = pop();
                if (value != 0) {
                    printf("Popped value: %d\n", value);
                }
                break;
                
			case 3:
            	peep();
                break;
                
            case 4:
            	printf("Thank You... Exitingggggggg !!!'");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
