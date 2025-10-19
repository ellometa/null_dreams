#include <stdio.h>

int main(){
    
    int n = 5;
    printf("Enter your number: ");
    scanf("%d", &n);
    
    printf("\n");
    for(int i = 1; i <= n; i++){
        
        for(int j = 0; j < n-i; j++){
            printf("    ");
        }
        for (int k = 2 ; k <= 2*(i); k+=1){
            printf(" *  ");
        }
        printf("\n");
    }
    
    return 0;
        
}


// Write a program in C to make such a pattern like a right angle triangle with a number which will repeat a number in a row or as pattern given below

//             *
//         *   *   *
//     *   *   *   *    *
// *   *   *   *   *    *    *
