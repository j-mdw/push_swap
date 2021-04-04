/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap_top_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:35:16 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 16:35:16 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	stack_swap_top_two(t_stack *stack)
{
	int *arr;
	int store;

	arr = stack->stack;
	if ((stack->bottom - stack->top) > 1)
	{
		store = arr[stack->top];
		arr[stack->top] = arr[stack->top + 1];
		arr[stack->top + 1] = store;
	}
}
