#include <stdio.h>

int main(){
    
    int n = 9;
    printf("Enter your number: ");
    scanf("%d", &n);
    
    
    int first = 1, second = 1;
    int i = 1;
    do{
        
        
        printf("%d, ", first);
        
        second += first;
        
        first = second - first;
        
        ++i;
    }
    while (i-1 < n);
    
    
    return 0;
        
}

