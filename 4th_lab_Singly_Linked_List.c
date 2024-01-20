#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void insert_at_begin(int);
void insert_at_end(int);
void display();
void deletion_at_begin();
void free_memory();
int main()
{
    while (1)
    {
        int choice, data;
        printf("\n Press 1 For insertion in the beginning:");
        printf("\n Press 2 For insertion in the End:");
        printf("\n Press 3 For Deletion in the beginning:");
        printf("\n Press 4 For Display :");
        printf("\n Press 5 For Exit");
        printf("\nEnter Your Choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Data to insert in the begining:");
            scanf("%d", &data);
            insert_at_begin(data);
            break;
        case 2:
            printf("\nEnter Data to insert in the end:");
            scanf("%d", &data);
            insert_at_end(data);
            break;
        case 3:
            deletion_at_begin();
            break;
        case 4:
            display();
            break;
        case 5:
            free_memory();
            exit(0);
            break;
        default:
            printf("\n Invalid Choice:");
        }
    }
}
void insert_at_begin(int data)
{
    struct node *new_node = NULL;
    new_node = (struct node *)malloc((sizeof(struct node)));
    if (new_node == NULL)
    {
        printf("\n Node creation Unsucessfull");
        return;
    }
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}
void insert_at_end(int data)
{
    struct node *new_node = NULL;
    new_node = (struct node *)malloc((sizeof(struct node)));
    if (new_node == NULL)
    {
        printf("\n Node creation Uncessfull");
        return;
    }
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
    }

    else
    {
        struct node *i = head;
        while (i->next != NULL)
        {
            i = i->next;
        }

        i->next = new_node;
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\nNo node found");
        return;
    }
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
}
void deletion_at_begin()
{
    if (head == NULL)
    {
        printf("\nNo node found");
        return;
    }

    struct node *ptr = head;
    head = head->next;
    printf("\n%d is removed", ptr->data);
    free(ptr);
}
void free_memory()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        struct node *temp = ptr;

        ptr = ptr->next;
        free(temp);
    }
}