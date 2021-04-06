/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_instruct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:41:40 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/04 16:41:40 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int
	shortcut(int *arr)
{
	if ((arr[0] == SWAP_A && arr[1] == SWAP_B) ||
	(arr[0] == SWAP_B && arr[1] == SWAP_A))
		return (SWAP_AB);
	else if ((arr[0] == RU_A && arr[1] == RU_B) ||
	(arr[0] == RU_A && arr[1] == RU_B))
		return (RU_AB);
	else if ((arr[0] == RD_A && arr[1] == RD_B) ||
	(arr[0] == RD_A && arr[1] == RD_B))
		return (RD_AB);
	return (0);
}

void
	ps_print_instruct(t_dyn_iarr *instruct)
{
	int			i;
	int			instruct_i;
	static char *arr[] = {
	"sa", "sb", "ss",
	"pa", "pb",
	"ra", "rb", "rr",
	"rra", "rrb", "rrr"};

	i = 0;
	while (i <= instruct->max_i)
	{
		if (i < instruct->max_i && (instruct_i = shortcut(&instruct->arr[i])))
		{	
			printf("%s\n", arr[instruct_i]);
			i += 2;
		}
		else
		{
			instruct_i = instruct->arr[i];
			printf("%s\n", arr[instruct_i]);
			i++;
		}
	}
}
