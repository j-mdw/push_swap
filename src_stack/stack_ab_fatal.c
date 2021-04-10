/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab_fatal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:35:15 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 16:35:54 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	stack_ab_fatal(t_stack *stack_a, t_stack *stack_b, char *error_msg)
{
	free(stack_a->stack);
	free(stack_b->stack);
	(void)error_msg;
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
