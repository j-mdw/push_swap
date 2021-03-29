#include "push_swap.h"

int
	stack_pop(t_stack *stack)
{
	if (stack->top < stack->bottom)
	{
		stack->top++;
		return (stack->stack[stack->top - 1]);
	}
	return (0);
}