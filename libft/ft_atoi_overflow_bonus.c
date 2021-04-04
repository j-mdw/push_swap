/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_overflow_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:33:03 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 15:34:42 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char
	*ft_check_sign(char *str, int *sign)
{
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
	{
		*sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
		*sign = 1;
	}
	else
		*sign = 1;
	return (str);
}

int
	ft_atoi_overflow(const char *str, int *overflow)
{
	int		sign;
	int		power;
	double	res;
	int		i;

	str = ft_check_sign((char *)str, &sign);
	power = 0;
	while (str[power] <= '9' && str[power] >= '0')
		power++;
	i = 0;
	res = 0;
	while (i < power)
	{
		res = res * 10 + ((str[i] - '0'));
		if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
		{
			*overflow = 1;
			return (-1);
		}
		i++;
	}
	*overflow = 0;
	return (res * sign);
}
