/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_selection_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:28:53 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/10 23:28:16 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ps_selection_sort(t_param *param)
{
	int *arr;
	int i;

	if (!(arr = ft_intarr_dup(param->stack_a->stack,
	stack_len(param->stack_a))))
		ps_fatal(param, "");
	quick_sort(arr, stack_len(param->stack_a));
	i = 0;
	while (stack_len(param->stack_a) > 2 && !(stack_issort(param->stack_a)))
	{
		ps_rotate_top(param->stack_a, param->instruct,
		stack_get_index(param->stack_a, arr[i]));
		ps_push_b(param->stack_a, param->stack_b, param->instruct);
		i++;
	}
	if (param->stack_a->stack[param->stack_a->top] >
	param->stack_a->stack[param->stack_a->top + 1])
		ps_swap_top(param->stack_a, param->instruct);
	while (param->stack_b->top < param->stack_b->bottom)
		ps_push_a(param->stack_a, param->stack_b, param->instruct);
	free(arr);
}

int
	ft_iarr_getindex(int *arr, int len, int val)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == val)
			return (i);
		i++;
	}
	return (0);
}
