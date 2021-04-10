/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintarr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:32:08 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/10 23:51:53 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_putintarr(int *arr, int len)
{
	int i;

	if (len != 0)
	{
		i = 0;
		while (i < len)
		{
			ft_putchar_fd('|', 1);
			ft_putnbr_fd(arr[i], 1);
			i++;
		}
		ft_putstr_fd("|\n", 1);
	}
	ft_putchar_fd('\n', 1);
}
