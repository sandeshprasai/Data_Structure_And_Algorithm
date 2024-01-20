#include <stdio.h>
#include <stdlib.h>
void create();
void display();

struct node
{
    int data;
    struct node *pointer;
};
struct node *head = NULL;

int main()
{

    create(10);
    create(20);
    create(30);
    create(40);
    create(50);
    create(60);
    display();
}

void create(int temp_data)
{
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = temp_data;
        head->pointer = NULL;
    }

    else if (head->pointer == NULL)
    {
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = temp_data;
        head->pointer = temp;
        temp->pointer = NULL;
    }
    else
    {
        struct node *i = NULL;
        struct node *tp;
        for (i = head; i->pointer != NULL; i = i->pointer)
        {
        }
        tp = (struct node *)malloc(sizeof(struct node));
        if (tp == NULL)
        {
            printf("Memory allocation Unsucessfull\n");
            exit(0);
        }
        tp->data = temp_data;
        tp->pointer = NULL;
        i->pointer = tp;
    }
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