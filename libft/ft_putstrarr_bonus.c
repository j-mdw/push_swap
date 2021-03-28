/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:25:05 by jmaydew           #+#    #+#             */
/*   Updated: 2021/03/27 16:58:30 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_putstrarr(char **arr)
{
	int i;

	if (arr)
	{
		i = 0;
		while (arr[i])
		{
			ft_putstr_fd(arr[i], 1);
			write(1, "\n", 1);
			i++;
		}
	}
}