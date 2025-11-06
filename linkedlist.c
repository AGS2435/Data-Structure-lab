#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};


struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertAtFirst(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}


void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}


void insertAtPosition(struct Node **head, int data, int position) {
    if (position == 0) {
        insertAtFirst(head, data);
        return;
    }

    struct Node *newNode = createNode(data);
    struct Node *temp = *head;

    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


void deleteFromFirst(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = temp->next;
    printf("Deleted node with data %d from beginning.\n", temp->data);
    free(temp);
}


void deleteFromEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head;


    if (temp->next == NULL) {
        printf("Deleted node with data %d from end.\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }


    while (temp->next->next != NULL)
        temp = temp->next;

    printf("Deleted node with data %d from end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}


void deleteAtPosition(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 0) {
        deleteFromFirst(head);
        return;
    }

    struct Node *temp = *head;

    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }

    struct Node *next = temp->next->next;
    printf("Deleted node with data %d from position %d.\n", temp->next->data, position);
    free(temp->next);
    temp->next = next;
}


void print(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void freeList(struct Node **head) {
    struct Node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct Node *head = NULL;
    int choice, data, position;

    while (1) {
        printf("\n Singly Linked List Menu\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtFirst(&head, data);
            break;
        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 3:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position (starting from 0): ");
            scanf("%d", &position);
            insertAtPosition(&head, data, position);
            break;
        case 4:
            deleteFromFirst(&head);
            break;
        case 5:
            deleteFromEnd(&head);
            break;
        case 6:
            printf("Enter position to delete (starting from 0): ");
            scanf("%d", &position);
            deleteAtPosition(&head, position);
            break;
        case 7:
            print(head);
            break;
        case 8:
            freeList(&head);
            printf("Exiting program\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
