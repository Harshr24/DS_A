#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

bool areIdentical(struct node* a, struct node* b){
    while (a != NULL && b != NULL) {
        if (a->data != b->data) {
            return false;
        }
        a = a->next;
        b = b->next;
    }
    return (a == NULL && b == NULL);
}

struct node* createList(int n) {
    head = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insert(value);
    }
    return head;
}

int main() {
    int n, m;
    printf("Enter the number of elements for the first linked list: ");
    scanf("%d", &n);
    struct node *a = createList(n);
    
    printf("Enter the number of elements for the second linked list: ");
    scanf("%d", &m);
    struct node *b = createList(m);
    
    if (areIdentical(a, b)) {
        printf("The two lists are identical.\n");
    } else {
        printf("The two lists are not identical.\n");
    }
    return 0;
}
