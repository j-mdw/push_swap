#include "push_swap.h"

void
	init_sort_func_arr(t_sort_func *sort_func)
{
	sort_func[0] = ps_bubble_sort;
	sort_func[1] = ps_bubble_sort_v2;
	sort_func[2] = pushswap_sort;
}

void
	ps_init_param_v2(t_param *param)
{
	param->input = NULL;
	param->instruct = NULL;
	param->min_instruct = NULL;
	param->stack_a = NULL;
	param->stack_b = NULL;
}

int
	main(int ac, char **av)
{
	t_param		param;
	t_dyn_iarr	instruct;
	t_dyn_iarr	min_instruct;
	t_sort_func	sort_func[SORT_FUNC_COUNT];
	int			i;

	ps_init_param_v2(&param);
	av++;
	if (!(param.input = parse_iarr_input(av, ac - 1)))
		ps_fatal(&param, "");
	init_sort_func_arr(sort_func);
	min_instruct.arr = NULL;
	param.min_instruct = &min_instruct;
	instruct.arr = NULL;
	param.instruct = &instruct;
	i = 0;
	while (i < SORT_FUNC_COUNT)
	{
		if(!ps_sort_stack(&param, ac - 1, sort_func[i]))
			ps_fatal(&param, "Sort_stack returned error");
		// printf("Algo result (instructions): %d\n", param.instruct->max_i + 1);
		if (!param.min_instruct->arr || param.min_instruct->max_i > param.instruct->max_i)
		{	
			if (param.min_instruct->arr)
				free(param.min_instruct->arr);
			param.min_instruct->arr = param.instruct->arr;
			param.min_instruct->max_i = param.instruct->max_i;
			param.min_instruct->size = param.instruct->size;
			param.instruct->arr = NULL;
		}
		else
			free(param.instruct->arr);
		param.instruct->arr = NULL;
		i++;
	}
	ps_print_instruct(&min_instruct);
	free(min_instruct.arr);

	return (EXIT_SUCCESS);
}
 // While reading the instructions and writting them to stdout, if a swap_a is followed by a swap_b (or the other way around), write a swap_ab instead
 // Do same thing for rotate instructions