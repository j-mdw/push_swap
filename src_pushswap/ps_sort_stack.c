/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:41:40 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 16:42:07 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ps_sort_stack(t_param *param, int len, void (*ps_sort)(t_param *))
{
	t_stack		stack_a;
	t_stack		stack_b;

	stack_b.stack = NULL;
	param->stack_a = &stack_a;
	param->stack_b = &stack_b;
	if (!stack_init(&stack_a, len, STACK_A))
		ps_fatal(param, "stack init");
	free(stack_a.stack);
	if (!(stack_a.stack = ft_intarr_dup(param->input, len)))
		ps_fatal(param, "int arr dup");
	stack_a.top = 0;
	if (!stack_init(&stack_b, len, STACK_B))
		ps_fatal(param, "stack init");
	if (!dyn_iarray_init(param->instruct, len * 2))
		ps_fatal(param, "Dyn arr init error");
	// printf("ps_sort_stack\n");
	ps_sort(param);
	free(stack_a.stack);
	param->stack_a = NULL;
	free(stack_b.stack);
	param->stack_b = NULL;
}
