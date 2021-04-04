/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_isintarr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:37:45 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 16:37:45 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	input_isintarr(int len, char **arr)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (!ft_isnumber(arr[i]))
			return (i);
		i++;
	}
	return (-1);
}
