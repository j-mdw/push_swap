#include "libft.h"

int
    ft_intarr_min(int *arr, int len)
{
    int i;
    int min;

    min = 0;
    i = 0;
    while (i < len)
    {
        if (arr[i] < arr[min])
            min = i;
        i++;
    }
    return (min);
}