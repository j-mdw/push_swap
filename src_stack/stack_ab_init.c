/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:35:15 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 16:36:50 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	stack_ab_init(t_stack *stack_a, t_stack *stack_b, char **input, int size)
{
	int i;
	int j;
	int overflow;

	stack_b->stack = NULL;
	if (!stack_init(stack_a, size, STACK_A))
		stack_ab_fatal(stack_a, stack_b, "Malloc error");
	if (!stack_init(stack_b, size, STACK_B))
		stack_ab_fatal(stack_a, stack_b, "Malloc error");
	i = size - 1;
	while (i >= 0)
	{
		stack_push(stack_a, ft_atoi_overflow(input[i], &overflow));
		if (overflow == 1)
			stack_ab_fatal(stack_a, stack_b, "Input larger than INT");
		j = size - 1;
		while (j > i)
		{
			if (stack_a->stack[j] == stack_a->stack[i])
				stack_ab_fatal(stack_a, stack_b,
				"Multiple occurences of value");
			j--;
		}
		i--;
	}
}
