#include "push_swap.h"

void
	rotate_a(t_stack *stack_a, t_stack *stack_b)
{
	stack_rotate_up(stack_a);
	(void)stack_b;
}

void
	rotate_b(t_stack *stack_a, t_stack *stack_b)
{
	stack_rotate_up(stack_b);
	(void)stack_a;
}

void
	rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	stack_rotate_up(stack_a);
	stack_rotate_up(stack_b);
}