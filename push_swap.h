/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaydew <jmaydew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:45:17 by jmaydew           #+#    #+#             */
/*   Updated: 2021/04/10 11:34:08 by jmaydew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"
# include <limits.h>

# define SORT_FUNC_COUNT 5

# define V_FLAG "-v"

# define AVAIL_INSTRUCT 11
# define SWAP_A 0
# define SWAP_B 1
# define SWAP_AB 2
# define PUSH_A 3
# define PUSH_B 4
# define RU_A 5
# define RU_B 6
# define RU_AB 7
# define RD_A 8
# define RD_B 9
# define RD_AB 10

# define STACK_A 0
# define STACK_B 1

typedef struct	s_stack {
	int	ref;
	int top;
	int bottom;
	int *stack;
}				t_stack;

typedef struct	s_dyn_iarray {
	int		max_i;
	int		size;
	int		*arr;
}				t_dyn_iarr;

typedef struct	s_check_param {
	t_stack *stack_a;
	t_stack *stack_b;
}				t_check_param;

typedef struct	s_param {
	t_dyn_iarr	*instruct;
	t_dyn_iarr	*min_instruct;
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			*input;
}				t_param;

typedef void	(*t_sort_func)(t_param *param);

typedef	struct	s_stack_func {
	char	*name;
	void	(*stack_func)(t_stack *stack_a, t_stack *stack_b);
}				t_stack_func;

typedef struct	s_skip_list {
	int		val;
	int		find;
	int		new;
	int		arr[3];
}				t_skip_list;

/*
** CHECKER
*/

int				input_isintarr(int len, char **arr);
void			exec_instructions(t_stack *stack_a, t_stack
				*stack_b, int flag);
void			swap_a(t_stack *stack_a, t_stack *stack_b);
void			swap_b(t_stack *stack_a, t_stack *stack_b);
void			swap_ab(t_stack *stack_a, t_stack *stack_b);
void			push_a(t_stack *stack_a, t_stack *stack_b);
void			push_b(t_stack *stack_a, t_stack *stack_b);
void			rotate_a(t_stack *stack_a, t_stack *stack_b);
void			rotate_b(t_stack *stack_a, t_stack *stack_b);
void			rotate_ab(t_stack *stack_a, t_stack *stack_b);
void			rrotate_a(t_stack *stack_a, t_stack *stack_b);
void			rrotate_b(t_stack *stack_a, t_stack *stack_b);
void			rrotate_ab(t_stack *stack_a, t_stack *stack_b);
t_stack_func	*set_stack_func_arr(void);

/*
** STACK
*/

void			stack_push(t_stack *stack, int val);
int				stack_pop(t_stack *stack);
void			stack_swap_top_two(t_stack *stack);
void			stack_rotate_up(t_stack *stack);
void			stack_print(t_stack *stack);
int				stack_init(t_stack *stack, int size, int ref);
void			stack_rotate_down(t_stack *stack);
void			stack_ab_init(t_stack *stack_a, t_stack *stack_b,
				char **input, int len);
void			stack_ab_fatal(t_stack *stack_a, t_stack *stack_b,
				char *error_msg);
int				stack_len(t_stack *stack);
int				stack_issort(t_stack *stack);
int				stack_issort_r(t_stack *stack);
void			stack_ab_print(t_stack *stack_a, t_stack *stack_b);
int				stack_is_closest(t_stack *stack, int val1, int val2);
int				stack_sub_issort(t_stack *stack, int len);
int				stack_sub_issort_r(t_stack *stack, int len);
/*
** DYNAMIC INT ARR
*/

int				dyn_iarray_init(t_dyn_iarr *dyn_arr, int size);
int				dyn_iarray_add(t_dyn_iarr *dyn_arr, int val);
void			ps_insertion_sort(t_param *param);
/*
** PUSH SWAP PROGRAM
*/
void			magic_selec_sort_n(t_stack *stack_1, t_stack *stack_2,
				t_dyn_iarr *instruct, int len);
void			ps_get_best_sort(int *input, int len,
				t_dyn_iarr *min_instruct);
void			ps_fatal(t_param *param, char *error_msg);
void			ps_bubble_sort(t_param *param);
void			ps_bubble_sort_v2(t_param *param);
void			quick_sort(int *arr, int len);
void			ps_selection_sort(t_param *param);
void			ps_selection_sort_v2(t_param *param);
void			magic_quick_sort(t_param *param);
int				magic_partition(t_stack *stack_1, t_stack *stack_2,
				int len, t_dyn_iarr *instruct);
void			ps_insertion_sort(t_param *param);
int				ps_are_elem_sbs(t_stack *stack, int index1, int index2);
void			ps_rotate_up(t_stack *stack, t_dyn_iarr *instruct);
void			ps_rotate_down(t_stack *stack, t_dyn_iarr *instruct);
void			ps_rotate_top(t_stack *stack, t_dyn_iarr *instruct, int index);
void			ps_push_a(t_stack *stack_a, t_stack *stack_b,
				t_dyn_iarr *instruct);
void			ps_push_b(t_stack *stack_a, t_stack *stack_b,
				t_dyn_iarr *instruct);
int				ps_swap(t_stack *stack, t_dyn_iarr *instruct, int index1,
				int index2);
void			ps_swap_top(t_stack *stack, t_dyn_iarr *instruct);
int				stack_get_index(t_stack *stack, int val);
int				*parse_iarr_input(char **input, int size);
void			ps_sort_stack(t_param *param, int len,
				void (*ps_sort)(t_param *));
void			ps_print_instruct(t_dyn_iarr *instruct);
void			ps_push_a_n(t_stack *stack_a, t_stack *stack_b,
				t_dyn_iarr *instruct, int n);
#endif
