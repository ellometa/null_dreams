#include <stdio.h>

int increment(int var){
    var+=1;
    return var;
}


int main(){
    int num1 = 20;
    int num2 = increment(num1);
    
    printf("\nnum1 value is %d", num1);
    printf("\nnum2 value is %d", num2);
    return 0;
}