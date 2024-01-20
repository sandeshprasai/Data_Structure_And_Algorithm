#include<stdio.h>
#define max 4
int stack_arr[max];
int top=-1;

void display()
{
    for(int i=0;i<max;i++)
    {
        printf(" %d ",stack_arr[i]);
    }
}

void push( int temp)
{
        if(top==max-1)
        {
            printf("Stack Overflow:\n");
                display();
            return;
        }
        top=top+1;
        stack_arr[top]=temp;
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

}