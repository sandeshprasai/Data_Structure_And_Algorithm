    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define MAX 100

    char infix[MAX], postfix[MAX], stack[MAX];
    int top = -1;

    int isEmpty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }

    int isFull()
    {
        if (top == MAX - 1)
            return 1;
        else
            return 0;
    }

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

    void push(char symbol)
    {
        if (isFull())
        {
            printf("Stack Overflow:\n");
            return;
        }

        top += 1;
        stack[top] = symbol;
    }

    int pop()
    {
        char temp;
        if (isEmpty())
        {
            printf("Nothing to pop Empty Stack:");
            return '\0';
        }
        temp = stack[top];
        top -= 1;
        return temp;
    }

    void toPostfix()
    {
        char symbol, next;
        int i, j = 0;
        for (i = 0; i < strlen(infix); i++)
        {
            symbol = infix[i];
            switch (symbol)
            {
            case '(':
                push(symbol);
                break;
            case ')':

                while ((next = pop()) != '(')
                {
                    postfix[j++] = next;
                }

                break;

            case '^':
            case '/':
            case '*':
            case '+':
            case '-':
                while (!isEmpty() && (precidence(stack[top])) >= precidence(symbol))
                {
                    postfix[j++] = pop();
                }
                push(symbol);
                break;

            default:
                postfix[j++] = symbol;
                break;
            }
        }

        while (stack[top]!='\0')
        {
            postfix[j++]=pop();
            
        }
        
    }

    void print()
    {
        for (int i = 0; i < strlen(postfix); i++)
        {
            printf("%c", postfix[i]);
        }
    }

    int main()
    {
        printf("Enter the infix expression:\n");
        scanf("%[^\n]", infix);
        toPostfix();
        print();
        printf("\n");
    }