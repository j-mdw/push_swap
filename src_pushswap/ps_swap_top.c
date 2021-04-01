#include "push_swap.h"

/*
** Swap val1 and val2 in stack->stack, adds push_swap instructions
** return 0 on error, 1 otherwiss
*/
void
    ps_swap_top(t_stack *stack, t_dyn_iarr *instruct)
{
    if (stack->ref == STACK_A)
        dyn_iarray_add(instruct, SWAP_A);
    else if (stack->ref == STACK_B)
        dyn_iarray_add(instruct, SWAP_B);
    stack_swap_top_two(stack);
}