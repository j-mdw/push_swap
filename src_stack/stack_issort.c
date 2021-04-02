#include "push_swap.h"

int
    stack_issort(t_stack *stack)
{
    int i;

    i = stack->top;
    while (i < stack->bottom - 1)
    {
        if (stack->stack[i] > stack->stack[i + 1])
            return (0);
        i++;
    }
    return (1);
}