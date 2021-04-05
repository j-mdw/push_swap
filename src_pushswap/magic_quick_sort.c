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
    partition(t_stack *stack_1, t_stack *stack_2, int top, int bottom, t_dyn_iarr *instruct)
{
    int med;
    int *arr_cpy;
    int i;
    int mid;

    if (!(arr_cpy = ft_intarr_dup(&(stack_1->stack[stack_1->top]), bottom - top)))
        return (-1);
    med = intarr_median(arr_cpy, bottom - top);
    free(arr_cpy);
    mid = (bottom - top) / 2;
    i = stack_1->top;
    while (i < bottom)
    {
        if (stack_1->stack[i] < med)
        {
            stack_ab_print(stack_1, stack_2);
            ps_rotate_top(stack_1, instruct, i);
            if (stack_1->ref == STACK_A)
                ps_push_b(stack_1, stack_2, instruct);
            else if (stack_1->ref == STACK_B)
                ps_push_a(stack_1, stack_2, instruct);
            i = stack_1->top - 1;
        }
        i++;
    }
        stack_ab_print(stack_1, stack_2);
    return (med);
}

void
    magic_quick_sort(t_param *param)
{
//     int pivot;
//     int *arr_cpy;
    int p = 0;
    (void)param;

//    if (!(arr_cpy = ft_intarr_dup(&(stack_1->stack[stack_1->top]), bottom - top)))
//         return (-1);
//     med = intarr_median(arr_cpy, bottom - top);
//     free(arr_cpy);

//     if ((p = partition(param->stack_a, param->stack_b, param->stack_a->top, param->stack_a->bottom, param->instruct)) <= 0)
//         ps_fatal(param, "Partition");
    
    printf("Median: %d\n", p);
} 