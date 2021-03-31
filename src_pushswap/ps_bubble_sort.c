#include "push_swap.h"

/*
** "Are elements side by side?"
** If index1 is on top of index2 - Return 1
** If index2 is on top of index1 - Return 2
** Return 0 otherwise
*/
int
    ps_are_elem_sbs(t_stack *stack, int index1, int index2)
{
    if (((index1 - index2) == -1) || 
    (index1 == stack->bottom - 1 && index2 == stack->top))
        return (1);
    if (((index1 - index2) == 1 )|| 
    (index1 == stack->top && index2 == stack->bottom - 1))
        return (2);
    return (0);
}

void
    ps_rotate_up(t_stack *stack, t_dyn_iarr *instruct)
{
    if (stack->ref == STACK_A)
        dyn_iarray_add(instruct, RU_A);
    else if (stack->ref == SATCK_B)
        dyn_iarray_add(instruct, RU_B);
}

void
    ps_rotate_down(t_stack *stack, t_dyn_iarr *instruct)
{
    if (stack->ref == STACK_A)
        dyn_iarray_add(instruct, RD_A);
    else if (stack->ref == SATCK_B)
        dyn_iarray_add(instruct, RD_B);
}

void
    ps_swap_top(t_stack *stack, t_dyn_iarr *instruct)
{
    if (stack->ref == STACK_A)
        dyn_iarray_add(instruct, SWAP_A);
    else if (stack->ref == SATCK_B)
        dyn_iarray_add(instruct, SWAP_B);
}

void
    ps_rotate_top(t_stack *stack, t_dyn_iarr *instruct, int index)
{
    int mid;
    int len;

    len = stack->bottom - stack->top;
    mid = (len / 2) + (len % 2);
    if (index <  mid)
    {
        while (index-- > 0)
            ps_rotate_up(stack, instruct);
    }
    else if (index >= mid)
    {
        while (--index)
            ps_rotate_down(stack, instruct);
    }
}

/*
** Swap val1 and val2 in stack->stack, adds push_swap instructions
** return 0 on error, 1 otherwiss
*/

void
    ps_push_a(t_dyn_iarr *instruct)
{
        dyn_iarray_add(instruct, PUSH_B);
}

void
    ps_push_b(t_dyn_iarr *instruct)
{
        dyn_iarray_add(instruct, PUSH_B);
}

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

int
    ps_swap(t_stack *stack, t_dyn_iarr *instruct, int index1, int index2)
{
    int size;
    int ret;

    if ((size = (stack->bottom - stack->top)) < 2)
        printf("Less than 2 elements in stack, nothing to swap\n"); //DEBUG
    if ((ret = ps_are_elem_sbs(stack, index1, index2)) > 0) 
    {
        printf("SBS ret: %d\n", ret);
        if (ret == 1)
            ps_rotate_top(stack, instruct, index1);
        if (ret == 2)
            ps_rotate_top(stack, instruct, index2);
        ps_swap_top(stack, instruct);
    }
    else
    {
        printf("Elements not side by side\n");
    }
    return (0);
    // else
    // {
    //     swap_dist_elem(stack, instruct, index1, index2);        
    // }
    
}

int
    stack_get_index(t_stack *stack, int val)
{
    int i;

    i = stack->top;
    while (i < stack->bottom)
    {
        if (stack->stack[i] == val)
            return (i);
        i++;
    }
    printf("Value not found\n");
    return (0);
}

void
    swap_two(int *arr, int i1, int i2)
{
    int store;

    store = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = store;
}

int
    ps_bubble_sort(t_param *param)
{
    int i;
    int j;
    int len;
    int *arr;
    
    ft_putintarr(param->instruct->arr, param->instruct->max_i + 1);
    
    len = param->stack_a->bottom - param->stack_a->top;
    if (!(arr = ft_intarr_cpy(param->stack_a->stack, param->stack_a->bottom - param->stack_a->bottom)))
        ps_fatal(param, "Malloc");
    i = 0;
    while (i < len)
    {
        j = 0;
        while (j < len - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                swap_two(arr, j, j + 1);
                ps_swap(param->stack_a, param->instruct, stack_get_index(param->stack_a, arr[j]), stack_get_index(param->stack_a, arr[j + 1]));
            }
            j++;
        }
        ft_putintarr(arr, len);
        i++;
    }
    free(arr);
    // ps_swap(param->stack_a, param->instruct, 0, 1);
    // ps_swap(param->stack_a, param->instruct, 1, 2);
    // ps_swap(param->stack_a, param->instruct, 2, 3);
    // ps_swap(param->stack_a, param->instruct, 3, 4);
    // ps_swap(param->stack_a, param->instruct, 0, 1);
    // ps_swap(param->stack_a, param->instruct, 1, 0);
    return (0);
}