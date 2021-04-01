#include "push_swap.h"

int
    dyn_iarray_add(t_dyn_iarr *dyn_arr, int val)
{
    int *arr_cpy;
    int i;

    if (dyn_arr->max_i == dyn_arr->size - 1)
    {
        if (dyn_arr->size == INT_MAX)
            return (-1);
        else if (dyn_arr->size * 2 > INT_MAX)
            dyn_arr->size = INT_MAX;
        else
            dyn_arr->size = dyn_arr->size * 2;
        if (!(arr_cpy = (int *)malloc(sizeof(int) * dyn_arr->size)))
            return (0);
        i = 0;
        while (i <= dyn_arr->max_i)
        {
            arr_cpy[i] = dyn_arr->arr[i];
            i++;
        }
        free(dyn_arr->arr);
        dyn_arr->arr = arr_cpy;
    }
    dyn_arr->max_i++;
    dyn_arr->arr[dyn_arr->max_i] = val;
    return (1);
}