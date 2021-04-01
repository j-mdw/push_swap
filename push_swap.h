#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "libft.h"
#include <limits.h>

#define V_FLAG "-v"

#define SWAP_A 0
#define SWAP_B 1
#define SWAP_AB 2
#define PUSH_A 3
#define PUSH_B 4
#define RU_A 5
#define RU_B 6
#define RU_AB 7
#define RD_A 8
#define RD_B 9
#define RD_AB 10

#define STACK_A 0
#define STACK_B 1

typedef struct	s_stack {
	int	ref;
	int top;
	int bottom;
	int *stack;
}				t_stack;


typedef struct  t_dyn_iarray {
    int     max_i;
    int     size;
    int     *arr;
}               t_dyn_iarr;

typedef struct	s_check_param {
	t_stack *stack_a;
	t_stack *stack_b;
}				t_check_param;

typedef struct	s_param {
	t_dyn_iarr	*instruct;
	t_stack		*stack_a;
	t_stack		*stack_b;
}				t_param;

/*
** CHECKER
*/

int     input_isintarr(int len, char **arr);

/*
** STACK
*/
void	stack_push(t_stack *stack, int val);
int		stack_pop(t_stack *stack);
void	stack_swap_top_two(t_stack *stack);
void	stack_rotate_up(t_stack *stack);
void	stack_print(t_stack *stack);
int		stack_init(t_stack *stack, int size, int ref);
void	stack_rotate_down(t_stack *stack);
void    stack_ab_init(t_stack *stack_a, t_stack *stack_b, char **input, int len);
void    stack_ab_fatal(t_stack *stack_a, t_stack *stack_b, char *error_msg);

/*
** DYNAMIC INT ARR
*/
int		dyn_iarray_init(t_dyn_iarr *dyn_arr, int size);
int		dyn_iarray_add(t_dyn_iarr *dyn_arr, int val);

/*
** PUSH SWAP PROGRAM
*/
void	ps_fatal(t_param *param, char *error_msg);
void	ps_bubble_sort(t_param *param);

#endif
