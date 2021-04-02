#include "push_swap.h"

void
    ps_bubble_sort(t_param *param)
{
    int i;
    int j;
    int len;
    int *arr;

    len = param->stack_a->bottom - param->stack_a->top;
    if (!(arr = ft_intarr_dup(param->stack_a->stack, len)))
        ps_fatal(param, "Malloc");
    i = 0;
    while (i < len)
    {
        j = 0;
        while (j < len - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                ps_swap(param->stack_a, param->instruct, stack_get_index(param->stack_a, arr[j]), stack_get_index(param->stack_a, arr[j + 1]));
                ft_swap_int(arr, j, j + 1);
            }
            j++;
        }
        i++;
    }
    ps_rotate_top(param->stack_a, param->instruct, ft_intarr_min(param->stack_a->stack, len));
    free(arr);
}

void
    ps_bubble_sort_v2(t_param *param)
{
    int i;
    int j;
    int len;
    int *arr;

    len = param->stack_a->bottom - param->stack_a->top;
    ps_rotate_top(param->stack_a, param->instruct, ft_intarr_min(param->stack_a->stack, len));
    if (!(arr = ft_intarr_dup(param->stack_a->stack, len)))
        ps_fatal(param, "Malloc");
    i = 0;
    while (i < len)
    {
        j = 0;
        while (j < len - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                ps_swap(param->stack_a, param->instruct, stack_get_index(param->stack_a, arr[j]), stack_get_index(param->stack_a, arr[j + 1]));
                ft_swap_int(arr, j, j + 1);
            }
            j++;
        }
        i++;
    }
    ps_rotate_top(param->stack_a, param->instruct, ft_intarr_min(param->stack_a->stack, len));
    free(arr);
}