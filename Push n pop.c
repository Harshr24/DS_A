#include<stdio.h>
#define n 10

int stack[n];
int choice, a, i , top =-1;

void push(void);
void pop(void);
void display(void);

int main()
{
    printf("\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n Program is over. ");
                break;
            }
            default:
            {
                printf ("\n Enter a Valid Choice");
            }
        }
    }
    while(choice!=4);
    return 0;
}

void push()
{ 
    if (top>n)
    {
        printf("\n STACK is over flow"); 
    }
    else
    { 
        printf("Enter a value to be pushed:");
        scanf("%d",&a);
        top++;
        stack[top]=a;
    }
}

void pop()
{
    if(top<0)
    {
        printf("\n Stack is under flow");
    }
    else
    {
        printf("\n The popped elements is %d",stack[top]);
        top--;
    }
}

void display()
{
    if(top>=0)
    {
        printf("\n The elements in STACK are : ");
        for(i=top; i>=0; i--)
        {
            printf("\n %d",stack[i]);
        }
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The STACK is empty");
    }
}
