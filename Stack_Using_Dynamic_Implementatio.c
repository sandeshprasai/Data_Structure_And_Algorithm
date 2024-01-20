#include <stdio.h>
#include <stdlib.h>
struct stack_lists
{
    int data;
    struct stack_lists *next;
};

struct stack_lists *head = NULL;

void push(int);
void pop();
void peek();
void print();
void free_memory();

int main()
{
    int choice, data;
    while (1)
    {
        printf("\n Press 1 For PUSH operation:");
        printf("\n Press 2 For pop operation:");
        printf("\n Press 3 For peek operation:");
        printf("\n Press 4 For print operation:");
        printf("\n Press 5 For Exit:");
        printf("\n Enter Your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter data to push:");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            print();
            break;
        case 5:
            free_memory();
            exit(0);
            break;
        default:
            printf("\n Invalid Choice");
            break;
        }
    }
}
void push(int data)
{
    struct stack_lists *new_node = (struct stack_lists *)malloc(sizeof(struct stack_lists));
    if (new_node == NULL)
    {
        printf("\nMemory Allocation Unsccessfull");
        return;
    }
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}
void pop()
{
    if (head == NULL)
    {
        printf("\n Empty stack ");
        return;
    }
    struct stack_lists *ptr = head;
    printf("%d data is removed", head->data);
    head = head->next;
    free(ptr);
}
void peek()
{
    printf("\n Topmost element of the stack is %d:", head->data);
}
void print()
{
    if (head == NULL)
    {
        printf("\nEmpty stack");
        return;
    }
    struct stack_lists *ptr = head;
    printf("\n The stack elements are:\n");
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
}

void free_memory()
{
    struct stack_lists *ptr = head;
    while (ptr != NULL)
    {
        struct node *temp = ptr;

        ptr = ptr->next;
        free(temp);
    }
}