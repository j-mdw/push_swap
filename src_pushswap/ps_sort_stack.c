#include "push_swap.h"

int
	ps_sort_stack(t_param *param, int len, void (*ps_sort)(t_param *))
{
	t_stack		stack_a;
	t_stack		stack_b;

	stack_init(&stack_a, len, STACK_A);
	free(stack_a.stack);
	if (!(stack_a.stack = ft_intarr_dup(param->input, len)))
		return (0);
	stack_a.top = 0;
	stack_init(&stack_b, len, STACK_B);
	param->stack_a = &stack_a;
	param->stack_b = &stack_b;
	if (!dyn_iarray_init(param->instruct, len * 2)) //len * 2 TBU eventually
		ps_fatal(param, "Dyn arr init error");
	ps_sort(param);
	free(stack_a.stack);
	param->stack_a = NULL;
	free(stack_b.stack);
	param->stack_b = NULL;
	return (param->instruct->max_i + 1);
}