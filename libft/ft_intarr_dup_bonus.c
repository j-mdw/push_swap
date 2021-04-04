/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarr_dup_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:31:43 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 15:31:46 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	*ft_intarr_dup(int *arr, int len)
{
	int *arr_cpy;
	int i;

	if (!(arr_cpy = (int *)malloc(sizeof(int) * len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		arr_cpy[i] = arr[i];
		i++;
	}
	return (arr_cpy);
}
