#include <stdio.h>

int main(){
    
    char str[100] = "";
    printf("Enter your string:");
    fgets(str, sizeof(str), stdin);
    printf("%s", str);
    int i = 0;
    int ascii, vowelcount = 0, constantcount = 0;
    
    while (str[i]!='\0'){
        ascii = (int)str[i];
        if (ascii >=91 && ascii <= 122){ 
            ascii-=32;
        }
        
        if ( ascii>=65 && ascii <=90){
            if (ascii == 65 || ascii == 69 || ascii == 73 || ascii == 79 || ascii == 85){
                vowelcount+=1;
            }
            else{
                constantcount+=1;
            }
        }
        i++;
    }
    
    printf("\nVowels: %d\nConstants: %d", vowelcount, constantcount);
    return 0;
        
}