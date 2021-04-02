#include "push_swap.h"

void
	exec_instructions(t_stack *stack_a, t_stack *stack_b, int flag)
{
	char			buf[4];
	int				ret;
	t_stack_func	*stack_func_arr;
	int				i;

	stack_func_arr = set_stack_func_arr();
	while ((ret = read(STDIN_FILENO, buf, 3)) == 3)
	{
		if (buf[2] != '\n' && (ret += read(STDIN_FILENO, &buf[3], 1)) != 4)
			stack_ab_fatal(stack_a, stack_b, "Unknown instruction");
		buf[ret - 1] = '\0';
		i = 0;
		while (i < AVAIL_INSTRUCT)
		{
			if (!ft_strcmp(buf, (stack_func_arr[i]).name))
			{
				(stack_func_arr[i]).stack_func(stack_a, stack_b);
				break;
			}
			i++;
		}
		if (flag == 1)
			stack_ab_print(stack_a, stack_b);
	}
	if (ret != 0)
		stack_ab_fatal(stack_a, stack_b, "Unknown instruction");
}