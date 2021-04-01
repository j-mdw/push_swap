#include "push_swap.h"

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

int
	exec_instructions(t_stack *stack_a, t_stack *stack_b, int flag)
{
	char	buf[4];
	int		ret;
	int		count;

	count = 0;
	while ((ret = read(STDIN_FILENO, buf, 3)) == 3)
	{
		if (buf[2] != '\n' && (ret += read(STDIN_FILENO, &buf[3], 1)) != 4)
			stack_ab_fatal(stack_a, stack_b, "Unknown instruction");
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
			stack_ab_fatal(stack_a, stack_b, "Unknown instruction");
		if (flag == 1)
		{	
			printf("Stack A:\n");
			stack_print(stack_a);
			printf("Stack B:\n");
			stack_print(stack_b);
		}
		count++;
	}
	if (ret != 0)
		stack_ab_fatal(stack_a, stack_b, "Unknown instruction");
	return (count);
}

int
	ft_isintarr_sort(int *arr, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int
	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		ret;
	int		flag;
	int		count;

	av++;
	flag = 0;
	if (ac <= 1)
	{
		dprintf(STDERR_FILENO, "Error - No input\n");
		return (EXIT_FAILURE);
	}
	if (!ft_strcmp(*av, V_FLAG))
	{
		flag |= 1;
		av++;
		ac--;
	}
	if ((ret = input_isintarr(ac - 1, av)) != -1)
		dprintf(STDERR_FILENO, "Error: Input '%s': not a number\n", av[ret]);
	else
	{
		stack_ab_init(&stack_a, &stack_b, av, ac - 1);
		stack_print(&stack_a); //To delete
		count = exec_instructions(&stack_a, &stack_b, flag);
		printf("Nb. of instructions: %d\n", count);
		printf("Stack size: %d\nStack top index: %d\nStack bottom index: %d\n", stack_a.bottom - stack_a.top, stack_a.top, stack_a.bottom);
		stack_print(&stack_a);
		if (ft_isintarr_sort(&stack_a.stack[stack_a.top], stack_a.bottom - stack_a.top))
			printf("OK\n");
		else
			printf("KO\n");
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
