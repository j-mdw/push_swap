#include "push_swap.h"

void
    ps_rotate_down(t_stack *stack, t_dyn_iarr *instruct)
{
    if (stack->ref == STACK_A)
        dyn_iarray_add(instruct, RD_A);
    else if (stack->ref == STACK_B)
        dyn_iarray_add(instruct, RD_B);
    stack_rotate_down(stack);
}