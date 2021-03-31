#include "push_swap.h"

void
	ps_fatal(t_param *param, char *error_msg)
{
	free(param->instruct->arr);
	free(param->stack_a->stack);
	free(param->stack_b->stack);
	dprintf(STDERR_FILENO, "Error: %s\n", error_msg);
	exit(EXIT_FAILURE);
}