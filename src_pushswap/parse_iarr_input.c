/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_iarr_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:41:39 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 16:45:03 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int
	*parse_iarr_fatal(int *arr)
{
	free(arr);
	return (NULL);
}

static int
	ps_input_isintarr(int len, char **arr)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (!ft_isnumber(arr[i]))
			return (i);
		i++;
	}
	return (0);
}

int
	*parse_iarr_input(char **input, int size)
{
	int i;
	int j;
	int *arr;
	int overflow;

	if (ps_input_isintarr(size, input) != 0)
		return (NULL);
	if (!(arr = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = ft_atoi_overflow(input[i], &overflow);
		if (overflow == 1)
			return (parse_iarr_fatal(arr));
		j = 0;
		while (j < i)
		{
			if (arr[j] == arr[i])
				return (parse_iarr_fatal(arr));
			j++;
		}
		i++;
	}
	return (arr);
}
