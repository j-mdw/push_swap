/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <jmaydew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:41:39 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/07 14:34:20 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	main(int ac, char **av)
{
	int			*input;
	t_dyn_iarr	min_instruct;

	av++;
	if (!(input = parse_iarr_input(av, ac - 1)))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	ps_get_best_sort(input, ac - 1, &min_instruct);
	ps_print_instruct(&min_instruct);
	free(min_instruct.arr);
	free(input);
	return (EXIT_SUCCESS);
}
