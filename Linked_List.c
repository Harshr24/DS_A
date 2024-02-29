#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createN (int data) {
    struct Node* newN = malloc(sizeof(struct N));
    if (newN = NULL) {
        printf("Memory allocation failed!\n");
    }
    else {
        newN->data = data;
        newN->next = NULL;
        return newN;
    }
}

int main () {
    struct Node* head = NULL;
    int data, key, n;
    printf ("Enter number of elemnt in linked list : ");
    scanf ("%d", &n);
    printf("Enter elements to insert into the linked list :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
    }
}
