#include "libft.h"

int
    *ft_intarr_dup(int *arr, int len)
{
    int *arr_cpy;
    int i;

    if (!(arr_cpy = (int *)malloc(sizeof(int) * len)))
        return (NULL);
    i = 0;
    while (i < len)
    {
        arr_cpy[i] = arr[i];
        i++;
    }
    return (arr_cpy);
}