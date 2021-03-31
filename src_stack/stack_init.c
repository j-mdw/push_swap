#include "push_swap.h"

int
	stack_init(t_stack *stack, int size, int ref)
{
	stack->bottom = size;
	stack->top = size;
	stack->ref = ref;
	if (!(stack->stack = (int *)malloc(sizeof(int) * size)))
		return (0);
	return (1);
}