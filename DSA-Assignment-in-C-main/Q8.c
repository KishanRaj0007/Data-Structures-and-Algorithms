#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}


void deleteNegativeNodes(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = *head;
    while (current != NULL) {
        if (current->data < 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            struct Node* temp = current;
            current = current->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}


void printList(struct Node* head) {
    printf("Doubly linked list: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


int main() {
    
    struct Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, -2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, -4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, -6);

    
    printf("Original ");
    printList(head);

    
    deleteNegativeNodes(&head);

    
    printf("List after deleting nodes with negative keys: ");
    printList(head);

    
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
