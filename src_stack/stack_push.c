#include "push_swap.h"

void
	stack_push(t_stack *stack, int val)
{
	if (stack->top > 0)
	{
		stack->top--;
		stack->stack[stack->top] = val;
	}
}