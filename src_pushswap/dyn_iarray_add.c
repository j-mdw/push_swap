#include "push_swap.h"

static int
    dyn_iarr_grow(t_dyn_iarr *dyn_arr)
{
    int *arr_cpy;
    int i;

    if (dyn_arr->size == INT_MAX)
        return (0);
    else if (dyn_arr->size * 2 > INT_MAX)
        dyn_arr->size = INT_MAX;
    else
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
    return (1);
}

int
    dyn_iarray_add(t_dyn_iarr *dyn_arr, int val)
{
    int *arr_cpy;
    int i;

    if (dyn_arr->max_i == dyn_arr->size - 1)
    {
        if (!dyn_iarr_grow(dyn_arr) )
            return (0);
    }
    dyn_arr->max_i++;
    dyn_arr->arr[dyn_arr->max_i] = val;
    return (1);
}