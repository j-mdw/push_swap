/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_func_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:37:46 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 16:37:46 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_func
	*set_stack_func_arr(void)
{
	static t_stack_func arr[AVAIL_INSTRUCT] = {
	{"sa", swap_a},
	{"sb", swap_b},
	{"ss", swap_ab},
	{"pa", push_a},
	{"pb", push_b},
	{"ra", rotate_a},
	{"rb", rotate_b},
	{"rr", rotate_ab},
	{"rra", rrotate_a},
	{"rrb", rrotate_b},
	{"rrr", rrotate_ab}};

	return (arr);
}
