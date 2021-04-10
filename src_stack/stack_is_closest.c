#include "push_swap.h"

static int
    stack_min_dist(t_stack *stack, int val)
{
    int dist;

    dist = stack_get_index(stack, val);
    if ((dist - stack->top) > (stack->bottom - dist + 1))
        dist =  (stack->bottom - dist + 1);
    else
        dist = (dist - stack->top); 
    return (dist);
}

int
    stack_is_closest(t_stack *stack, int val1, int val2)
{
    int dist1;
    int dist2;

    dist1 = stack_min_dist(stack, val1);
    dist2 = stack_min_dist(stack, val2);
    return ((dist2 >= dist1) + 2 * (dist2 < dist1));
}