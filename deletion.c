
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Insert a node at the end
void insert(struct Node **head, int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != *head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = *head;
}

// Delete from beginning
void deleteBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head;

    // Only one node
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
        return;
    }

    struct Node *last = *head;

    while (last->next != *head)
        last = last->next;

    *head = temp->next;
    last->next = *head;

    free(temp);
}

// Delete from end
void deleteEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head;

    // Only one node
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
        return;
    }

    struct Node *prev = NULL;

    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = *head;
    free(temp);
}

// Display the list
void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

int main() {
    struct Node *head = NULL;
    int n, data, choice;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &data);
        insert(&head, data);
    }

    printf("\nOriginal Circular Linked List:\n");
    display(head);

    printf("\n1. Delete from beginning");
    printf("\n2. Delete from end");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        deleteBeginning(&head);
    else if (choice == 2)
        deleteEnd(&head);
    else
        printf("Invalid choice.\n");

    printf("\nAfter deletion:\n");
    display(head);

    return 0;
}