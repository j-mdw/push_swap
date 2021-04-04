/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:35:15 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 16:35:15 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	stack_init(t_stack *stack, int size, int ref)
{
	stack->bottom = size;
	stack->top = size;
	stack->ref = ref;
	if (!(stack->stack = (int *)malloc(sizeof(int) * size)))
		return (0);
	return (1);
}
