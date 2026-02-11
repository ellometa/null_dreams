#include <stdio.h>

void merge(int arr[], int left, int pivot, int right) {
    int i, j, k;
    int n1 = pivot - left + 1;
    int n2 = right - pivot;

    int LeftArray[n1];
    int RightArray[n2];

    for (i = 0; i < n1; i++) {
        LeftArray[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        RightArray[j] = arr[pivot + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (LeftArray[i] <= RightArray[j]) {
            arr[k] = LeftArray[i];
            i++;
        }
        else {
            arr[k] = RightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = LeftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = RightArray[j];
        j++;
        k++;
    }
}

void sort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = (left + right) / 2;

        sort(arr, left, pivot);
        sort(arr, pivot + 1, right);

        merge(arr, left, pivot, right);
    }
}

int main() {
    int my_numbers[] = {12, 11, 13, 5, 6, 7};
    int size = 6; 
    int i;

    printf("Numbers before sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", my_numbers[i]);
    }
    printf("\n");

    sort(my_numbers, 0, size - 1);

    printf("Numbers after sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", my_numbers[i]);
    }
    printf("\n");

    return 0;
}
