#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "libft.h"
#include <limits.h>

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
#define SATCK_B 1

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

/*
CHECKER
*/
void    init_param(t_stack *stack_a, t_stack *stack_b, char **input, int len);
void    fatal(t_stack *stack_a, t_stack *stack_b, char *error_msg);
int     input_isintarr(int len, char **arr);

/*
STACK
*/
void	stack_push(t_stack *stack, int val);
int		stack_pop(t_stack *stack);
void	stack_swap_top_two(t_stack *stack);
void	stack_rotate_up(t_stack *stack);
void	stack_print(t_stack *stack);
int		stack_init(t_stack *stack, int size);
void	stack_rotate_down(t_stack *stack);

/*
DYNAMIC INT ARR
*/
int		dyn_iarray_add(t_dyn_iarr *dyn_arr, int val);
#endif
