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
    partition(t_stack *stack_1, t_stack *stack_2, int top, int bottom)
{
    int med;
    int *arr_cpy;
    int i;

    if (!(arr_cpy = ft_intarr_dup(&(stack_1->stack[stack_1->top]), bottom - top)))
        return (-1);
    med = intarr_median(arr_cpy, bottom - top);
    i = top;
    while (i < bottom)
    {
        if (stack_1->stack[i] < med)
        {
            if (stack_1->ref = STACK_A)
            {
                push_a



    return (med);
}

void
    magic_sort(t_param *param)
{
    int p;

    if ((p = partition(param->stack_a, param->stack_b, param->stack_a->top, param->stack_a->bottom)) <= 0)
        ps_fatal(param, "Partition");
    printf("Median: %d\n", p);
} 