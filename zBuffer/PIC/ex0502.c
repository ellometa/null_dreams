#include <stdio.h>
#include <string.h>

int main(){
    // Input the student's name and grade (two strings).
    char name[100] = "";
    printf("Enter your Name:");
    fgets(name, sizeof(name), stdin);
    char grade[100] = "";
    printf("\nEnter your Grade:");
    fgets(grade, sizeof(grade), stdin);
    
    // Display the length of both the student's name and grade.
    
    printf("\nLength of name: %ld", strlen(name));
    printf("\nLength of Grade: %ld", strlen(grade));
    
    // Copy the student's name into a new string and display it.
    char copyname[100];
    strcpy(copyname, name);
    printf("\nstrcpy(copyname, name)\ncopyname: %s",copyname);
    
    // Concatenate a fixed string (e.g., " - Excellent Student") 
    // to the student's name and display the result.
    char ccat[50] = " - Excellent Student";
    strcat(copyname, ccat);
    printf("\nstrcat(copyname, ccat): \ncopyname: %s", copyname);
    
    // Compare two students' names lexicographically and 
    // display which student has the lexicographically greater name
    
    char name2[100] = "";
    printf("\nEnter second name to be compared: ");
    fgets(name2, sizeof(name2), stdin);
    
    int result = strcmp(name, name2);

    if (result > 0) {
        printf("%s is greater than %s.\n", name, name2);
    } else if (result < 0) {
        printf("%s is greater than %s.\n", name2, name);
    } else {
        printf("Both names are equal.\n");
    }
    
    //	Search for a substring in the student's name (e.g., "John" in "Johnny")
    //  and display the position of the first occurrence.
    
    char search[100] = "";
    printf("\nEnter second name to be searched: ");
    fgets(search, sizeof(search), stdin);
    
    char *pos = strstr(name, search);

    if (pos != NULL) {
        printf("\nName found at position: %ld", pos - name + 1);
    } else {
        printf("\nName not found.");
    }
    
    // Search for a character in the grade string (e.g., 'A') 
    // and display the position of the first occurrence.
    
    char gradesearch[100] = "";
    printf("\nEnter grade to be searched: ");
    fgets(gradesearch, sizeof(gradesearch), stdin);
    
    char *pos2 = strstr(grade, gradesearch);

    if (pos2 != NULL) {
        printf("\nGrade found at position: %ld", pos2 - grade + 1);
    } else {
        printf("\nGrade not found.");
    }
    
    
    return 0;

}