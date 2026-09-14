#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;   // Points back to head
        } else {
            temp = head;

            // Find the last node
            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;   // Last node points to head
        }
    }

    // Display circular linked list
    if (head != NULL) {
        temp = head;

        printf("\nCircular Linked List: ");

        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);

        printf("(back to head)\n");
    }

    return 0;