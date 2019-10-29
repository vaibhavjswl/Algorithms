
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 30



struct stack
{
    int top;
    char element[MAX];
}stack;

void push(char );
char pop();
void displayall();
void infixtoPostfix();
void get_priority(char);
int Operatorcheck(char);
char displaytop();
char infix[MAX];
char postfix[MAX];

void main()
{
    stack.top = -1;
    char exit = 'n';
    int choice ;

        do
     {
            system("cls");

            printf("Enter:\n");
            printf("1.Infix to Prefix\n");

            printf("2. EXIT \n");
            printf("Your Choice : ");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1: printf("Enter Expression : ");
                             scanf("%s",infix);
                             infixtoPostfix(infix);
                             break;

                case 2: exit ='y';
                             break;
            }

            printf("\nClick Enter to continue\n");
            fflush(stdin);
            getchar();

     }while(exit!='y');

}

void push(char term)
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

char pop()
{
    if (stack.top == -1) printf("Stack Underflow\n");
    else
    {
        stack.top--;
        return stack.element[stack.top+1];
    }
}

char displaytop()
{
    if (stack.top != -1)
    {
        return stack.element[stack.top];
    }
}


int getPriority(char term)
{
	if(term=='-'||term=='+')
        return 1;
	else if(term=='*'||term=='/')
        return 2;
	else if (term=='^')
        return 3;
	else
        return 0;
}

int Operatorcheck(char term)
{
    if (term=='+' || term=='*' || term=='-' || term=='/' || term=='^') return 1;
    else if (term==')') return 2;
    else if (term=='(') return 3;
    else return 0;
}

void infixtoPostfix(char str[])
{
    int current_toppriority, current_top, i=0 ,j=0;
    int term;

    strrev(infix);

    while (infix[i]!='\0')
    {
         if (Operatorcheck(infix[i])==0)
         {
             postfix[j] = infix[i] ;
             i++ ; j++;
             }

         else
         {
             if (Operatorcheck(infix[i])==2) push(infix[i]);
             else if (Operatorcheck(infix[i])==3)
             {
                 while (Operatorcheck(term = pop())!=2)
                 {
                     if (term!=')') postfix[j++] = term;
                 }
             }

             else if(Operatorcheck(infix[i])==1)
             {
                 if (stack.top==-1) push(infix[i]);
                 else
                 {
                     if (getPriority(infix[i])>getPriority(displaytop())) push(infix[i]);

                     else if (getPriority(infix[i])<=getPriority(displaytop()))
                     {

                         while ((getPriority(displaytop())>getPriority(infix[i])) && stack.top!=-1)
                         {
                            postfix[j++] = pop();
                         }

                         push(infix[i]);


                     }
                }
             }
             i++;
         }
    }

    while (stack.top!=-1)
    {
        postfix[j++] = stack.element[stack.top];
        stack.top--;
    }

    strrev(postfix);
    printf("Expression : ");
    for (i = 0 ; i<strlen(postfix) ; i++)
        printf("%c",postfix[i]);
}
