#include "push_swap.h"

int
    ps_swap(t_stack *stack, t_dyn_iarr *instruct, int index1, int index2)
{
    int size;
    int ret;

    if ((size = (stack->bottom - stack->top)) < 2)
        printf("Less than 2 elements in stack, nothing to swap\n"); //DEBUG
    if ((ret = ps_are_elem_sbs(stack, index1, index2)) > 0) 
    {
        // printf("SBS ret: %d\n", ret);
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