#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int arr[MAX];

int hash_function(int k) {
    return k % MAX;
}

int l_insert(int key) {
    int idx = hash_function(key);
    if (arr[idx] == -1) {
        arr[idx] = key;
    } else {
        int i = 1;
        while (arr[(idx + i) % MAX] != -1) {
            i++;
        }
        arr[(idx + i) % MAX] = key;
    }
    return 0;
}

int q_insert(int key) {
    int idx = hash_function(key);
    if (arr[idx] == -1) {
        arr[idx] = key;
    } else {
        int i = 1;
        while (arr[(idx + i * i) % MAX] != -1 && i < MAX) {
            i++;
        }
        if (i < MAX)
            arr[(idx + i * i) % MAX] = key;
        else
            printf("\nHash table full!\n");
    }
    return 0;
}

int search(int ele) {
    int idx = hash_function(ele);
    if (arr[idx] == ele) {
        return idx;
    } else {
        int i = 1;
        while (arr[(idx + i) % MAX] != -1) {
            if (arr[(idx + i) % MAX] == ele) {
                return (idx + i) % MAX;
            } else {
                i++;
            }
        }
    }
    return -1;
}

void delete(int ele) {
    int pos = search(ele);
    if (pos != -1) {
        arr[pos] = -1;
        printf("\nElement %d deleted.\n", ele);
    } else {
        printf("\nElement not found.\n");
    }
}

void display(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, n, key, idx, ele;

    for (int i = 0; i < MAX; i++)
        arr[i] = -1;

    do {
        printf("\nEnter:\n"
               "1. To insert with linear probing\n"
               "2. To insert with quadratic probing\n"
               "3. Display\n"
               "4. Searching\n"
               "5. Deletion\n"
               "6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements (<= 10): ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &key);
                    l_insert(key);
                }
                break;

            case 2:
                printf("Enter the number of elements (<= 10): ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &key);
                    q_insert(key);
                }
                break;

            case 3:
                display(MAX);
                break;

            case 4:
                printf("Enter element to search: ");
                scanf("%d", &ele);
                idx = search(ele);
                if (idx != -1)
                    printf("Element %d found at index %d\n", ele, idx);
                else
                    printf("Element not found\n");
                break;

            case 5:
                printf("Enter element to delete: ");
                scanf("%d", &ele);
                delete(ele);
                break;

            case 6:
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}
