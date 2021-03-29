#include "push_swap.h"

// int
// 	is_sort(int *arr, int len);

void
	stack_push_from(t_stack *stack1, t_stack *stack2)
{
	int pop;

	if (stack2->top < stack2->bottom)
	{
		pop = stack_pop(stack2);
		stack_push(stack1, pop);
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
		if (!ft_strcmp(buf, "sa"))
			stack_swap_top_two(stack_a);
		else if (!ft_strcmp(buf, "sb"))
			stack_swap_top_two(stack_b);
		else if (!ft_strcmp(buf, "ss"))
		{
			stack_swap_top_two(stack_a);
			stack_swap_top_two(stack_b);
		}
		else if (!ft_strcmp(buf, "pa"))
			stack_push_from(stack_a, stack_b);
		else if (!ft_strcmp(buf, "pb"))
			stack_push_from(stack_b, stack_a);
		else if (!ft_strcmp(buf, "ra"))
			stack_rotate_up(stack_a);
		else if (!ft_strcmp(buf, "rb"))
			stack_rotate_up(stack_b);
		else if (!ft_strcmp(buf, "rr"))
		{
			stack_rotate_up(stack_a);
			stack_rotate_up(stack_b);
		}
		else if (!ft_strcmp(buf, "rra"))
			stack_rotate_down(stack_a);
		else if (!ft_strcmp(buf, "rrb"))
			stack_rotate_down(stack_b);
		else if (!ft_strcmp(buf, "rrr"))
		{
			stack_rotate_down(stack_a);
			stack_rotate_down(stack_b);
		}
		else
			fatal(stack_a, stack_b, "Unknown instruction");
		printf("Stack A:\n");
		stack_print(stack_a);
		printf("Stack B:\n");
		stack_print(stack_b);
	}
	if (ret != 0)
		fatal(stack_a, stack_b, "Unknown instruction");
}

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
		// Check doublons
		stack_print(&stack_a);
		exec_instructions(&stack_a, &stack_b);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
