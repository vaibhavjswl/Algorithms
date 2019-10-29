#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

struct employee
{
    int no;
    char name[25];
    int basic , grade ;
}emp ,emp2 , empn[50] , temp;

int recsize = sizeof(emp);

int main()
{
    FILE *fp ;


    int choice ;
    char exit = 'n';
    int i;

    if (fp == NULL) printf("File open Failed\n");

    do
    {
         fp = fopen("employedata.txt","a+");

        printf("\n\n1. Add Record \n");
        printf("2. Show All Record \n");
        printf("3. Delete  Record \n");
        printf("4. To Sort The Record Alphabetically \n");
        printf("5. To Find Missing Employee Numbers \n");
        printf("6. Exit \n");
        printf("Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                       fseek(fp , 0 , SEEK_END);
                       {
                           printf("Enter Employee Number : ");
                           scanf("%d",&emp.no);
                           printf("Enter Employee Name : ");
                           scanf("%s",emp.name);
                           printf("Enter Employee Basic Pay : ");
                           scanf("%d",&emp.basic);
                           printf("Enter Employee Grade Pay : ");
                           scanf("%d",&emp.grade);

                            fwrite(&emp , sizeof(emp) , 1 , fp);

                           break;
                       }

            case 2:
                {
                    rewind(fp);
                    printf("Emp no  Emp Name  Basic pay  Grade Pay\n");
                    while (fread(&emp , sizeof(emp) , 1 , fp) == 1)
                    {
                        printf("%d\t%s\t  %d\t\t%d\t\n",emp.no,emp.name,emp.basic,emp.grade);
                    }
                    break;
                }

            case 3:
                {
                    int count = 0 ;
                    int record_no;

                    FILE *ftemp ;
                    ftemp = fopen("temp.txt" , "a+");

                    rewind(fp);
                    printf("Emp no  Emp Name  Basic pay  Grade Pay\n");
                    while (fread(&emp , sizeof(emp) , 1 , fp) == 1)
                        {
                            printf("%d\t%s\t  %d\t\t%d\t\n",emp.no,emp.name,emp.basic,emp.grade);
                        };

                    printf("Enter Emp no of  Record to Delete :");
                    scanf("%d",&record_no);

                    rewind(fp);
                    while (fread(&emp , sizeof(emp) , 1 , fp) == 1)
                        {
                            empn[count++] = emp ;
                        }

                    for (i = 0 ; i<count ; i++)
                    {
                        if (record_no != empn[i].no)
                        {
                            fwrite(&empn[i] , sizeof(emp) , 1 , ftemp);
                        }
                    }

                    fclose(fp) ;
                    fclose(ftemp);
                    remove("employedata.txt");
                    rename("temp.txt" , "employedata.txt");

                    fp = fopen("employedata.txt", "a+");
                    break;
                }

            case 4 :
                {
                     int count = 0  , j ,i ;

                    rewind(fp);
                    while (fread(&emp , sizeof(emp) , 1 , fp) == 1)
                    {
                        count++;
                    }

                    i=0;

                 rewind(fp);
                    while (i<count)
                    {
                        fread(&empn[i], sizeof(emp) , 1 , fp);
                        i++;
                    }
                   rewind(fp);

                    for (i = 0 ; i<count-1; i++)
                    {
                        for ( j = i ; j<count - i-1 ; j++)
                        {
                             if (strcmp(empn[j].name , empn[j+1].name)>0)
                             {
                                 temp = empn[j];
                                 empn[j] = empn[j+1];
                                 empn[j+1] = temp ;
                             }
                        }
                    }

                    rewind(fp);

                    fp = fopen("employedata.txt", "w");

                    for (i = 0 ; i<count; i++)
                    {
                        fwrite(&empn[i] , sizeof(emp), 1 , fp);
                    }

                    break;
                }


            case 5:
                {
                    int arr[50],size=0 , i,tempno,count = 0 , j;

                    while (fread(&emp , sizeof(emp) , 1 , fp) == 1)
                    {
                        empn[size++] = emp;
                    }

                    i=0;

                    while (i < size )
                    {
                        arr[i] = empn[i].no;
                        i++;
                    }

                    for (i = 0 ; i<size-1 ; i++)
                    {
                        for (j=i+1 ; j<size ; j++)
                        {
                            if (arr[i] > arr[j])
                            {
                                tempno = arr[i];
                                arr[i] = arr[j];
                                arr[j] = tempno;
                            }
                        }
                    }

                    i=0 ; j=0;
                    while (i<arr[size-1])
                    {
                        if (i != arr[j]) printf("Emp no %d is absent \n",i);
                        else j++;

                        i++;
                    }
                }
                break;

            case 6: exit = 'y';
        }
        fclose(fp);
    }while(exit!='y');

    fclose(fp);
}
