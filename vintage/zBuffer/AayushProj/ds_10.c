#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void rdm(int arr[], int n, int maxValue) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % maxValue;
}

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("pass %d: ", i + 1);
        printArray(arr, n);
    }
}

void shellSort(int arr[], int n) {
    int it = 1;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        printf("After gap %d pass %d: ", gap, it++);
        printArray(arr, n);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr1 = malloc(n * sizeof(int));
    int *arr2 = malloc(n * sizeof(int));

    srand((unsigned)time(NULL));

    rdm(arr1, n, 100);
    for (int i = 0; i < n; i++)
        arr2[i] = arr1[i];

    printf("\nOriginal array:\n");
    printArray(arr1, n);

    printf("\nBubble Sort Process:\n");
    bubbleSort(arr1, n);

    printf("\nShell Sort Process:\n");
    shellSort(arr2, n);

    free(arr1);
    free(arr2);
    return 0;
}
