#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "libft.h"

typedef struct	s_stack {
	int top;
	int bottom;
	int *stack;
}				t_stack;

typedef struct	s_check_param {
	t_stack *stack_a;
	t_stack *stack_b;
}				t_check_param;

void    init_param(t_stack *stack_a, t_stack *stack_b, char **input, int len);
void    fatal(t_stack *stack_a, t_stack *stack_b, char *error_msg);
int     input_isintarr(int len, char **arr);
#endif
