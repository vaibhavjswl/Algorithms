#include<stdio.h>
#include <string.h>
#include <stdlib.h>


struct student
{
	long long int prn;
	char firstname[30],lastname[30];
	float phy,chem,math;
}stu[100];

int enteries=0;


void creation();
void displayall();
void displaystud(int entry);
void modify();
void deletbyprn();
void deletbypos();
int  search(double );
int  searchbyname(char firstname[30],char lastname[30]);
void sortbyname();
void sortbytotalmarks();


int main()
{
	int choice;
	char exit,firstname[30],lastname[30];
	long long int prnquery;
	int result;

	do
	{

	printf("\nEnter:\n");
	printf(" 1. Create\n");
	printf(" 2. Display all\n");
	printf(" 3. Modify\n");
	printf(" 4. Delete by PRN\n");
	printf(" 5. Delete by Position\n");
	printf(" 6. Search By PRN\n");
	printf(" 7. Search By Name\n");
	printf(" 8. Sort By total marks\n");
	printf(" 9. Sort By Name\n");
	printf(" 10. Exit\n");

	printf("Your Choice : ");
	scanf ("%d",&choice);

		switch(choice)
		{
			case 1: creation();
			        break;

			case 2: displayall();
			        break;

			case 3: modify();
			        break;

			case 4: deletbyprn();
			        break;
            case 5: deletbypos();
			        break;

			case 6: printf("Enter the PRN to search : ");
			        scanf("%lld",&prnquery);
			        result = search(prnquery);
			        if ( result != -1)
			        {
			         displaystud(result);
                    }

                    else printf("Entered query has returned no result\n");
			        break;


            case 7: printf("Enter the Name to search : ");
			        scanf("%s %s",firstname,lastname);
			        result = searchbyname(firstname,lastname);
			        if ( result != -1)
			        {
			         displaystud(result);
                    }

                    else printf("Entered query has returned no result\n");
			        break;

            case 8:
                    displayall();
                    sortbytotalmarks();
                    printf("\nAfter Sorting by total Marks\n");
                    displayall();
                    break;

            case 9:
                    displayall();
                    sortbyname();
                    printf("\nAfter Sorting by Name");
                    displayall();
                    break;

			case 10:
			       goto exit1;

			default: printf("invalid choice entered\n");
		}

	puts("Enter y to go back to menu and n to exit");
	printf("Choice : ");
	getchar();
	scanf("%c",&exit);

    }while (exit=='y');
    exit1:;
    return 0;
}

void creation()
{
	printf ("\n\nEnter PRN of Student : ");
	scanf("%lld",&stu[enteries].prn);

	printf ("Enter The Name Of Student : ");
	fflush(stdin);
	scanf("%s %s",stu[enteries].firstname,stu[enteries].lastname);

	printf("Enter Marks of Physics : ");
	scanf("%f",&stu[enteries].phy);

	printf("Enter Marks of Chemistry : ");
	scanf("%f",&stu[enteries].chem);

	printf("Enter Marks of Maths : ");
	scanf("%f",&stu[enteries].math);

	enteries++;

}

void displayall()
{
	int count;
	printf("\n\n");
	for (count=0;count<enteries;count++)
	{
		printf ("%d. PRN  :  %lld  ,  ",count+1,stu[count].prn);
		printf("NAME : ");
		printf("%s %s ",stu[count].firstname,stu[count].lastname);
        printf(" -> Marks: Phy : %.2f , Chem : %.2f , Maths : %.2f\n",stu[count].phy,stu[count].chem,stu[count].math);
	}
}

void displaystud(int entry)
{
	printf("\n\n");

    printf ("%d. PRN  :  %lld  ,  ",entry+1,stu[entry].prn);
    printf("NAME : ");
    printf("%s %s ",stu[entry].firstname,stu[entry].lastname);
    printf(" -> Marks: phy : %.2f , chem : %.2f , maths : %.2f\n",stu[entry].phy,stu[entry].chem,stu[entry].math);
}

void modify()
{
	long long int entry;
	int count,choice,subchoice;
	displayall();

	printf ("\nEnter the PRN Number Which you want to change\n");
	scanf ("%lld",&entry);
	count = search(entry);

	printf("Enter Which Entity you want to modify\n");
	printf("1.PRN\n2.Name\n3.Marks\n4.All of above\n");
	printf("Your Choice :");
	scanf("%d",&choice);

    switch (choice)
    {

	case 1: printf ("\nEnter PRN of Student : ");
            scanf("%lld",&stu[count].prn);
            break;

	case 2: printf ("Enter The Name Of Student : ");
            scanf("%s %s",stu[count].firstname,stu[count].lastname);
            break;
    case 3:
            printf("Enter which subject marks to change\n");
            printf("1.Physics\n2.Chemistry\n3.Maths\n");
            printf("Your choice : ");
            scanf("%d",&subchoice);

            switch(subchoice)
            {
              case 1 : printf("Enter Physics Marks : ");
                       scanf("%f",&stu[count].phy);
                       break;

              case 2 : printf("Enter Chemistry Marks : ");
                       scanf("%f",&stu[count].chem);
                       break;


              case 3 : printf("Enter Maths Marks : ");
                       scanf("%f",&stu[count].math);
                       break;
            }
            break;
	}
	printf("After Modification Data is \n\n");
	displayall();
}

void deletbyprn()
{

	int count ,check;
	long long int entry;
	displayall();

	printf ("Enter the PRN Number Which you want to delete\n");
	scanf ("%lld",&entry);
	check = search(entry);

	if(check!=-1)
	{
        for (count=check;count<enteries;count++)
        {
            stu[count]=stu[count+1];
        }
        enteries--;

        printf("After Modification Data is \n\n");
        displayall();
    }
}

void deletbypos()
{

	int count;
    int entry;
	displayall();

	printf ("Enter the Entry Number you want to delete\n");
	scanf ("%d",&entry);
	entry--;

	if(!(entry < 0 && entry>enteries))
	{
        for (count=entry;count<enteries;count++)
        {
            stu[count]=stu[count+1];
        }
        enteries--;
        printf("After Modification Data is \n\n");
        displayall();
    }
}

int  search(double prnquery)
{
        int count,flag=1;

		for (count=0;count<enteries;count++)
		{
			if(stu[count].prn==prnquery)
			 {
				return count;
		        break;
			 }
			else flag=0;
		}
		if (flag==0) return -1;
}

int  searchbyname(char firstname[30],char lastname[30])
{
        int count,flag=1;

		for (count=0;count<enteries;count++)
		{
			if(strcmp(stu[count].firstname,firstname)==0 && strcmp(stu[count].lastname,lastname)==0)
			{
				return count;
		        break;
			}
			else flag=0;
		}
		if (flag==0) return -1;
}

void sortbyname()
{
  struct student temp;
  int i,j;

  for(i=0;i<enteries-1;i++)
      {
          for (j=i+1;j<enteries;j++)
          {
            if (strcmp(stu[i].firstname,stu[j].firstname)>0)
            {
                temp=stu[i];
                stu[i]=stu[j];
                stu[j]=temp;
            }
          }
      }
}

void sortbytotalmarks()
{
  struct student temp;
  int i,j;

  for(i=0;i<enteries-1;i++)
      for (j=i+1;j<enteries;j++)
      {
        if ((stu[i].phy+stu[i].chem+stu[i].math)<(stu[j].phy+stu[j].chem+stu[j].math))
        {
              temp=stu[i];
              stu[i]=stu[j];
              stu[j]=temp;
        }
      }
}
