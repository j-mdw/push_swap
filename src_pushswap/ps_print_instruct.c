#include "push_swap.h"

void
	ps_print_instruct(t_dyn_iarr *instruct)
{
	int			i;
	int			instruct_i;
	static char *arr[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", 
						 "rra", "rrb", "rrr"};

	i = 0;
	while (i <= instruct->max_i)
	{
		instruct_i = instruct->arr[i];
		printf("%s\n", arr[instruct_i]);
		i++;
	}
}