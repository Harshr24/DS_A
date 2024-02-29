#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
    } else {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

void insertFromHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertFromTail(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 0) {
        printf("Invalid position!\n");
    }
    if (position == 0) {
        insertFromHead(head, data);
    }
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Position out of range!\n");
        free(newNode);
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int data, choice, position;

    printf("Enter number of elements in the linked list: ");
    int n;
    scanf("%d", &n);
    printf("Enter elements to insert into the linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertFromTail(&head, data);
    }
    displayList(head);

    while (1) {
        printf("\n1. Insert from head\n2. Insert from tail\n3. Insert at position\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the head: ");
                scanf("%d", &data);
                insertFromHead(&head, data);
                displayList(head);
                break;
            case 2:
                printf("Enter data to insert at the tail: ");
                scanf("%d", &data);
                insertFromTail(&head, data);
                displayList(head);
                break;
            case 3:
                printf("Enter data to insert at a position: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                displayList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    } return 0;
}
