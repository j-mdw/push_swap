/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 23:26:02 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/10 23:26:05 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int
	ps_insertionsort(t_stack *stack, t_dyn_iarr *instruct, int len)
{
	int i;
	int j;
	int *arr;

	if (!(arr = ft_intarr_dup(&(stack->stack[stack->top]), stack_len(stack))))
		return (0);
	i = 1;
	while (i < len)
	{
		j = i;
		while (j > 0)
		{
			if (arr[j - 1] > arr[j])
			{
				ps_swap(stack, instruct, stack_get_index(stack, arr[j]),
				stack_get_index(stack, arr[j - 1]));
				ft_swap_int(arr, j, j - 1);
			}
			j--;
		}
		i++;
	}
	ps_rotate_top(stack, instruct, stack_get_index(stack, arr[0]));
	free(arr);
	return (1);
}

void
	ps_insertion_sort(t_param *param)
{
	if (!ps_insertionsort(param->stack_a, param->instruct,
	stack_len(param->stack_a)))
		ps_fatal(param, "");
}
