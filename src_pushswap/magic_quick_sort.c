#include "push_swap.h"

static int
    stack_sub_issort(t_stack *stack, int len)
{
    int i;

    i = stack->top;
    while (i < (stack->top + len - 1))
    {
        if (stack->stack[i] > stack->stack[i + 1])
            return (0);
        i++;
    }
    return (1);
}

static int
    stack_sub_issort_r(t_stack *stack, int len)
{
    int i;

    i = stack->top;
    while (i < (stack->top + len - 1))
    {
        if (stack->stack[i] < stack->stack[i + 1])
            return (0);
        i++;
    }
    return (1);
}

static void
    len_2_routine(t_stack *stack_1, t_stack *stack_2, t_dyn_iarr *instruct)
{
    if (stack_1->ref == STACK_A)
        ps_swap_top(stack_1, instruct);
    else if (stack_1->ref == STACK_B)
    {
        ps_swap_top(stack_1, instruct);
        ps_push_a_n(stack_2, stack_1, instruct, 2);
    }
}
   
static void
    magic_quick_sort_rec(t_stack *stack_1, t_stack *stack_2, int len, t_dyn_iarr *instruct)
{
    int push_count;

    if (stack_1->ref == STACK_A && stack_sub_issort(stack_1, len))
        return ;
    else if (stack_1->ref == STACK_B && stack_sub_issort_r(stack_1, len))
        ps_push_a_n(stack_2, stack_1, instruct, len);
    else if (len == 2)
         len_2_routine(stack_1, stack_2, instruct);
    else
    {
        push_count = magic_partition(stack_1, stack_2, len, instruct);
        if (stack_1->ref == STACK_A)
        {
            magic_quick_sort_rec(stack_1, stack_2, len - push_count, instruct);
            magic_quick_sort_rec(stack_2, stack_1, push_count, instruct);
        }
        else
        {
            magic_quick_sort_rec(stack_2, stack_1, push_count, instruct);
            magic_quick_sort_rec(stack_1, stack_2, len - push_count, instruct);
        }
    }
}

void
    magic_quick_sort(t_param *param)
{
    magic_quick_sort_rec(param->stack_a, param->stack_b,
    param->stack_a->bottom - param->stack_a->top, param->instruct);
} 