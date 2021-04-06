#include "push_swap.h"

int
    intarr_median(int *arr, int len)
{
    int med;

    quick_sort(arr, len);
    med = arr[len / 2];
    return (med);
}

int
    partition(t_stack *stack_1, t_stack *stack_2, int len, t_dyn_iarr *instruct)
{
    int med;
    int *arr_cpy;
    int i;
    int push_count;
    int index;
    int rotcount;

    if (!(arr_cpy = ft_intarr_dup(&(stack_1->stack[stack_1->top]), len)))
        return (0);
    med = intarr_median(arr_cpy, len);
    free(arr_cpy);
    push_count = 0;
    i = 0;
    rotcount = 0;
    while (i < len)
    {
        if (stack_1->ref == STACK_A && stack_1->stack[stack_1->top + i] < med)
        {
		    index = stack_1->top + i;
            while (index-- > stack_1->top)
            {
			    ps_rotate_up(stack_1, instruct);
                len--;
                rotcount++;
            }
            ps_push_b(stack_1, stack_2, instruct);
            push_count++;
            i = -1;
            len--;
        }
        else if (stack_1->ref == STACK_B && stack_1->stack[stack_1->top + i] >= med)
        {
		    index = stack_1->top + i;
            while (index-- > stack_1->top)
            {
			    ps_rotate_up(stack_1, instruct);
                len--;
                rotcount++;
            }
            ps_push_a(stack_2, stack_1, instruct);
            push_count++;
            i = -1;
            len--;
        }
        i++;
    }
    while (rotcount--)
        ps_rotate_down(stack_1, instruct);
    return (push_count);
}

void
	ps_push_a_n(t_stack *stack_a, t_stack *stack_b, t_dyn_iarr *instruct, int n)
{
	int val;
    int i;
    
    i = 0;
    while (i < n)
	{
        dyn_iarray_add(instruct, PUSH_A);
	    val = stack_pop(stack_b);
	    stack_push(stack_a, val);
        i++;
    }
}

int
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

int
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
void
    magic_quick_sort_rec(t_stack *stack_1, t_stack *stack_2, int len, t_dyn_iarr *instruct)
{
    int push_count;

    // stack_ab_print(stack_1, stack_2);
    // printf("Len: %d\n", len);
    if (stack_1->ref == STACK_A && stack_sub_issort(stack_1, len))
        return ;
    if (stack_1->ref == STACK_B && stack_sub_issort_r(stack_1, len))
    {
        ps_push_a_n(stack_2, stack_1, instruct, len);
        return ;
    }
    if (len == 2)
     {
         if (stack_1->ref == STACK_A)
            ps_swap_top(stack_1, instruct);
         else if (stack_1->ref == STACK_B)
         {
            ps_swap_top(stack_1, instruct);
            ps_push_a_n(stack_2, stack_1, instruct, 2);
         }
         return ;
     }
    push_count = partition(stack_1, stack_2, len, instruct);
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

void
    magic_quick_sort(t_param *param)
{
    magic_quick_sort_rec(param->stack_a, param->stack_b, param->stack_a->bottom - param->stack_a->top, param->instruct);
} 