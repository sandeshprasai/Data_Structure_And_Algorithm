#include <stdio.h>
#include <stdlib.h>
void display();
void create(int);
void insert_At_pos(int);
struct node
{
    int data;
    struct node *pointer;
};

struct node *head = NULL;

int main()
{
    int pos;
    create(10);
    create(20);
    create(40);
    create(50);
    create(60);
    create(70);

    printf("\n Enter the position to insert data:");
    scanf("%d", &pos);

    insert_At_pos(pos);
    display();
    free(head);
}

void create(int temp_data)
{

    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        if (head == NULL)
        {
            printf("\nInsufficient Memmoey");
            exit(0);
        }
        head->data = temp_data;
        head->pointer = NULL;
    }

    else if (head->pointer == NULL)
    {
        struct node *temp_head = NULL;
        temp_head = (struct node *)malloc(sizeof(struct node));
        if (temp_head == NULL)
        {
            printf("\nInsufficient Memmoey");
            exit(0);
        }
        temp_head->data = temp_data;
        temp_head->pointer = NULL;
        head->pointer = temp_head;
    }

    else
    {
        struct node *temp_head = NULL;
        struct node *temp = head;
        temp_head = (struct node *)malloc(sizeof(struct node));
        if (temp_head == NULL)
        {
            printf("\nInsufficient Memmoey");
            exit(0);
        }
        temp_head->data = temp_data;
        temp_head->pointer = NULL;
        while (temp->pointer != NULL)
        {
            temp = temp->pointer;
        }
        temp->pointer = temp_head;
    }
}

void display()
{
    struct node *disp = head;
    while (disp != NULL)
    {
        printf(" %d ", disp->data);
        disp = disp->pointer;
    }
}
void insert_At_pos(int pos)
{
    struct node *temp_head = NULL;
    temp_head = (struct node *)malloc(sizeof(struct node));
    if (temp_head == NULL)
    {
        printf("\nInsufficient Memmoey");
        exit(0);
    }
    temp_head->data = 30;
    temp_head->pointer = NULL;
    if (pos == 1)
    {
        temp_head->pointer = head;
        head = temp_head;
    }
    else
    {
        struct node *ptr = head;
        for (int i = 1; i <= pos - 1; i++)
        {
            ptr = ptr->pointer;
            if (ptr == NULL)
            {
                printf("\nInvalid Address");
                free(temp_head);
            }
        }

        temp_head->pointer = ptr->pointer;
        ptr->pointer = temp_head;
    }
}