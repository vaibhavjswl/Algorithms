#include<stdio.h>
#include<stdlib.h>
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
char displaytop();



void main()
{
    stack.top = -1;
    char exit = 'n';
    int choice ;
    char postfix[MAX];
    int t1 , t2 ;
    int result,i;


      printf("Enter Postfix expression : ");
      scanf("%s",postfix);

      while (postfix[i]!='\0')
      {
          while(isdigit(postfix[i]) !=0)
          {
              push(postfix[i]);
              i++;
          }

          if (postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='/' || postfix[i]=='*')
          {
              t1 = pop() - '0';
              t2 = pop() - '0';

              if (postfix[i]=='+') result = t1+t2;
              else if (postfix[i]=='-') result = t1-t2;
              else if (postfix[i]=='/') result = t1/t2;
              else if (postfix[i]=='*') result = t1*t2;
              push(result);
              i++;
          }
      }

      result = pop() - 48;
      printf("Result is %d",result);

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




