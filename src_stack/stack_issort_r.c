/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_issort_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:35:15 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/06 14:48:48 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	stack_issort_r(t_stack *stack)
{
	int i;

	i = stack->top;
	while (i < stack->bottom - 1)
	{
		if (stack->stack[i] < stack->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}
