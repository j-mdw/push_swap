/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:35:16 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 16:35:16 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	stack_rotate_down(t_stack *stack)
{
	int store;
	int	*arr;
	int i;

	if (stack->top < stack->bottom)
	{
		arr = stack->stack;
		store = arr[stack->bottom - 1];
		i = stack->bottom - 1;
		while (i > stack->top)
		{
			arr[i] = arr[i - 1];
			i--;
		}
		arr[stack->top] = store;
	}
}
