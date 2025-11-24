#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int v, e;
int mat[MAX][MAX];
int visited[MAX];

void dfs(int node) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < v; i++) {
        if (mat[node][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

void bfs(int start) {
    int queue[MAX];
    int front = 0, rear = 0;
    int visitedB[MAX] = {0};

    queue[rear++] = start;
    visitedB[start] = 1;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < v; i++) {
            if (mat[node][i] == 1 && !visitedB[i]) {
                queue[rear++] = i;
                visitedB[i] = 1;
            }
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &v);

    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            mat[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < e; i++) {
        int s, d;
        scanf("%d %d", &s, &d);
        mat[s][d] = 1;
        mat[d][s] = 1;
    }

    int choice;
    while (1) {
        printf("1. DFS\n2. BFS\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < v; i++)
                    visited[i] = 0;
                printf("DFS from node 0: ");
                dfs(0);
                printf("\n");
                break;

            case 2:
                printf("BFS from node 0: ");
                bfs(0);
                printf("\n");
                break;

            default:
                printf("Invalid\n");
        }
    }

    return 0;
}
