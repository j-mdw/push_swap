/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:41:40 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 16:41:40 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	ps_swap(t_stack *stack, t_dyn_iarr *instruct, int index1, int index2)
{
	int size;
	int ret;

	if ((size = (stack->bottom - stack->top)) < 2)
		return (0);
	if ((ret = ps_are_elem_sbs(stack, index1, index2)) > 0)
	{
		if (ret == 1)
			ps_rotate_top(stack, instruct, index1);
		if (ret == 2)
			ps_rotate_top(stack, instruct, index2);
		ps_swap_top(stack, instruct);
		return (1);
	}
	return (0);
}
