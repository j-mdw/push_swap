#include "push_swap.h"

void
    ps_push_b(t_stack *stack_a, t_stack *stack_b, t_dyn_iarr *instruct)
{
    int val;

    dyn_iarray_add(instruct, PUSH_B);
    val = stack_pop(stack_a);
    stack_push(stack_b, val);
}