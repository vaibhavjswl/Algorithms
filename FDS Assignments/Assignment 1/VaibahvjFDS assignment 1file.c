#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void floydstriangle();
void electricitybill();
void maxmofthreeno();
void simpleinterest();
void reverseNum();
void is_prime();
void is_leapyear();
void array_isprimeandcomposite();
void binarytodecimalconversion();
void decimaltooctalconversion();


main ()
{
	int choice,factr,num;

	menu:
	printf("Enter Desired Option Number \n");
	printf("1.To Print Floyd's Triangle\n");
	printf("2.To Calculate and Print electricity bill\n");
	printf("3.To Print Maxm of three number\n");
	printf ("4. To find Simple Interest of Data Set \n");
	printf ("5. To Reverse a Number\n");
	printf ("6.To find if a number is prime or not\n");
	printf ("7.TO find if a year is leap year or not\n");
	printf ("8.Enter to find prime numbers from one array and composite numbers from another array \n");
	printf("9. To convert a binary number to Decimal Number");
	printf("10.To Convert a Decimal Number to its Octal Number ");

	printf("\nChoice : ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1: floydstriangle();
		        break;
		case 2: electricitybill();
		        break;
		case 3: maxmofthreeno();
		        break;
		case 4: simpleinterest();
		        break;
		case 5: reverseNum();
		        break;
		case 6: is_prime();
		        break;

		case 7 : is_leapyear();
		         break;
		case 8 : array_isprimeandcomposite();
		         break;

		case 9 : binarytodecimalconversion();
		         break;

        case 10 : decimaltooctalconversion();
                  break;

		default: printf("Invalid Input Please try again");
		         goto menu;
	}
}

void floydstriangle()
{
	int row,column,number=1;

	for (row=1;row<=3;row++)
    {
    	for(column=1;column<=row;column++)
    	{
    		printf("%d ",number);
    		number++;
    	}
    	printf("\n");
    }

}

void electricitybill()
{
	float units,bill;

	printf ("Enter the Number of Units Consumed  : ");
	scanf("%f",&units);

	if (units<=50)
	{
		bill=units*0.50;
	}

	else if (units<=150)
	{
		bill= 50*0.50+(units-50)*0.75;
	}

	else if (units<=250)
	{
		bill=50*0.50+100*0.75+(units-150)*1.20;
	}

	else
	{
		bill=50*0.50+100*0.75+100*1.20+(units-250)*1.50;
	}

	bill=bill+(bill*0.20)+(bill*0.10);

	printf("Electricity bill is : %.3f",bill);

}

void maxmofthreeno()
{
    double n1, n2, n3;

    printf("Enter three different numbers: ");
    scanf("%lf %lf %lf", &n1, &n2, &n3);

    if( n1>=n2 && n1>=n3 )
        printf("%.2f is the largest number.", n1);
    if( n2>=n1 && n2>=n3 )
        printf("%.2f is the largest number.", n2);
    if( n3>=n1 && n3>=n2 )
        printf("%.2f is the largest number.", n3);
}

void reverseNum()
{
    int sum=0,rem,num;
    printf("Enter the number : ");
    scanf ("%d",&num);

    while(num > 0)
    {
        rem=num%10;
        sum=(sum*10)+rem;
        num=num/10;
    }

    printf ("Reverse of Number is : %d",sum);
}

void simpleinterest()
{
	float p[3],n[3],r,si[3];
	int element;

	for (element=0;element<3;element++)
	{
	printf("Enter Principal Amount %d : ",element+1);
	scanf ("%f",&p[element]);
	printf ("Enter Number of month %d : ",element+1);
	scanf ("%f",&n[element]);
    }
    printf("Enter Rate of Interest per year : ");
    scanf ("%f",&r);

    for (element=0;element<3;element++)
    {
    	si[element]=p[element]*r*(n[element]/12)*0.01;
    }

    for (element=0;element<3;element++)
    {
    	printf("Simple Intered for Data set %d is : %f \n",element+1,si[element]);
    }

}

void is_prime ()
{
	int number,i,flag=1,j;

	printf ("Enter the number you want to check : ");
	scanf ("%d",&number);

	for (j=2;j<=number;j++)
{
	 flag=1;

	for (i=2;i<=(j/2);i++)
	{
		if (j%i==0) {
			            printf("%d is a composite number\n",j);
			            flag=0;
			            break;
		                 }
	}
	if (flag) printf("%d is prime number \n",j);
}
}

void is_leapyear()
{
	int year;

	printf ("Enter the Year you want to check : ");
	scanf ("%d",&year);

	if (year%400==0) printf ("Year:%d is a leap year\n",year);
	else if (year%100==0) printf("Year:%d is not a leap year",year);
    else if (year%4==0) printf("year : %d is leap year",year);
}

void array_isprimeandcomposite()
{
	int size1,size2,element,flag,i;

	printf ("Enter the size of array 1  : ");
	scanf ("%d",&size1);
	printf ("\nEnter the size of array 2  : ");
	scanf ("%d",&size2);

	int arr1[size1],arr2[size2];

	printf ("Enter Elements of array 1\n");

	for (element=0;element<size1;element++)
	{
		scanf("%d",&arr1[element]);
	}

	printf ("Enter Elements of array 2\n");

	for (element=0;element<size1;element++)
	{
		scanf("%d",&arr2[element]);

	}

	for (element=0;element<size1;element++)
{
	 flag=1;

	for (i=2;i<=(arr1[element]/2);i++)
	{
		if (arr1[element]%i==0)
		{

		flag=0;
		break;
		}

	}
	if (flag) printf("element %d i.e %d from array 1 is prime number \n",element,arr1[element]);
}

	for (element=0;element<size1;element++)
{
	 flag=1;

	for (i=2;i<=(arr2[element]/2);i++)
	{
		if (arr2[element]%i==0)
		{
			printf("element %d i.e %d from array 2 is a composite number\n",element,arr2[element]);
			flag=0;
		    break;
		}

	}
}
}


void binarytodecimalconversion()
{
	long binarynum,decimal=0;
	int length=0,count,digit;

	printf ("Enter the binary number  :  ");

	scanf("%ld",&binarynum);


	for (count=0;binarynum!=0;count++)
	{
		digit = binarynum%10;
		decimal=decimal+ (digit*pow(2,count));
		binarynum /= 10;
	}

	printf ("\nDecimal NO : %ld",decimal);
}

void decimaltooctalconversion()
{
  long decimal ,quotient;
  int count,octal,digit=0;

  printf("Enter Number  :  ");
  scanf("%ld",&decimal);

  for (count=0;decimal!=0;count++)
  {
     digit = decimal % 8 ;
     decimal= decimal/8 ;
     octal=octal+ (digit*pow(10,count));
  }
  printf("Octal For of Entered Number is : %d",octal);
}
