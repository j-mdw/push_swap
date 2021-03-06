/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:35:15 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/07 14:35:55 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	stack_get_index(t_stack *stack, int val)
{
	int i;

	i = stack->top;
	while (i < stack->bottom)
	{
		if (stack->stack[i] == val)
			return (i);
		i++;
	}
	return (0);
}
