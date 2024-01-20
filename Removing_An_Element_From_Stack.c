#include<stdio.h>
#include<stdlib.h>
int stack_arr[6]={0,1,2,3,4,5};
int top=5;

int pop()
{

    int temp;
            if(top==-1)
            {
                printf("Stack Underflow\n");
                exit(1);
            }
            temp=stack_arr[top];
            top=top-1;
            return temp;
}

int main()
{
    int x;
    x=pop();
    printf("The removed Element is:%d",x);
}