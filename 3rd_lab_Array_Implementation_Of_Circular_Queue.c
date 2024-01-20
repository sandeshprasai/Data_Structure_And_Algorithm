#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue_arr[MAX];
int front = -1, rear = -1;

int isFull();
int isEmpty();
void enqueue(int data);
int dequeue();
void print();

int main()
{
    int choice, data;
    while (1)
    {
        printf("\n Press 1 For Enqueue:");
        printf("\n Press 2 For Dequeue:");
        printf("\n Press 3 For Display:");
        printf("\n Press 4 For Exit:");
        printf("\n Enter Your Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isFull())
            {
                printf("\n Queue Overflow");
                break;
            }
            printf("\n Enter The data To Enqueue:");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            if (isEmpty())
            {
                printf("\nQueue Underflow:");
                break;
            }
            data = dequeue();
            printf("\nThe %d element is dequeued:", data);
            break;
        case 3:
            if (isEmpty())
            {
                printf("Queue is Empty:");
                break;
                
            }
            print();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\n Invalid Choice:");
            break;
        }
    }
}
int isEmpty()
{
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if (front == ((rear + 1) % MAX))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int data)
{
    if (isEmpty())
    {
        front += 1;
    }
    rear = (rear + 1) % MAX;
    queue_arr[rear] = data;
}

int dequeue()
{

    int data;

    if (front == rear)
    {
        data = queue_arr[front];
        front = -1;
        rear = -1;
        return data;
    }
    data = queue_arr[front];
    front = (front + 1) % MAX;
    return data;
}
void print()
{

    int i;
    for (i = front; i != rear; i = (i + 1) % MAX)
    {
        printf(" %d ", queue_arr[i]);
    }
    printf(" %d ", queue_arr[rear]);
}
