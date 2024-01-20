#include<stdio.h>
#define MAX 5
int stack_arr[MAX];
int first=-1;

    void push(int temp)
    {   
       stack_arr[first+1]=stack_arr[0];     
        stack_arr[0]=temp;
        first+=1;            


    }


void display()
{
        for (int i = 0; i < MAX; i++)
        {
            /* code */
            printf(" %d ",stack_arr[i]);
        }
        
}
int main()
{


    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();
}