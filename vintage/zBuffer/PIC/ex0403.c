#include <stdio.h>

int main() {
    int n;
    printf("Enter your desired length: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int counter = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {  
            if (arr[i] == arr[j]) {
                counter++;
            }
        }
    }

    printf("Count of duplications: %d\n", counter);

    return 0;
}
