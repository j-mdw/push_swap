#include "push_swap.h"

void
	print_instruct(t_dyn_iarr *instruct)
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

int
	*parse_iarr_input(char **input, int size)
{
	int i;
	int j;
	int *arr;
	int overflow;

	if (!(arr = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = ft_atoi_overflow(input[i], &overflow);
		if (overflow == 1)
		{
			printf("Input lager than int");
			return (NULL);
		}
		j = 0;
		while (j < i)
		{
			if (arr[j] == arr[i])
			{
				printf("Multiple occurences of value");
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int
	sort_stack(t_param *param, int len, void (*ps_sort)(t_param *))
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

typedef void (*t_sort_func)(t_param *param);

void
	init_sort_func_arr(t_sort_func *sort_func)
{
	sort_func[0] = ps_bubble_sort;
	sort_func[1] = ps_bubble_sort_v2;
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
		printf("Before algo\n");
		if(!sort_stack(&param, ac - 1, sort_func[i]))
			ps_fatal(&param, "Sort_stack returned error");
		printf("Algo result (instructions): %d\n", param.instruct->max_i + 1);
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
	print_instruct(&min_instruct);
	free(min_instruct.arr);

	return (EXIT_SUCCESS);
}
 // While reading the instructions and writting them to stdout, if a swap_a is followed by a swap_b (or the other way around), write a swap_ab instead
 // Do same thing for rotate instructions