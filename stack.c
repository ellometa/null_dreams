#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
    int array[MAX];
    int front;
    int rear;
} QueueDef;

void initQ(QueueDef* Q){
    Q->front = -1;
    Q->rear = 0;
}

//CHECK EMPTY
int isEmpty(QueueDef* Q){
    return (Q->front == Q->rear-1);
}
//CHECK FULL
int isFull(QueueDef* Q){
    return (Q->front == MAX);
}
//ENQ
void enQ(QueueDef* Q, int val){
    if (isFull(Q)){
        printf("Queue is full, Overflow.\n");
        return;
    }

    Q->array[Q->rear]=val;
    Q->rear+=1;

}
//DEQ
void deQ(QueueDef* Q){
    if (isEmpty(Q)){
        printf("Queue is empty, lol.\n");
        return;
    }
    int printval = Q->front;
    printf("Dequeued value: %d\n", printval);
    Q->front+=1;

}
//DESTROY
void destroy(QueueDef* Q){
    if (isEmpty(Q)){
        printf("Queue is empty, lol.\n");
        return;
    }
    printf("Destroying your Queue");
    Q->front = 0;
    Q->rear = 0;
}

//DISPLAYQ
void displayQ(QueueDef* Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue contents: ");
    for (int i = Q->front; i < Q->rear; i++) {
        printf("%d ", Q->array[i]);
    }
    printf("\n");
}
//MENU

//MAIN
int main() {
    QueueDef kyu;
    initQ(&kyu);

    int choice, val;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Destroy\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &val);
            enQ(&kyu, val);
            break;
        case 2:
            deQ(&kyu);
            break;
        case 3:
            displayQ(&kyu);
            break;
        case 4:
            destroy(&kyu);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
