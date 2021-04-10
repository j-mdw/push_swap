/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_quick_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:31:03 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/07 14:31:38 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	ft_iarr_cpy(int *src, int *dst, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

static void
	magic_sort_4(t_stack *stack_1, t_stack *stack_2, t_dyn_iarr *instruct,
	int len)
{
	int i;
	int j;
	int arr[4];

	ft_iarr_cpy(&(stack_1->stack[stack_1->top]), arr, len);
	i = 1;
	while (i < len)
	{
		j = i;
		while (j > 0)
		{
			if ((stack_1->ref == STACK_A && arr[j] < arr[j - 1]) ||
				(stack_1->ref == STACK_B && arr[j] > arr[j - 1]))
			{
				ps_swap(stack_1, instruct, stack_get_index(stack_1, arr[j]),
				stack_get_index(stack_1, arr[j - 1]));
				ft_swap_int(arr, j, j - 1);
			}
			j--;
		}
		i++;
	}
	ps_rotate_top(stack_1, instruct, stack_get_index(stack_1, arr[0]));
	if (stack_1->ref == STACK_B)
		ps_push_a_n(stack_2, stack_1, instruct, len);
}

static void
	len_2_routine(t_stack *stack_1, t_stack *stack_2, t_dyn_iarr *instruct)
{
	if (stack_1->ref == STACK_A)
		ps_swap_top(stack_1, instruct);
	else if (stack_1->ref == STACK_B)
	{
		ps_swap_top(stack_1, instruct);
		ps_push_a_n(stack_2, stack_1, instruct, 2);
	}
}

static void
	magic_quick_sort_rec(t_stack *stack_1, t_stack *stack_2,
	int len, t_dyn_iarr *instruct)
{
	int p;

	if (stack_1->ref == STACK_A && stack_sub_issort(stack_1, len))
		return ;
	else if (stack_1->ref == STACK_B && stack_sub_issort_r(stack_1, len))
		ps_push_a_n(stack_2, stack_1, instruct, len);
	else if (len == 2)
		len_2_routine(stack_1, stack_2, instruct);
	else if (len <= 4)
		magic_sort_4(stack_1, stack_2, instruct, len);
	else
	{
		p = magic_partition(stack_1, stack_2, len, instruct);
		if (stack_1->ref == STACK_A)
		{
			magic_quick_sort_rec(stack_1, stack_2, len - p, instruct);
			magic_quick_sort_rec(stack_2, stack_1, p, instruct);
		}
		else
		{
			magic_quick_sort_rec(stack_2, stack_1, p, instruct);
			magic_quick_sort_rec(stack_1, stack_2, len - p, instruct);
		}
	}
}

void
	magic_quick_sort(t_param *param)
{
	magic_quick_sort_rec(param->stack_a, param->stack_b,
	param->stack_a->bottom - param->stack_a->top, param->instruct);
}
