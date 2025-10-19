#include <stdio.h>
#include <stdlib.h>

typedef struct StackKaStruct {
    int data;
    struct StackKaStruct* next;
} StackKaStruct;

typedef struct Stack {
    StackKaStruct* top;
    int size;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

void insert(Stack* stack, int data) {
    StackKaStruct* element = (StackKaStruct*)malloc(sizeof(StackKaStruct));
    element->data = data;
    element->next = stack->top;
    stack->top = element;
    stack->size++;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = stack->top->data;
    StackKaStruct* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}

void display(Stack* stack) {
    StackKaStruct* temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int isEmpty(Stack* stack) {
    return stack->size == 0;
}

int main() {
    Stack* stack = createStack();
    int choice, data;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\t\t");
        printf("2. Pop\t\t");
        printf("3. Peek\t\t");
        printf("4. Display\t\t");
        printf("5. Check if empty\t\t");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                insert(stack, data);
                break;

            case 2:
                data = pop(stack);
                if (data != -1) {
                    printf("Popped: %d\n", data);
                }
                break;

            case 3:
                data = peek(stack);
                if (data != -1) {
                    printf("Peek: %d\n", data);
                }
                break;

            case 4:
                printf("Stack: ");
                display(stack);
                break;

            case 5:
                printf("Is stack empty? %s\n", isEmpty(stack) ? "Yes" : "No");
                break;

            case 6:
                exit(0);
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
