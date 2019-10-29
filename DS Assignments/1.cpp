
#include <stdio.h>
#include <string>

using namespace std ; 

int main(){

    FILE *fptr = fopen("Hello.txt" , "w") ;
    char ch[20] ; 
    if (fptr==NULL){

        printf("[ERROR] -> File could not be opened.") ;
    }
    else{
        printf("Enter something to write in the file ") ;
        gets(ch) ; 

        fprintf(fptr , ch) ;
    }

    fclose(fptr) ;
    return 0 ;

}