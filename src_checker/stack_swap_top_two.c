#include "push_swap.h"

void
	stack_swap_top_two(t_stack *stack)
{
	int *arr;
	int store;

	arr = stack->stack;
	if ((stack->bottom - stack->top) > 1)
	{
		store = arr[stack->top];
		arr[stack->top] = arr[stack->top + 1];
		arr[stack->top + 1] = store;
	}
}