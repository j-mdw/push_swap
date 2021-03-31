#include "push_swap.h"

int
    dyn_iarray_init(t_dyn_iarr *dyn_arr, int size)
{
    dyn_arr->max_i = -1;
    dyn_arr->size = size;
    if (!(dyn_arr->arr = (int *)malloc(sizeof(int) * size)))
        return (0);
    return (1);
}