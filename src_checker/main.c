/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <jmaydew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:37:46 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 17:11:35 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int
	sort_check_stack(t_stack *stack_a, t_stack *stack_b, int flag)
{
	exec_instructions(stack_a, stack_b, flag);
	if (ft_isintarr_sort(&stack_a->stack[stack_a->top],
		stack_len(stack_a)) && stack_len(stack_b) == 0)
		printf("OK\n");
	else
		printf("KO\n");
	return (0);
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
	if (ac == 1)
		return (0);
	if (!ft_strcmp(*av, V_FLAG))
	{
		flag |= 1;
		av++;
	}
	if ((ret = input_isintarr(ac - 1 - flag, av)) != -1)
		ft_putstr_fd("Error\n", 2);
	else
	{
		stack_ab_init(&stack_a, &stack_b, av, ac - 1 - flag);
		return (sort_check_stack(&stack_a, &stack_b, flag));
	}
	return (EXIT_FAILURE);
}
