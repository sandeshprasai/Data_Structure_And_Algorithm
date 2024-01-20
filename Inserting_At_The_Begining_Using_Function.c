#include <stdio.h>
#include <stdlib.h>
void insert_in_Begin(int);
void display();
struct node
{
    int data;
    struct node *pointer;
};
struct node *head = NULL;
int main()
{

    int data1;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("Memory allocation Unsucessfull\n");
        exit(0);
    }
    head->data = 10;
    head->pointer = NULL;

    printf("Enter data to insert in the begining of an list \n");
    scanf("%d", &data1);
    insert_in_Begin(data1);
    insert_in_Begin(30);
    insert_in_Begin(40);
    insert_in_Begin(50);

    display();
}

void insert_in_Begin(int data1)
{

    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation Unsucessfull\n");
        exit(0);
    }
    temp->pointer = NULL;
    temp->data = data1;
    temp->pointer = head;
    head = temp;
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->pointer;
    }
}