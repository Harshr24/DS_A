#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL; // Global variable for the head of the linked list

void insert(int value) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void display() {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    struct node *current = head; // Traverse the linked list and print each node's data
    printf("Linked list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void deleteFirstNode() {
    struct node *toDelete;
    if (head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    toDelete = head;
    head = head->next;
    printf("\nData deleted = %d\n", toDelete->data);
    free(toDelete);
    printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
}

void deleteMiddleNode(int position) {
    int i;
    struct node *toDelete, *prevNode;
    if (head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    toDelete = head;
    prevNode = head;
    for (i = 2; i <= position; i++) {
        prevNode = toDelete;
        toDelete = toDelete->next;
        if (toDelete == NULL) break;
    }
    if (toDelete != NULL) {
        if (toDelete == head) head = head->next;
        prevNode->next = toDelete->next;
        toDelete->next = NULL;
        free(toDelete);
        printf("SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n");
    } else {
        printf("Invalid position unable to delete.\n");
    }
}

void deleteLastNode() {
    if (head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct node *toDelete = head;
    struct node *secondLastNode = NULL;
    while (toDelete->next != NULL) {
        secondLastNode = toDelete;
        toDelete = toDelete->next;
    }
    if (toDelete == head) {
        head = NULL;
    } else {
        secondLastNode->next = NULL;
    }
    free(toDelete);
    printf("Last node deleted successfully.\n");
}

int main() {
    int value;
    printf("Enter number of elements in the linked list: ");
    int n;
    scanf("%d", &n);
    printf("Enter elements to insert into the linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(value);
    }
    display(); // Display the linked list
    int choice;
    printf("Enter 1 to delete the first node, 2 to delete the middle node, 3 to delete the last node: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            deleteFirstNode();
            break;
        case 2:
            int position;
            printf("Enter position of the node to delete: ");
            scanf("%d", &position);
            deleteMiddleNode(position);
            break;
        case 3:
            deleteLastNode();
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    display(); // Display the linked list after deletion
    return 0;
}
