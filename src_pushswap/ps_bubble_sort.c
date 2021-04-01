#include "push_swap.h"

// void
//     swap_dist_elem(t_stack *stack, t_dyn_iarr *instruct, int index1, int index2)
// {
//     int mid;

//     mid = stack->bottom - stack->top;
//     if ((index1 - mid) < (index2 - mid))
//     {
//         ps_rotate_top(stack, instruct, index1);
//         ps_push_b(instruct);
//     }
//     else
//         ps_rotate_top(stack, instruct, index2);
    
// }
void
    ps_bubble_sort(t_param *param)
{
    int i;
    int j;
    int len;
    int *arr;
    int index1;
    int index2;


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
                index1 = stack_get_index(param->stack_a, arr[j]);
                index2 = stack_get_index(param->stack_a, arr[j + 1]);
                ps_swap(param->stack_a, param->instruct, index1, index2);
                ft_swap_int(arr, j, j + 1);
                // printf("Stack:\n");
                // ft_putintarr(param->stack_a->stack, len);
                // printf("Arr:\n");
                // ft_putintarr(arr, len);
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
    int index1;
    int index2;

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
                index1 = stack_get_index(param->stack_a, arr[j]);
                index2 = stack_get_index(param->stack_a, arr[j + 1]);
                ps_swap(param->stack_a, param->instruct, index1, index2);
                ft_swap_int(arr, j, j + 1);
                // printf("Stack:\n");
                // ft_putintarr(param->stack_a->stack, len);
                // printf("Arr:\n");
                // ft_putintarr(arr, len);
            }
            j++;
        }
        i++;
    }
    ps_rotate_top(param->stack_a, param->instruct, ft_intarr_min(param->stack_a->stack, len));
    free(arr);
}