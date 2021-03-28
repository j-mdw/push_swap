#include "push_swap.h"

void
	init_param(t_stack *stack_a, t_stack *stack_b, char **input, int len)
{
	int i;
	int overflow;

	stack_a->bottom = len - 1;
	stack_a->top = 0;
	stack_b->bottom = len - 1;
	stack_b->top = len - 1;

	stack_b->stack = NULL;
	if (!(stack_a->stack = (int *)malloc(sizeof(int) * len)))
		fatal(stack_a, stack_b, "Malloc error");
	if (!(stack_b->stack = (int *)malloc(sizeof(int) * len)))
		fatal(stack_a, stack_b, "Malloc error");
	i = 0;
	while (i < len)
	{
		stack_a->stack[i] = ft_atoi_overflow(input[i], &overflow);
		if (overflow == 1)
			fatal(stack_a, stack_b, "Input larger than INT");
		i++;
	}
	ft_putintarr(stack_a->stack, len); // TB Deleted
}