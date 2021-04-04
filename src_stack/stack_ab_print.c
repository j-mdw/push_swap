/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:35:15 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 16:35:15 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	stack_ab_print(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int j;
	int space_len;

	space_len = 13;
	i = stack_a->top;
	j = stack_b->top;
	printf("---------------");
	printf("---------------\n");
	while (i < stack_a->bottom || j < stack_b->bottom)
	{
		if (i < stack_a->bottom)
			printf("|%*d|", space_len, stack_a->stack[i]);
		else
			printf("|%*c|", space_len, ' ');
		if (j < stack_b->bottom)
			printf("\t%*d|\n", space_len, stack_b->stack[j]);
		else
			printf("\t%*c|\n", space_len, ' ');
		i++;
		j++;
	}
	printf("---------------");
	printf("---------------\n");
}
