/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarr_min_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:35:08 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 15:35:10 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_intarr_min(int *arr, int len)
{
	int i;
	int min;

	min = 0;
	i = 0;
	while (i < len)
	{
		if (arr[i] < arr[min])
			min = i;
		i++;
	}
	return (min);
}
