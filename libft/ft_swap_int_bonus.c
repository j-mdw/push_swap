#include "libft.h"

void
    ft_swap_int(int *arr, int i1, int i2)
{
    int store;

    if (arr)
    {
        store = arr[i1];
        arr[i1] = arr[i2];
        arr[i2] = store;
    }
}