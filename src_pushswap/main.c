#include "push_swap.h"

void
	ps_init_param(t_param *param, t_dyn_iarr *instruct, t_stack *stack_a, t_stack *stack_b)
{
	param->instruct = instruct;
	param->stack_a = stack_a;
	param->stack_b = stack_b;
}

int
	main(int ac, char **av)
{
	t_param		param;
	t_dyn_iarr	instructions;
	t_stack		stack_a;
	t_stack		stack_b;

	stack_ab_init(&stack_a, &stack_b, ++av, ac - 1);
	ps_init_param(&param, &instructions, &stack_a, &stack_b);
	if (!dyn_iarray_init(&instructions, ac * 2)) //ac * 2 TBU eventually
		ps_fatal(&param, "Malloc");
	ps_bubble_sort(&param);
	printf("Instructions: %d\n", instructions.max_i + 1);
	ft_putintarr(instructions.arr, instructions.max_i + 1);
	free(instructions.arr);
	free(stack_a.stack);
	free(stack_b.stack);

	return (0);
}
 // While reading the instructions and writting them to stdout, if a swap_a is followed by a swap_b (or the other way around), write a swap_ab instead
 // Do same thing for rotate instructions