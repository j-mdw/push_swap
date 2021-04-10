#include "push_swap.h"

static void
	init_sort_func_arr(t_sort_func *sort_func)
{
	sort_func[0] = magic_quick_sort;
	// sort_func[0] = ps_insertion_sort;
	// sort_func[1] = ps_selection_sort;
	// sort_func[2] = magic_quick_sort;
	// sort_func[3] = ps_bubble_sort;
	// sort_func[4] = ps_bubble_sort_v2;
	// sort_func[5] = ps_selection_sort_v2;
}

static void
	ps_init_param(t_param *param)
{
	param->input = NULL;
	param->instruct = NULL;
	param->min_instruct = NULL;
	param->stack_a = NULL;
	param->stack_b = NULL;
}

static void
	get_best_sort(t_param *param, t_sort_func *sort_func, int len, int fromqs)
{
	int i;
	// int algo;

	// algo = (len > 10) * 1;
	i = 0;
	// while (i < SORT_FUNC_COUNT - algo)
    while (i < SORT_FUNC_COUNT - fromqs)
	{
		ps_sort_stack(param, len, sort_func[i]);
		// printf("|%d\n", param->instruct->max_i + 1);
		if (!param->min_instruct->arr || param->min_instruct->max_i >
		param->instruct->max_i)
		{
			if (param->min_instruct->arr)
				free(param->min_instruct->arr);
			param->min_instruct->arr = param->instruct->arr;
			param->min_instruct->max_i = param->instruct->max_i;
			param->min_instruct->size = param->instruct->size;
			param->instruct->arr = NULL;
		}
		else
			free(param->instruct->arr);
		param->instruct->arr = NULL;
		i++;
	}
}

void
	ps_get_best_sort(int *input, int len, t_dyn_iarr *min_instruct, int fromqs)
{
	t_param		param;
	t_dyn_iarr	instruct;
	t_sort_func	sort_func[SORT_FUNC_COUNT];	
	
	ps_init_param(&param);
	param.input = input;
	init_sort_func_arr(sort_func);
	min_instruct->arr = NULL;
	param.min_instruct = min_instruct;
	instruct.arr = NULL;
	param.instruct = &instruct;
	get_best_sort(&param, sort_func, len, fromqs);
}