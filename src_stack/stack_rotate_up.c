/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:35:16 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 16:35:16 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	stack_rotate_up(t_stack *stack)
{
	int store;
	int	*arr;
	int i;

	if (stack->top < stack->bottom)
	{
		arr = stack->stack;
		store = arr[stack->top];
		i = stack->top;
		while (i < stack->bottom - 1)
		{
			arr[i] = arr[i + 1];
			i++;
		}
		arr[stack->bottom - 1] = store;
	}
}
