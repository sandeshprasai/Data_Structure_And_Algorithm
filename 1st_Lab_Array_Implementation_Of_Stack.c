#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int stack_arr[SIZE];
int top = -1;

void push();
int pop();
void peek();
int isFULL();
int isEmpty();
void Display();
int main()
{
    int choice, data;
    while (1)
    {
        printf("\n Presss 1 For Push:");
        printf("\n Presss 2 For Pop:");
        printf("\n Presss 3 For Peek:");
        printf("\n Presss 4 For Display:");
        printf("\n Presss 5 For Exit:");
        printf("\n Enter Your Choice:");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n Enter a value to push:");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            data = pop();
            printf("\n%d Value is removed", data);
            break;
        case 3:
            peek();
            break;
        case 4:
            if (isEmpty())
            {
                printf("\nEmpty Stack");
            }
            printf("\nThe Element on the array are as follow:");
            Display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nInvalid Choice");
            break;
        }
    }

    return 0;
}

int isFUll()
{
    if (top == SIZE - 1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(int data)
{
    if (isFUll())
    {
        printf("\n Stack Overflow:");
        return;
    }
    top += 1;
    stack_arr[top] = data;
    printf("\n %d is Pushed into the stack SucessFully.....", data);
}

int pop()
{
    if (isEmpty())
    {
        printf("\nStack Underflow");
        return;
    }
    return stack_arr[top--];
}

void peek()
{
    if (isEmpty())
    {
        printf("\nEmpty Stack");
        return;
    }
    printf("\n Topmost Element of stack is %d", stack_arr[top]);
}

void Display()
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("\nStack_arr[%d]= %d", i, stack_arr[i]);
    }
}