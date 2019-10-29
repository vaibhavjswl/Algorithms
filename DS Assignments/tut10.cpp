#include <stdio.h>
#include <stdlib.h>

struct Record{
    int rollNo;
    char name[25] ;
    int m1 , m2 , m3 ;
}r ;

void dispay (FILE *fptr){
    rewind(fptr) ;
    int i = 0 ;
    while(fscanf(fptr , "%d %s %d %d %d" , &r.rollNo , r.name , &r.m1 , &r.m2 , &r.m3)!= EOF){
        printf("Student %d\n",++i) ; 
        printf("ROLL NO : %d \nNAME: %s\nMarks 1 : %d\nMarks 2 : %d\nMarks 3: %d\n" , r.rollNo , r.name , r.m1 ,r.m2, r.m3) ;
    }
}

int search(FILE *fptr , int key){
    rewind(fptr) ;

    while(fscanf(fptr , "%d%s%d%d%d" , &r.rollNo , r.name , &r.m1 , &r.m2 , &r.m3)!=EOF){
        if (key==r.rollNo)
            return 1;
    }
    return 0 ; 
}
int main(){
    int n ; 

    printf("how Many Records do you want to enter :") ;
    scanf("%d" , &n) ;

    FILE *fptr ;
    fptr = fopen("records.txt","w") ;

    if(fptr == NULL){
        printf("[ERROR] -> Opening FIle Unsuccessfull \n");
    }
    else{
        int i ;

        for(i=0; i<n ; i++){
            printf("Enter Roll No : ") ;
            scanf("%d" , &r.rollNo) ;

            printf("Enter Name : ") ;
            scanf("%s" , r.name) ;

            printf("Enter Marks sof 3 subjects  : ") ;
            scanf("%d%d%d" , &r.m1 , &r.m2 , &r.m3) ;

            fprintf(fptr , "%d %s %d %d %d\n",r.rollNo , r.name , r.m1 , r.m2 , r.m3) ;
        }

        fclose(fptr) ;
        fptr = fopen("records.txt" , "r");

        printf("Records Stored are \n");

        dispay(fptr) ; 

        int key ;
        printf("\n\n\ENter which roll no to search :") ;
        scanf("%d" ,&key ) ;

        if(search(fptr , key)==1)
            printf("Record Found in Database\n");
        else{
            printf("Record Not Found in Database\n");
        }
    }
}