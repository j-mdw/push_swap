#include "push_swap.h"

void
	ps_push_a_n(t_stack *stack_a, t_stack *stack_b,
    t_dyn_iarr *instruct, int n)
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