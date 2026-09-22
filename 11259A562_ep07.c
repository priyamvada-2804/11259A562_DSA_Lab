#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void insert() {
    int value;
    struct Node *newNode, *temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } 
    else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted successfully.\n");
}
void deleteNode() {
    int value;
    struct Node *temp, *prev;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Enter value to delete: ");
    scanf("%d", &value);
    temp = head;
    prev = NULL;
    if (temp->data == value) {
        head = temp->next;
        free(temp);
        printf("Node deleted successfully.\n");
        return;
    }
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node deleted successfully.\n");
}
void traverse() {
    struct Node *temp;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int choice;
    while (1) {
        printf("\n--- SINGLY LINKED LIST ---\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                deleteNode();
                break;
            case 3:
                traverse();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
