#include <stdio.h>

int main(){
    
    int n = 3;
    printf("Enter your number: ");
    scanf("%d", &n);
    int pow, sum = 0;
    
    for (int i = 1; i <= n ; i++){
        pow = i*i;
        printf("%d ", pow);
        sum += pow;
    }
    printf("\nSum: %d", sum);
    return 0;
        
}

