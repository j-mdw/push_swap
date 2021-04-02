#include "push_swap.h"

int
    stack_len(t_stack *stack)
{
    return (stack->bottom - stack->top);
}