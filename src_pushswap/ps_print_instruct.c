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
	int		arr[3];
}				t_skip_list;

static int
	forward_check(int *arr, int len)
{
	static t_skip_list skip_list[AVAIL_INSTRUCT] = {
		{SWAP_A, SWAP_B, {RU_A, RD_A, SWAP_A}},
		{SWAP_B, SWAP_A, {RU_B, RD_B, SWAP_B}},
		{RU_A, RU_B, {RU_A, RD_A, SWAP_A}},
		{RU_B, RU_A, {RU_B, RD_B, SWAP_B}},
		{RD_A, RD_B, {RD_A, RU_A, SWAP_A}},
		{RD_B, RD_A, {RD_B, RU_B, SWAP_B}}}
	};



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
		if (instruct->arr[i])
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
