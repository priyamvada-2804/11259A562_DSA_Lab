#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void insertBeginning(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Node inserted at the beginning.\n");
}
void insertPosition(int value, int position) {
    struct Node *newNode, *temp;
    int i;
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }
    if (position == 1) {
        insertBeginning(value);
        return;
    }
    temp = head;
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position does not exist!\n");
        return;
    }
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d.\n", position);
}
void insertEnd(int value) {
    struct Node *newNode, *temp;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted at the end.\n");
}
void deleteBeginning() {
    struct Node *temp;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from the beginning.\n");
}
void deletePosition(int position) {
    struct Node *temp, *deleteNode;
    int i;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }
    if (position == 1) {
        deleteBeginning();
        return;
    }
    temp = head;
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position does not exist!\n");
        return;
    }
    deleteNode = temp->next;
    temp->next = deleteNode->next;
    free(deleteNode);
    printf("Node deleted from position %d.\n", position);
}
void deleteEnd() {
    struct Node *temp, *deleteNode;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Node deleted from the end.\n");
        return;
    }
    temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    deleteNode = temp->next;
    temp->next = NULL;
    free(deleteNode);
    printf("Node deleted from the end.\n");
}
void traverse() {
    struct Node *temp;
    if (head == NULL) {
        printf("List is empty!\n");
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
    int choice, value, position;
    while (1) {
        printf("\n===== SINGLY LINKED LIST =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Position\n");
        printf("3. Insert at End\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at Position\n");
        printf("6. Delete at End\n");
        printf("7. Traverse\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertPosition(value, position);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 4:
                deleteBeginning();
                break;
            case 5:
                printf("Enter position: ");
                scanf("%d", &position);
                deletePosition(position);
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                traverse();
                break;
            case 8:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
