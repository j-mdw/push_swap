/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_instruct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:41:40 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/07 14:33:30 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int
// 	shortcut(int *arr)
// {
// 	if ((arr[0] == SWAP_A && arr[1] == SWAP_B) ||
// 	(arr[0] == SWAP_B && arr[1] == SWAP_A))
// 		return (SWAP_AB);
// 	else if ((arr[0] == RU_A && arr[1] == RU_B) ||
// 	(arr[0] == RU_A && arr[1] == RU_B))
// 		return (RU_AB);
// 	else if ((arr[0] == RD_A && arr[1] == RD_B) ||
// 	(arr[0] == RD_A && arr[1] == RD_B))
// 		return (RD_AB);
// 	return (0);
// }
/*
sa:
Look for: sb 
Continue: ra/rra
sb:
Look for: sa
Continue: rb/rrb
ra:
Look for: rb
Continue: ra/rra/sa
rb:
Look for: ra
Continue: rb/rrb/sb
rra:
Look for: rrb
Continue: rra/ra/pa
rrb:
Look for: rra
Continue: rrb/rb/pb
*/
typedef struct	s_skip_list {
	int		val;
	int		find;
	int		new;
	int		arr[3];
}				t_skip_list;

static int
	isinarr(int val, int *arr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (val == arr[i])
			return (1);
		i++;
	}
	return (0);
}


static void
	forward_check(int *arr, int len)
{
	int					i;
	int					j;
	int					val;
	static t_skip_list	skip_list[6] = {
		{SWAP_A, SWAP_B, SWAP_AB, {RU_A, RD_A, SWAP_A}},
		{SWAP_B, SWAP_A, SWAP_AB, {RU_B, RD_B, SWAP_B}},
		{RU_A, RU_B, RU_AB, {RU_A, RD_A, SWAP_A}},
		{RU_B, RU_A, RU_AB, {RU_B, RD_B, SWAP_B}},
		{RD_A, RD_B, RD_AB, {RD_A, RU_A, SWAP_A}},
		{RD_B, RD_A, RD_AB, {RD_B, RU_B, SWAP_B}}};

	i = 0;
	j = 1;
	val = arr[0];
	while (i < 6)
	{
		if (val == (skip_list[i]).val)
		{
			while ((j < len) && (arr[j] != (skip_list[i]).find) && (isinarr(arr[j], (skip_list[i]).arr, 3)
			|| arr[j] < 0))
				j++;
			if (arr[j] == (skip_list[i]).find)
			{
				arr[0] = (skip_list[i]).new;
				arr[j] = -1;
				return ;
			}
			break;
		}
		i++;
	}
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
		if (instruct->arr[i] < 0)
			i++;
		else
		{
			forward_check(&(instruct->arr[i]), instruct->max_i + 1 - i);
			instruct_i = instruct->arr[i];
			printf("%s\n", arr[instruct_i]);
			i++;
		}
		// if (i < instruct->max_i && (instruct_i = shortcut(&instruct->arr[i])))
		// {
		// 	printf("%s\n", arr[instruct_i]);
		// 	i += 2;
		// }
		// else
		// {
		// 	instruct_i = instruct->arr[i];
		// 	printf("%s\n", arr[instruct_i]);
		// 	i++;
		// }
	}
}
