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

    printf("Len: %d\n", len);
    if (!(arr_cpy = ft_intarr_dup(&(stack_1->stack[stack_1->top]), len)))
        return (0);
    ft_putintarr(arr_cpy, len);
    med = intarr_median(arr_cpy, len);
    printf("Med: %d\n", med);
    free(arr_cpy);
    push_count = 0;
    i = stack_1->top;
    while (i < (stack_1->top + len))
    {
        if (stack_1->ref == STACK_A && stack_1->stack[i] < med)
        {
            ps_rotate_top(stack_1, instruct, i);
            ps_push_b(stack_1, stack_2, instruct);
            push_count++;
            i = stack_1->top - 1;
        }
        else if (stack_1->ref == STACK_B && stack_1->stack[i] >= med)
        {
            ps_rotate_top(stack_1, instruct, i);
            ps_push_a(stack_1, stack_2, instruct);
            push_count++;
            i = stack_1->top - 1;
        }
        i++;
    }
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

    if (stack_1->ref == STACK_A && stack_sub_issort(stack_1, len))
        return ;
    if (stack_1->ref == STACK_B && stack_sub_issort_r(stack_1, len))
    {
        ps_push_a_n(stack_2, stack_1, instruct, len);
        return ;
    }
    if (stack_len(stack_1) == 2)
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
    stack_ab_print(stack_1, stack_2);
    magic_quick_sort_rec(stack_1, stack_2, len - push_count, instruct);
    magic_quick_sort_rec(stack_2, stack_1, push_count, instruct);
}

void
    magic_quick_sort(t_param *param)
{
//     int pivot;
//     int *arr_cpy;
    // int p = 0;
    // (void)param;

    magic_quick_sort_rec(param->stack_a, param->stack_b, param->stack_a->bottom - param->stack_a->top, param->instruct);
    stack_ab_print(param->stack_a, param->stack_b);
    // while (stack_len(param->stack_a) > 2)
    // {
    //     if (stack_issort(param->stack_a))
    //         break;
    //     if (!partition(param->stack_a, param->stack_b, param->stack_a->top, param->stack_a->bottom, param->instruct))
    //         ps_fatal(param, "");
    //     stack_ab_print(param->stack_a, param->stack_b);
    // }
//    if (!(arr_cpy = ft_intarr_dup(&(stack_1->stack[stack_1->top]), bottom - top)))
//         return (-1);
//     med = intarr_median(arr_cpy, bottom - top);
//     free(arr_cpy);

//     if ((p = partition(param->stack_a, param->stack_b, param->stack_a->top, param->stack_a->bottom, param->instruct)) <= 0)
//         ps_fatal(param, "Partition");
    
    // printf("Median: %d\n", p);
} 