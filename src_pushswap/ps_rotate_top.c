#include "push_swap.h"

void
    ps_rotate_top(t_stack *stack, t_dyn_iarr *instruct, int index)
{
    int mid;
    int len;

    len = stack->bottom - stack->top;
    mid = (len / 2) + (len % 2);
    if (index <  mid)
    {
        while (index-- > stack->top)
            ps_rotate_up(stack, instruct);
    }
    else if (index >= mid)
    {
        while (index++ < stack->bottom)
            ps_rotate_down(stack, instruct);
    }
}