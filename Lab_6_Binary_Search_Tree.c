#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create();
void Inorder(struct node *);

void main()
{
    struct node *root = NULL;
    int choice;
    printf("\n Enter 1 To create a tree:");
    printf("\n Enter 2 To perform Inorder traversal:");
    printf("\n Enter 3 To perform preorder traversal:");
    printf("\n Enter 4 To perform postorder traversal:");
    printf("\n Enter Your Choice");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        root = create();
        break;
    case 2:
        Inorder(root);
        break;
    default:
        break;
    }
}

struct node *create()

{
    int data;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter -1 for no data or \n Enter your data:");
    scanf("%d", &data);
    if (data == -1)
    {
        return NULL;
    }
    new_node->data = data;
    printf("\n Enter Your left child");
    scanf("%d", &data);
    new_node->left = create();
    printf("\n Enter right Child:");
    scanf("%d", &data);
    new_node->right = create();

    return new_node;
}
void Inorder(struct node *temp_root)
{
     if (temp_root != NULL)
    {
        Inorder(temp_root->left);
        printf("%d ", temp_root->data);
        Inorder(temp_root->right);
    }
}