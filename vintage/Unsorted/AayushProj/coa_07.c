#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CACHE_SIZE 8
#define REF_LEN 16
#define MAX_PAGE 10

typedef struct Node {
    int page;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
    int count;
} Queue;

Node* newNode(int page) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->page = page;
    temp->next = NULL;
    return temp;
}

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
    q->count = 0;
}

void enqueue(Queue* q, int page) {
    Node* temp = newNode(page);

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        q->count = 1;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
    q->count++;
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }

    Node* temp = q->front;
    int removed_page = temp->page;

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->count--;
    return removed_page;
}

int is_in_cache(Queue* q, int page) {
    Node* current = q->front;
    while (current != NULL) {
        if (current->page == page) {
            return 1;   
        }
        current = current->next;
    }
    return 0;
}

void printQueue(Queue* q) {
    Node* current = q->front;
    int printed = 0;

    
    while (current != NULL) {
        
        printf("%d ", current->page);
        printed += 2;
        current = current->next;
    }

    while (printed < 30) {
        putchar(' ');
        printed++;
    }
}

int main(void) {
    int reference_string[REF_LEN];
    Queue cache;
    int hits = 0;

    initQueue(&cache);

    srand((unsigned)time(NULL));
    for (int i = 0; i < REF_LEN; i++) {
        reference_string[i] = rand() % MAX_PAGE;
    }

    printf("Cache size (Frames): %d\n", CACHE_SIZE);
    printf("Reference string: ");
    for (int i = 0; i < REF_LEN; i++) {
        printf("%d ", reference_string[i]);
    }
    printf("\n\n");

    printf("Step\tRef\tCache State (Oldest -> Newest)        Hit/Miss\n");

    int step = 1;
    for (int i = 0; i < REF_LEN; i++) {
        int current_page = reference_string[i];
        int found = is_in_cache(&cache, current_page);

        printf("%d\t%d\t", step++, current_page);

        if (found) {
            hits++;
            printQueue(&cache);
            printf("Hit\n");
        } else {
            if (cache.count == CACHE_SIZE) {
                dequeue(&cache);
            }
            enqueue(&cache, current_page);
            printQueue(&cache);
            printf("Miss\n");
        }
    }

    printf("\nTotal References: %d\n", REF_LEN);
    printf("Total Hits: %d\n", hits);
    printf("Total Faults: %d\n", REF_LEN - hits);
    printf("Hit ratio: %.2f\n", (float)hits / REF_LEN);


    while (cache.front != NULL) {
        dequeue(&cache);
    }

    return 0;
}
