#include "push_swap.h"

int
	stack_init(t_stack *stack, int size)
{
	stack->bottom = size;
	stack->top = size;
	if (!(stack->stack = (int *)malloc(sizeof(int) * size)))
		return (0);
	return (1);
}