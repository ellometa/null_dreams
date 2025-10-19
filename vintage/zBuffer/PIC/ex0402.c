#include <stdio.h>

int main(){
    int n = 3;
    printf("Enter your desired length: ");
    scanf("%d", &n);
    int arr[n];
    int x = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        arr[i]=x;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Ascending: \n");    
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\nDescending: \n");
    for (int i = n-1; i >= 0; i--){
        printf("%d ", arr[i]);
    }    
    return 0;
}