/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:41:40 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/07 14:32:53 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ps_rotate_top(t_stack *stack, t_dyn_iarr *instruct, int index)
{
	int mid;
	int len;

	len = stack->bottom - stack->top;
	mid = (len / 2) + (len % 2);
	if ((index - stack->top) < mid)
	{
		while (index-- > stack->top)
			ps_rotate_up(stack, instruct);
	}
	else if ((index - stack->top) >= mid)
	{
		while (index++ < stack->bottom)
			ps_rotate_down(stack, instruct);
	}
}
