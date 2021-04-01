#include "push_swap.h"

/*
** "Are elements side by side?"
** If index1 is on top of index2 - Return 1
** If index2 is on top of index1 - Return 2
** Return 0 otherwise
*/
int
    ps_are_elem_sbs(t_stack *stack, int index1, int index2)
{
    if (((index1 - index2) == -1) || 
    (index1 == stack->bottom - 1 && index2 == stack->top))
        return (1);
    if (((index1 - index2) == 1 )|| 
    (index1 == stack->top && index2 == stack->bottom - 1))
        return (2);
    return (0);
}