#include "push_swap.h"

void
	ps_fatal(t_param *param, char *error_msg)
{
	if (param->input)
		free(param->input);
	if (param->instruct)
		free(param->instruct->arr);
	if (param->min_instruct)
		free(param->min_instruct->arr);
	if (param->stack_a)
		free(param->stack_a->stack);
	if (param->stack_b)
		free(param->stack_b->stack);
	dprintf(STDERR_FILENO, "Error: %s\n", error_msg);
	exit(EXIT_FAILURE);
}