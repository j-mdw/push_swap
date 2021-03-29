#include "push_swap.h"

void
	init_param(t_stack *stack_a, t_stack *stack_b, char **input, int size)
{
	int i;
	int j;
	int overflow;

	stack_b->stack = NULL;
	if (!stack_init(stack_a, size))
		fatal(stack_a, stack_b, "Malloc error");
	if (!stack_init(stack_b, size))
		fatal(stack_a, stack_b, "Malloc error");
	i = 0;
	while (i < size)
	{
		stack_push(stack_a, ft_atoi_overflow(input[i], &overflow));
		if (overflow == 1)
			fatal(stack_a, stack_b, "Input larger than INT");
		j = 0;
		while (j < i)
		{
			if (stack_a->stack[j] == stack_a->stack[i])
				fatal(stack_a, stack_b, "Multiple occurences of value");
			j++;
		}
		i++;
	}
	ft_putintarr(stack_a->stack, size); // TB Deleted
}