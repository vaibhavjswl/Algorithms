#include <ctype.h>
#include <stdio.h>
//#include <stdlib.h>
//#include<string.h>
#define MAX 30



struct stack
{
    int top;
    int element[MAX];
}stack;

void push(int );
int operation(char, int , int);
char pop();
char postfix[MAX];



void main()
{
    stack.top = -1;
    int t1 , t2 , result;
    int i = 0;


    printf("Enter Postfix Expression to be evaluated : ");
    scanf("%s",postfix);

    while(postfix[i]!='\0')
    {

        if (isdigit(postfix[i]))
        {
            push((postfix[i] - 48));
            i++;
        }

        else
        {
            t2 = pop();
            t1 = pop();

            result = operation(postfix[i] , t2 , t1);

            push(result);
            i++;
        }

    }
    printf("Result of Evaluation is : %d" , pop());
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

char pop()
{
    if (stack.top == -1) printf("Stack Underflow\n");
    else
    {
        stack.top--;
        return stack.element[stack.top+1];
    }
}

int operation(char op , int t2 , int t1)
{
    switch (op)
    {
        case '+' : return t1 + t2;
                       break;
        case '-' : return t1 - t2;
                       break;
        case '*' : return t1 * t2;
                       break;
        case '/' : return t1 / t2;
                       break;
    }
}
