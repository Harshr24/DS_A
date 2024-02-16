#include<stdio.h>

int main () {
    int arr [100];
    int k;
    printf ("Enter array elemnts : ");
    for (int i=0; i<10; i++) 
    {
        scanf("%d",&arr[i]);
    }
    printf ("Entered array elemnts are : ");
    for (int i=0; i<10; i++)
    {
        printf("%d, ",arr[i]);
    }
    printf("\n");
    printf ("Enter kth position (0 to 9) for insertion: ");
    scanf("%d",&k);
    if (k<0 || k>9) {
        printf("Invalid kth position. Exiting...\n");
        return 1;
    }
    printf ("Enter new array elemnts for arr[%d]: \n", k);
    int new_val;
    scanf("%d",&new_val);
    // for insertion : 
    for (int i=9; i>=k; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[k]=new_val;
    printf ("New array elemnts are : ");
    for (int i=0; i<10+1; i++)
    {
        printf("%d, ",arr[i]);
    }
    return 0;
}
