#include "push_swap.h"

// int
// 	is_sort(int *arr, int len);

void
	swap_top(t_stack *stack)
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

void
	exec_instructions(t_stack *stack_a, t_stack *stack_b)
{
	char	buf[4];
	int		ret;

	while ((ret = read(STDOUT_FILENO, buf, 3)) == 3)
	{
		if (buf[2] != '\n' && (ret += read(STDOUT_FILENO, &buf[3], 1)) != 4)
			fatal(stack_a, stack_b, "Unknown instruction");
		buf[ret - 1] = '\0';
		if (ft_strcmp(buf, "sa"))
			swap_top(stack_a);
		else if (ft_strcmp(buf, "sb"))
			swap_top(stack_b);
		else if (ft_strcmp(buf, "ss"))
		{
			swap_top(stack_a);
			swap_top(stack_b);
		}
	}
}
	
	// read
	// parse
	// exec


int
	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		ret;

	av++;
	if (ac <= 1)
		dprintf(STDERR_FILENO, "Error - No input\n");
	else if ((ret = input_isintarr(ac - 1, av)) != -1)
		dprintf(STDERR_FILENO, "Error: Input '%s': not a number\n", av[ret]);
	else
	{
		init_param(&stack_a, &stack_b, av, ac - 1);
		// Check doublons?
		// exec_instructions(&stack_a, &stack_b);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
