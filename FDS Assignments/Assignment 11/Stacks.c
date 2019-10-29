#include <stdio.h>
#include <stdlib.h>
#define MAX 30

struct stack
{
    int top;
    int element[MAX];
}stack;

struct stack2
{
    int top;
    char element[MAX];
}stack2;

void push(int );
int pop();
void displayall();
void displayallchar();
void decimaltobinary(int);
void stringreverse(char []);

void main()
{
    stack.top = -1;
    char exit = 'n';
    int choice , term;
    char str[MAX];

        do
     {
            system("cls");

            printf("Enter:\n");
            printf("1.Push element into array\n");
            printf("2.pop element from array\n");
            printf("3. Display all terms in stack \n");
            printf("4. Decimal to binary conversion \n");
            printf("5. String Reverse \n");
            printf("6. EXIT \n");
            printf("Your Choice : ");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1: printf("Enter Term : ");
                             scanf("%d",&term);
                             push(term);
                             break;

                case 2: printf("Top Element : ");
                             pop();
                             break;

                case 3: displayall();
                             break;

                case 4 : printf("Enter Number to convert : ");
                              scanf("%d",&term);
                              decimaltobinary(term);
                              break;

                case 5: printf("Enter The String : ");
                             scanf("%s",str);
                             stringreverse(str);
                             break;

                case 6: exit ='y';
                             break;
            }

            printf("\nClick Enter to continue\n");
            fflush(stdin);
            getchar();

     }while(exit!='y');

}

void push(int term)
{
    if (stack.top == MAX-1)
      {
          printf("Stack Overflow \n");
      }
    else
      {
          stack.top++;
          stack.element[stack.top] = term;
      }
}

int pop()
{
    if (stack.top == -1) printf("Stack Underflow\n");
    else
    {
        printf("%d ",stack.element[stack.top]);
        stack.top--;
    }
}

void displayall()
{
    int i;

    if (stack.top == -1 ) printf("Stack EMPty \n");
    else
    {
        for (i=stack.top ; i > -1 ;i--)
        {
            printf("%d ",stack.element[i]);
        }
    }
}

void displayallchar()
{
    int i;

    if (stack2.top == -1 ) printf("Stack EMPty \n");
    else
    {
        for (i=stack2.top ; i > -1 ;i--)
        {
            printf("%c",stack2.element[i]);
        }
    }
}

void decimaltobinary(int num)
{
    int x;
    stack.top = -1 ;

    while (num!=0)
    {
        x = num%2;
        num = num/2;
        push(x);
    }

    printf("Binary Equivalent : ");
    //displayall();
    //for (x=stack.top ; x > -1 ; x--) printf("%d ",stack.element[x]);

    while (stack.top > -1)
    {
       // printf("%d ",pop());
       pop();
    }
}

void stringreverse(char str[])
{
    int i;

    stack2.top= -1;

    for ( i=0 ; str[i]!='\0' ; i++)
    {
        stack2.top++;
        stack2.element[stack2.top] = str[i];
    }

    printf("Reversed String is : ");
    displayallchar();
}
