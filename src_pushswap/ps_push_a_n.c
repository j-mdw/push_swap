/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_a_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:33:47 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/07 14:33:49 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ps_push_a_n(t_stack *stack_a, t_stack *stack_b,
	t_dyn_iarr *instruct, int n)
{
	int val;
	int i;

	i = 0;
	while (i < n)
	{
		dyn_iarray_add(instruct, PUSH_A);
		val = stack_pop(stack_b);
		stack_push(stack_a, val);
		i++;
	}
}
