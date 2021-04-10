/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_instruct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:41:40 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/10 23:27:06 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static t_skip_list
	*fwd_check_get_list(void)
{
	static t_skip_list	skip_list[8] = {
		{SWAP_A, SWAP_B, SWAP_AB, {RU_A, RD_A, SWAP_A}},
		{SWAP_B, SWAP_A, SWAP_AB, {RU_B, RD_B, SWAP_B}},
		{RU_A, RU_B, RU_AB, {RU_A, RD_A, SWAP_A}},
		{RU_B, RU_A, RU_AB, {RU_B, RD_B, SWAP_B}},
		{RD_A, RD_B, RD_AB, {RD_A, RU_A, SWAP_A}},
		{RD_B, RD_A, RD_AB, {RD_B, RU_B, SWAP_B}},
		{RU_A, RD_A, -1, {RU_B, RD_B, SWAP_B}},
		{RU_B, RD_B, -1, {RU_A, RD_A, SWAP_A}}};

	return (skip_list);
}

static void
	forward_check(int *arr, int len)
{
	int			i;
	int			j;
	t_skip_list	*skip_list;

	i = 0;
	j = 1;
	skip_list = fwd_check_get_list();
	while (i < 8)
	{
		if (arr[0] == (skip_list[i]).val)
		{
			while (((j < len) && (arr[j] != (skip_list[i]).find)
			&& isinarr(arr[j], (skip_list[i]).arr, 3)) || (arr[j] < 0))
				j++;
			if (arr[j] == (skip_list[i]).find)
			{
				arr[0] = (skip_list[i]).new;
				arr[j] = -1;
				return ;
			}
			break ;
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
	}
}
