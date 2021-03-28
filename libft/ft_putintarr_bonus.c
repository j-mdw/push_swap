#include "libft.h"

void
    ft_putintarr(int *arr, int len)
{
    int i;

    i = 0;
    while (i < len)
        printf("|%d", arr[i++]);
    printf("|\n");
}