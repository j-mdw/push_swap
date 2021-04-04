/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dyn_iarray_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:41:39 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 16:41:39 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	dyn_iarray_init(t_dyn_iarr *dyn_arr, int size)
{
	dyn_arr->max_i = -1;
	dyn_arr->size = size;
	if (!(dyn_arr->arr = (int *)malloc(sizeof(int) * size)))
		return (0);
	return (1);
}
