
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;

// Insert at beginning
void insertBeginning(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;

    if (last == NULL) {
        last = newNode;
        newNode->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
}

// Insert at end
void insertEnd(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;

    if (last == NULL) {
        last = newNode;
        newNode->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

// Display circular linked list
void display() {
    struct Node *temp;

    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = last->next;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(back to first node)\n");
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    printf("Original list:\n");
    display();

    insertBeginning(5);

    printf("After insertion at beginning:\n");
    display();

    insertEnd(40);

    printf("After insertion at end:\n");
    display();

    return 0;
}