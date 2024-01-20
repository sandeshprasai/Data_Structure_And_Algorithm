#include <stdio.h>
#include <stdlib.h>
#define MAX 100;
int front = -1, rear = -1;
int queue_arr[5];

int isFull()
{
    if (rear == 4)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if (rear == -1 || front==rear)
    return 1;
    else
    return 0;
}
int enqueue(int data)
{

    if (isFull())
    {
        printf("Queue is Full:\n");
        exit(0);
    }

    rear++;
    queue_arr[rear] = data;
}

int dequeue()
{

    if(isEmpty())
    {
        printf("\n\Empty Queue:");
        return;
    }

        front++;
        return queue_arr[front];

}

void print()
{
    for (int i = 0; i <= rear; i++)
    {
        printf(" %d ", queue_arr[i]);
    }
}

int main()
{
    int x;
    printf("Entering the element to insert into queue:\n");
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    print();
    x=dequeue();
    printf("\n Dequeed Elemrnt is %d", x);
    x=dequeue();
    printf("\n Dequeed Elemrnt is %d", x);
    x=dequeue();
    printf("\n Dequeed Elemrnt is %d", x);
    x=dequeue();
    printf("\n Dequeed Elemrnt is %d", x);
    x=dequeue();
    printf("\n Dequeed Elemrnt is %d", x);
    x=dequeue();
    printf("\n Dequeed Elemrnt is %d", x);
}