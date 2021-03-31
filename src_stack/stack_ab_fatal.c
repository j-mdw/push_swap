#include "push_swap.h"

void
	stack_ab_fatal(t_stack *stack_a, t_stack *stack_b, char *error_msg)
{
	free(stack_a->stack);
	free(stack_b->stack);
	dprintf(STDERR_FILENO, "Error: %s\n", error_msg);
	exit(EXIT_FAILURE);
}