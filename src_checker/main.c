#include "push_swap.h"

t_stack_func
	*set_stack_func_arr()
{
	static t_stack_func arr[AVAIL_INSTRUCT] = {
	{"sa", swap_a},
	{"sb", swap_b},
	{"ss", swap_ab},
	{"pa", push_a},
	{"pb", push_b},
	{"ra", rotate_a},
	{"rb", rotate_b},
	{"rr", rotate_ab},
	{"rra", rrotate_a},
	{"rrb", rrotate_b},
	{"rrr", rrotate_ab}};

	return (arr);
}

int
	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		ret;
	int		flag;

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
		exec_instructions(&stack_a, &stack_b, flag);
		stack_ab_print(&stack_a, &stack_b);
		if (ft_isintarr_sort(&stack_a.stack[stack_a.top], stack_a.bottom - stack_a.top))
			printf("OK\n");
		else
			printf("KO\n");
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
