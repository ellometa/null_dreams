#include <stdio.h>

int main(){
    
    int n = 3;
    printf("Enter your number: ");
    scanf("%d", &n);
    
    float sum = 0.0;
    
    for (int i = 1; i <= n; i++){
        sum = sum + (1.0/i);
        if (i==n){
            printf("1/%d", i);
            break;
        }
        printf ("1/%d + ", i);
    }
    
    printf("\nSum: %f", sum);
    
    
    return 0;
        
}

