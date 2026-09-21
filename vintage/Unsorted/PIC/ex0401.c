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
    
    printf("Reversed array: \n");
    
    
    
    for (int i = n-1; i >= 0; i--){
        printf("%d ", arr[i]);
    }
    
    
    return 0;
}