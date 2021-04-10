/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sub_issort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 23:29:15 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/10 23:29:17 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	stack_sub_issort(t_stack *stack, int len)
{
	int i;

	i = stack->top;
	while (i < (stack->top + len - 1))
	{
		if (stack->stack[i] > stack->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}
