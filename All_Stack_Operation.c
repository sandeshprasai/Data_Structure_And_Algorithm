#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int stack_arr[MAX];
int top = -1;

int isFull()
{
    if (top == (MAX - 1))
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

void push(int temp)
{
    if (isFull())
    {
        printf("Stack Overflow:\n");
        return;
    }
    top += 1;
    stack_arr[top] = temp;
}

int pop()
{

    if (isEmpty())
    {
        printf("Stack is Empty:\n");
        return -1;
    }

    return stack_arr[top];
}

void print_top()
{
    printf("The top Element of array is:%d\n", stack_arr[top]);
}

void display()
{
    for (int i = 0; i < MAX; i++)
    {
        printf(" %d ", stack_arr[i]);
    }
    printf("\n");
}

int main()
{
    int choice, data;
    while (1)
    {
        printf("1. Push Element:\n");
        printf("2. Pop Element\n");
        printf("3. Print top element\n");
        printf("4. Print All element:\n");
        printf("5. Exit \n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the Element to push:\n");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            data = pop();
            printf("The removed Element is:%d\n", data);
            top -= 1;
            break;
        case 3:
            print_top();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Wrong Choice:\n");
            break;
        }
    }
}
