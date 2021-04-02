#include "push_swap.h"

void
	rrotate_a(t_stack *stack_a, t_stack *stack_b)
{
	stack_rotate_down(stack_a);
	(void)stack_b;
}

void
	rrotate_b(t_stack *stack_a, t_stack *stack_b)
{
	stack_rotate_down(stack_b);
	(void)stack_a;
}

void
	rrotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	stack_rotate_down(stack_a);
	stack_rotate_down(stack_b);
}