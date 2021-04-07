#include "push_swap.h"

static int
    intarr_median(int *arr, int len)
{
    int med;

    quick_sort(arr, len);
    med = arr[len / 2];
    return (med);
}

static int
    get_med(int *med, int *arr, int len)
{
    int *arr_cpy;

    if (!(arr_cpy = ft_intarr_dup(arr, len)))
        return (0);
    *med = intarr_median(arr_cpy, len);
    free(arr_cpy);
    return (1);
}

static int
    sub1(t_stack *stack_1, t_stack *stack_2,
    t_dyn_iarr *instruct, int index)
{
    int mov_count;

    mov_count = 0;
    while (index-- > stack_1->top)
    {
        ps_rotate_up(stack_1, instruct);
        mov_count++;
    }
       
    if (stack_1->ref == STACK_A)
        ps_push_b(stack_1, stack_2, instruct);
    else
        ps_push_a(stack_2, stack_1, instruct);
    return (mov_count);
}

static void
    rot_down_n(t_stack *stack_1, t_dyn_iarr *instruct, int rotcount)
{
    while (rotcount--)
        ps_rotate_down(stack_1, instruct);
}

int
    magic_partition(t_stack *stack_1, t_stack *stack_2, int len,
    t_dyn_iarr *instruct)
{
    int md;
    int i;
    int push_count;
    int rotcount;

    if (!(get_med(&md, &(stack_1->stack[stack_1->top]), len)))
        return (0);
    push_count = 0;
    i = 0;
    rotcount = 0;
    while (i < len)
    {
        if ((stack_1->ref == STACK_A && stack_1->stack[stack_1->top + i] < md)
        || (stack_1->ref == STACK_B && stack_1->stack[stack_1->top + i] >= md))
        {
            len += rotcount;
            rotcount += sub1(stack_1, stack_2, instruct, stack_1->top + i);
            len -= (rotcount + 1);
            i = -1;
            push_count++;
        }
        i++;
    }
    rot_down_n(stack_1, instruct, rotcount);
    return (push_count);
}