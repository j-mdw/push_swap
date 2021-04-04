/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:35:16 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 16:35:16 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	stack_print(t_stack *stack)
{
	int i;

	i = stack->top;
	if (stack->top == stack->bottom)
		printf("Empty Stack\n");
	else
	{
		printf("---------------\n");
		while (i < stack->bottom)
		{
			printf("|%13d|\n", stack->stack[i]);
			i++;
		}
		printf("---------------\n");
	}
}
