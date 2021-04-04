/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:41:40 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 16:43:06 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	pushswap_sort(t_param *param)
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
