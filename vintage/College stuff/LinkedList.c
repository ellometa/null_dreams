#include <stdio.h>
#include <stdlib.h>

typedef struct NodeKaStruct {
    int val;
    struct NodeKaStruct* prev;
    struct NodeKaStruct* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = data;
    newNode->prev = newNode;
    newNode->next = newNode;
    return newNode;
}

void display(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = head;
    do {
        printf("%d <--> ", current->val);
        current = current->next;
    } while (current != head);
    printf("(head)\n");
}

Node* insertEnd(Node* head, int n) {
    Node* newNode = createNode(n);
    if (head == NULL) {
        return newNode;
    }
    Node* tail = head->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    return head;
}

Node* deleteNode(Node* head, int n) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    Node* current = head;
    do {
        if (current->val == n) {
            if (current->next == current) {
                free(current);
                return NULL;
            }
            if (current == head) {
                head = head->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            return head;
        }
        current = current->next;
    } while (current != head);
    printf("Node with data %d not found.\n", n);
    return head;
}

Node* search(Node* head, int n) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    Node* current = head;
    do {
        if (current->val == n) {
            return current;
        }
        current = current->next;
    } while (current != head);
    return NULL;
}

int main() {
    Node* head = NULL;
    int choice, data;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create list\t\t");
        printf("2. Insert at end\t\t");
        printf("3. Delete node\t\t");
        printf("4. Display list\t\t");
        printf("5. Search node\t\t");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter data for first node: ");
            scanf("%d", &data);
            head = insertEnd(head, data);
            char ch = 'y';
            while (ch == 'y' || ch == 'Y') {
                printf("Enter data for next node: ");
                scanf("%d", &data);
                head = insertEnd(head, data);
                printf("Do you want to continue? (y/n): ");
                getchar();
                scanf("%c", &ch);
            }
            break;
        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            head = insertEnd(head, data);
            printf("Node inserted.\n");
            break;
        case 3:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            head = deleteNode(head, data);
            break;
        case 4:
            display(head);
            break;
        case 5: {
            printf("Enter data to search: ");
            scanf("%d", &data);
            Node* result = search(head, data);
            if (result != NULL) {
                printf("Node with data %d found.\n", result->val);
            } else {
                printf("Node with data %d not found.\n", data);
            }
            break;
        }
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
