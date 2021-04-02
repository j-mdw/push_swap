#include "push_swap.h"

void
	swap_a(t_stack *stack_a, t_stack *stack_b)
{
	stack_swap_top_two(stack_a);
	(void)stack_b;
}
void
	swap_b(t_stack *stack_a, t_stack *stack_b)
{
	stack_swap_top_two(stack_b);
	(void)stack_a;
}
void
	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	stack_swap_top_two(stack_a);
	stack_swap_top_two(stack_b);
}
void
	push_a(t_stack *stack_a, t_stack *stack_b)
{
	int pop;

	if (stack_b->top < stack_b->bottom)
	{
		pop = stack_pop(stack_b);
		stack_push(stack_a, pop);
	}
}
void
	push_b(t_stack *stack_a, t_stack *stack_b)
{
	int pop;

	if (stack_a->top < stack_a->bottom)
	{
		pop = stack_pop(stack_a);
		stack_push(stack_b, pop);
	}
}