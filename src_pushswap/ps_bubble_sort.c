/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <jmaydew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:41:40 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 17:50:58 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	bubble_sort_routine(t_param *param, int *arr, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				ps_swap(param->stack_a, param->instruct,
				stack_get_index(param->stack_a, arr[j]),
				stack_get_index(param->stack_a, arr[j + 1]));
				ft_swap_int(arr, j, j + 1);
			}
			j++;
		}
		i++;
	}
}

void
	ps_bubble_sort(t_param *param)
{
	int len;
	int *arr;

	len = param->stack_a->bottom - param->stack_a->top;
	if (!(arr = ft_intarr_dup(param->stack_a->stack, len)))
		ps_fatal(param, "Malloc");
	bubble_sort_routine(param, arr, len);
	ps_rotate_top(param->stack_a, param->instruct,
	ft_intarr_min(param->stack_a->stack, len));
	free(arr);
}

void
	ps_bubble_sort_v2(t_param *param)
{
	int len;
	int *arr;

	len = param->stack_a->bottom - param->stack_a->top;
	ps_rotate_top(param->stack_a, param->instruct,
	ft_intarr_min(param->stack_a->stack, len));
	if (!(arr = ft_intarr_dup(param->stack_a->stack, len)))
		ps_fatal(param, "Malloc");
	bubble_sort_routine(param, arr, len);
	ps_rotate_top(param->stack_a, param->instruct,
	ft_intarr_min(param->stack_a->stack, len));
	free(arr);
}
