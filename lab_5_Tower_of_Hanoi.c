#include <stdio.h>
void TOH(int, char, char, char);
int main()
{
    int n;
    printf("\n Enter No of Discs:");
    scanf("%d", &n);
    TOH(n, 'O', 'D', 'I');
    return (0);
}

void TOH(int n, char A, char B, char C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        printf("\n Move disc no %d from %c to %c", n, A, B);
        TOH(n - 1, C, B, A);
    }
} 