#include <stdio.h>
#include "Array.h"

void Delete_data(int *a, int position)
{
    int i;
    for (i = position; i < MAXSIZE; i++)
    {
        printf("%d", a[i]);
        if (a[i])
        {
            a[i - 1] = a[i];
        }
        else
        {
            printf("该处没有元素\n");
            break;
        }
    }
    // a[i] = NULL;
}

// void Insert_data(int *a, position, num)
// {
//     int i;
//     for (i = position; i < num; i++)
//     {
//     }
// }