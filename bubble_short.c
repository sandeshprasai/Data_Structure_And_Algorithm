#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int main()
{
    int arr[MAX], temp;

    int i, j;

    printf("Enter 5 Array Elements:");
    for (i = 0; i < MAX; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i <MAX; i++)
    {
        for (j = i+1; j <= i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < MAX; i++)
    {
        printf("%d", arr[i]);
    }
}