// #include "push_swap.h"

// void
// 	init_stack_ab(t_param *param, char **input, int size)
// {
// 	int i;
// 	int j;
// 	int overflow;

// 	param->stack_b->stack = NULL;
// 	if (!stack_init(param->stack_a, size))
// 		ps_fatal(param, "Malloc error");
// 	if (!stack_init(param->stack_b, size))
// 		ps_fatal(param, "Malloc error");
// 	i = size - 1;
// 	while (i >= 0)
// 	{
// 		param->stack_a->stack[i] = ft_atoi_overflow(input[i], &overflow);
// 		if (overflow == 1)
// 			ps_fatal(param, "Input larger than INT");
// 		j = size - 1;
// 		while (j > i)
// 		{
// 			if (param->stack_a->stack[j] == param->stack_a->stack[i])
// 				ps_fatal(param, "Multiple occurences of value");
// 			j--;
// 		}
// 		i--;
// 	}
// 	param->stack_a->
// 	ft_putintarr(param->stack_a->stack, size); // TB Deleted
// }