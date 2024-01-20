#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char infix[MAX];
char postfix[MAX];
char stack[MAX];
int top = -1;

int precidence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
        break;

    case '*':
    case '/':

        return 2;
        break;

    case '+':
    case '-':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(char temp)
{
    top = top + 1;
    stack[top] = temp;
}
char pop()
{
    if (isEmpty())
    {
        printf("Enpty Stack:");
    }
    char temp = stack[top];
    top = top - 1;
    return temp;
}
void inTopost()
{
    char symmol, next;
    int i, j = 0;

    for (i = 0; i < strlen(infix); i++)
    {
        symmol = infix[i];
        switch (symmol)
        {
        case '(':
            push(symmol);
            break;

        case ')':
            while ((next = pop()) != '(')
                postfix[j++] = next;
            break;

        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
            while (!isEmpty && precidence(stack[top]) >= precidence(symmol))
            {
                postfix[j++] = pop();
            }
            push(symmol);
            break;
        default:
            postfix[j++] = symmol;
            break;
        }
    }
    while (!isEmpty())
    {
        /* code */
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

void print()
{
    int i = 0;
    while (postfix[i])
    {
        printf("%c", postfix[i++]);
    }
    printf("\n");
}

int main()
{

    printf("Enter The infix expression:");
    scanf("%[^\n]", &infix);

    inTopost();
    print();
}