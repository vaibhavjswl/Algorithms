#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

typedef struct
{
	int prn ;
	char name[25] ;
	int m1, m2 , m3 ;
	int chain ;
}student ;

int hash (int X)
{
	return (X%10);
}

void insert(FILE* recordfile)
{
    student s;
	printf("\nEnter PRN:");
	scanf("%d",&s.prn) ;
	
	printf("\nEnter name:");
	scanf("%s",s.name);
	
	printf("\nEnter marks:");
	scanf("%d%d%d",&s.m1,&s.m2,&s.m3) ;
	
	s.chain = -1;

    long int pos = hash(s.prn) ;
	
	int flag = 0;

	fseek(recordfile,pos*sizeof(student),SEEK_SET);
	
	student temp;
	
	fread(&temp,sizeof(temp),1,recordfile);
	
	
	if(temp.prn==0)  // checks for empty slot
	{
		flag = 1;
		fseek(recordfile,pos*sizeof(student),SEEK_SET);
		fwrite(&s,sizeof(s),1,recordfile);
		return ;
	}

    else
{
     while(temp.chain != -1)
        {
	fseek(recordfile,temp.chain*sizeof(student),SEEK_SET);
	pos = temp.chain ;
	fread(&temp,sizeof(temp),1,recordfile);
         }
        flag = 2 ;
 }

long int emptySlot = pos ;
student replace = temp  ; 
	
while(fread(&temp,sizeof(temp),1,recordfile))
{
       if(temp.prn==0)
        {
           fseek(recordfile,(emptySlot+1)*sizeof(student),SEEK_SET) ;
           fwrite(&s,sizeof(s),1,recordfile);
           if(flag==2)
           {
             fseek(recordfile,pos*sizeof(student),SEEK_SET);
             replace.chain = emptySlot + 1 ; 
	         fwrite(&replace,sizeof(student),1,recordfile);
           }	
	flag = 1 ;       //flag = 1 indicates successful insertion
	break;
        }
    emptySlot++;	
 }

	if(flag!=1)
	{
		printf("\nError:Record cannot be inserted!");
	}
	return ;
}

int search(FILE* fptr)
{
	printf("\nEnter PRN of student you want to search:");
	int prn ;
	scanf("%d",&prn);
	
	student temp ;
	
	int pos = hash(prn) ;
	fseek(fptr,pos*sizeof(student),SEEK_SET);

    while(fread(&temp,sizeof(student),1,fptr))
	{
		if(temp.prn==prn)
		{
			printf("\nStudent with prn %d is found",temp.prn) ;
			printf("\nDetails are:\n");
			printf("\nName: %s",temp.name);
			printf("\nMarks:%d %d %d",temp.m1,temp.m2,temp.m3) ;
			return 1; 
		}

        else 
		{
		 if(pos==hash(temp.prn))
		   	{
		   	   if(temp.chain!=-1)			                                        
                    fseek(fptr,temp.chain*sizeof(student),SEEK_SET);
			}
		}
	}
	printf("\nError:Record does not exist!");
	return 0; 
}

int main(){


    int choice ; 
    char exit='n' ; 
    FILE *fptr = fopen("student.txt","rw+") ; 

    do{
    printf("\nEnter\n");
    printf("1. Add Data :\n");
    printf("2. Search Data:\n");
    printf("3. exit:\n");
    
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        insert(fptr);
        break;
    
    case 2:
        search(fptr);
        break;
    
    case 3:
        exit='y';
        break ;
    default:
        printf("Enter correct input ") ; 
        break;
    }
    }while(exit=='n');
    
    fclose(fptr) ; 
}