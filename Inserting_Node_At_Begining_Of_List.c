#include <stdio.h>
#include <stdlib.h>

struct node
{  int data;
    struct node *pointer;
};
int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("\nMemory allocation Uncessfull:");
        exit(0);
    }
    head->data = 10;
    head->pointer = NULL;

    struct node *update = NULL;
    update = (struct node *)malloc(sizeof(struct node));
    if (update == NULL)
    {
        printf("\nMemory allocation Uncessfull:");
        exit(0);
    }
    update->data = 20;
    update->pointer = head;
    head = update;
    printf("\n Data inserted in the beginng of  node  %d \n ", head->data);
    printf("\n Data  in the previous   node  %d \n ", head->pointer->data);
}