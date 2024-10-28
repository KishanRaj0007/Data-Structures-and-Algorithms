#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertAtThird(struct Node** head, int data) {
    if (*head == NULL) {
        printf("Error: List is empty\n");
        return;
    }

    struct Node* newNode = createNode(data);

    
    struct Node* current = *head;
    int count = 1;
    while (count < 3 && current->next != NULL) {
        current = current->next;
        count++;
    }

    if (count < 2) {
        printf("Error: List has less than two nodes\n");
        return;
    }

    // Insert the new node after the third node
    newNode->next = current->next;
    current->next = newNode;
}


void removeLastNode(struct Node** head) {
    if (*head == NULL) {
        printf("Error: List is empty\n");
        return;
    }

    // If there is only one node, remove it
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    // Traverse to the second last node
    struct Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    // Free the last node and update the next pointer of second last node
    free(current->next);
    current->next = NULL;
}


void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


int main() {

    int n;
    int value;
    printf("Enter the number of elements in Linked list ");
    scanf("%d",&n);
    struct Node *head = malloc(sizeof(struct Node));
    printf("Enter the value of head ");
    scanf("%d",&value);
    head->data = value;
    struct Node *temp = head;
    int count = 2;
    while(count <= n)
    {
        int value;
        printf("Enter the value of node %d : ",count);
        scanf("%d",&value);
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->data = value;
        temp->next = newNode;
        temp = temp->next;
        count++;
    }
    temp->next = NULL;

    printf("Original linked list: ");
    printList(head);

    
    insertAtThird(&head, 5);
    printf("Linked list after insertion at third place: ");
    printList(head);

    
    removeLastNode(&head);
    printf("Linked list after removing the last node: ");
    printList(head);

    return 0;
}
