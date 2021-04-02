#include "push_swap.h"

int
    stack_get_index(t_stack *stack, int val)
{
    int i;

    i = stack->top;
    while (i < stack->bottom)
    {
        if (stack->stack[i] == val)
            return (i);
        i++;
    }
    printf("Value not found: %d\n", val); //To be deleted
    return (0);
}