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
	magic_sort_n(t_stack *stack_1, t_stack *stack_2, t_dyn_iarr *instruct, int len)
{
	int i;
	int j;
	int arr[QS_OPTI];

	(void)stack_2;
	i = -1;
	while (++i < len)
		arr[i] = stack_1->stack[stack_1->top + i];
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
}


static int
	stack_sub_issort(t_stack *stack, int len)
{
	int i;

	i = stack->top;
	while (i < (stack->top + len - 1))
	{
		if (stack->stack[i] > stack->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int
	stack_sub_issort_r(t_stack *stack, int len)
{
	int i;

	i = stack->top;
	while (i < (stack->top + len - 1))
	{
		if (stack->stack[i] < stack->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
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

void
	stack_cpy(t_stack *src, t_stack *dst)
{
	dst->bottom = src->bottom;
	dst->top = src->top;
	dst->ref = src->ref;
	dst->stack = ft_intarr_dup(src->stack, src->bottom);
}

static void
	try_sort(t_stack *stack_1, t_stack *stack_2, int len, t_dyn_iarr *instruct)
{
	int min;
	int start_i;
	t_stack cpy_1;
	t_stack cpy_2;

	stack_cpy(stack_1, &cpy_1);
	stack_cpy(stack_2, &cpy_2);
	if (!cpy_1.stack && !cpy_2.stack)
	{
		start_i = instruct->max_i;
		magic_sort_n(&cpy_1, &cpy_2, instruct, len);
		min = instruct->max_i;
		instruct->max_i = start_i;
		free(cpy_1.stack);
		free(cpy_2.stack);
		stack_cpy(stack_1, &cpy_1);
		stack_cpy(stack_2, &cpy_2);
		if (!cpy_1.stack && !cpy_2.stack)
		{	
			magic_selec_sort_n(&cpy_1, &cpy_2, instruct, len);
			free(cpy_1.stack);
			free(cpy_2.stack);
			if (instruct->max_i > min)
			{
				instruct->max_i = start_i;
				magic_sort_n(stack_1, stack_2, instruct, len);
				if (stack_1->ref == STACK_B)
					ps_push_a_n(stack_2, stack_1, instruct, len);
			}
		}
	}
	magic_selec_sort_n(stack_1, stack_2, instruct, len);
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
	else if (len <= QS_OPTI)
		try_sort(stack_1, stack_2, len, instruct);
		// magic_sort_4(stack_1, stack_2, instruct, len);

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
