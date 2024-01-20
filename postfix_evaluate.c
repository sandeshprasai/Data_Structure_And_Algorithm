#include <stdio.h>
#include<stdlib.h>
#include <string.h>
char postfix[20];
char stack[20];
int top=-1;
int result=0;
int isoperator(char x)
{
      if(x=='^'||x=='*'||x=='/'||x=='+'||x=='-')
      {
        return 1;
      }
  else
      {
        return 0;
      }
}
int pop()
{
    if(top==-1)
    {
      printf("Stack Underflow:");
      exit(0);
    }
  return stack[top--];
}
void push(char x)
{
    if(top==19)
    {
        printf("Stack Overflow");
      exit(0);
    }
  top+=1;
  stack[top]=x;
}

int evaluate()
{
int i;
  int a,b;
  char symbol;
  for(i=0;i<strlen(postfix);i++)
    {
      symbol=postfix[i];
        if(isoperator( symbol))
      {
        b=pop();
        a=pop();
        switch(symbol)
          {
            case '^':
            result=a^b;
            break;

            case '/':  
            result=a/b;
            break;

            case '*':
            result=a*b;
            break;

            case '+':
            result=a+b;
            break;

            case '-':
            result=a-b;
            break;
          }
           push(result);
      }
      else
      {
          push(symbol);  
      }
    }
    return pop();
}
int main()
{
  int r;
  printf("Enter an postfix epression:\n");
  scanf("%s",postfix);
  r=evaluate();
  printf("The result is %d:",r);
}