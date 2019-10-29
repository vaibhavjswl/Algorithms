#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void fibonacciseries();
void factorial();
int factorialusingrecursion(int );
int fibonacciusingrecursion(int );
void swap_using_callbyvalue();
void swap_using_callbyreference(int * , int *);

main ()
{
	int choice,factr,num,fib,count,num1,num2;
	menu:
	printf("Enter 1.To Print Fibonacci Series\n");
	printf("Enter 2.To Print Fibonacci Series using recursion\n");
	printf("Enter 3.To Calculate and Print Factorial of a number\n");
	printf("Enter 4.To Print Factorial of a number using Recursion Method\n");
	printf("Enter 5. Swap two numbers using Call by value method \n");
	printf("Enter 6. Swap two numbers using Call by reference method \n");
	printf("\nChoice : ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1 :  fibonacciseries();
		          break;

        case 2:   printf ("Enter a number of terms to find : ");
	              scanf  ("%d",&num);

                  for (count=0;count<=num;count++)
                  {
                    fib = fibonacciusingrecursion(count);
                    printf("%d \n",fib);
                  }
                  break;

		case 3 :  factorial();
	              break;
	    case 4 :  printf ("Enter a number : ");
	              scanf  ("%d",&num);

		          factr=factorialusingrecursion(num);
	              printf ("Factorial of number is %d",factr);
	              break;

        case 5 : swap_using_callbyvalue();
                 break;

        case 6 :
                  printf("Enter the First Number :  ");
                  scanf("%d",&num1);

                  printf("Enter the Second Number :  ");
                  scanf("%d",&num2);

                  swap_using_callbyreference(&num1,&num2);
                  printf("After Swapping Numbers are  : \nA : %d\nB: %d ",num1,num2);
                  break;

		default: printf("Invalid Input Please try again");
		         goto menu;
	}
}



void fibonacciseries()
{
	int fib[100],element;

	fib[0]=0;
	fib[1]=1;

	for (element=2;element<15;element++)
	{
		fib[element]=fib[element-1]+fib[element-2];
	}
	printf ("Fibonacci series is \n");

	for (element=0;element<15;element++)
	{
		printf ("%d \n",fib[element]);
	}
}

void factorial()
{
	int num,fact=1,count;

	printf ("Enter a number : ");
	scanf  ("%d",&num);

	for (count=1;count<=num;count++)
	{
		fact=fact*count;
	}
	printf ("Factorial of number is : %d",fact);
}

int factorialusingrecursion(int num)
{
	if (num==1) return 1;
	else return (num*factorialusingrecursion(num-1));
}

int fibonacciusingrecursion(int num)
{
   if (num==0) return 0;
   else if (num==1) return 1;
   else return (fibonacciusingrecursion(num-1)+fibonacciusingrecursion(num-2));
}
void swap_using_callbyvalue()
{
  int num1,num2,temp;

  printf("Enter the First Number :  ");
  scanf("%d",&num1);

  printf("Enter the Second Number :  ");
  scanf("%d",&num2);

  printf("Entered Numbers are : \nA : %d\nB: %d \n",num1,num2);
  temp=num1;
  num1=num2;
  num2=temp;
  printf("After Swapping Numbers are  : \nA : %d\nB: %d ",num1,num2);
}

void swap_using_callbyreference(int *num1,int *num2)
{
    int temp;
    printf("Entered Numbers are : \nA : %d\nB: %d \n",*num1,*num2);
    temp=*num1;
    *num1=*num2;
    *num2=temp;
}
