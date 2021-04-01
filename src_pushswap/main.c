#include "push_swap.h"

void
	ps_init_param(t_param *param, t_dyn_iarr *instruct, t_stack *stack_a, t_stack *stack_b)
{
	param->instruct = instruct;
	param->stack_a = stack_a;
	param->stack_b = stack_b;
}

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
	// ft_putintarr(arr, size);
	return (arr);
}

int
	sort_stack(int *arr, int len, t_dyn_iarr *instructions, void (*ps_sort)(t_param *))
{
	t_param		param;
	t_stack		stack_a;
	t_stack		stack_b;

	if (!arr)
		return (0);
	stack_init(&stack_a, len, STACK_A);
	free(stack_a.stack);
	stack_a.stack = arr;
	stack_a.top = 0;
	stack_init(&stack_b, len, STACK_B);
	ps_init_param(&param, instructions, &stack_a, &stack_b);
	if (!dyn_iarray_init(instructions, len * 2)) //ac * 2 TBU eventually
	{
		free(stack_a.stack);
		free(stack_b.stack);
		return (0);
	}
	ps_sort(&param);
	free(stack_a.stack);
	free(stack_b.stack);
	return (instructions->max_i + 1);
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
	t_dyn_iarr	instructions;
	t_sort_func	sort_func[SORT_FUNC_COUNT];
	// t_stack		stack_a;
	// t_stack		stack_b;
	int			*arr;
	int			*arr2;
	int			i;
	int			min;

	ps_init_param_v2(&param);
	av++;
	if (!(param.input = parse_iarr_input(av, ac - 1)))
		ps_fatal(&param, "");
	init_sort_func_arr(sort_func);
	i = 0;
	while (i < SORT_FUNC_COUNT)
	{
		if(!sort_stack(ft_intarr_dup(arr, ac - 1), ac - 1, &instructions, sort_func[i]))
			ps_fatal()

	}


	if(!sort_stack(ft_intarr_dup(arr, ac - 1), ac - 1, &instructions, ps_bubble_sort))
		return (EXIT_FAILURE);
	printf("Instructions: Algo1: %d\n", instructions.max_i + 1);
	if(!sort_stack(ft_intarr_dup(arr, ac - 1), ac - 1, &instructions, ps_bubble_sort_v2))
		return (EXIT_FAILURE);
	printf("Instructions: Algo2: %d\n", instructions.max_i + 1);
	// stack_ab_init(&stack_a, &stack_b, ++av, ac - 1);
	// ps_init_param(&param, &instructions, &stack_a, &stack_b);
	// if (!dyn_iarray_init(&instructions, ac * 2)) //ac * 2 TBU eventually
	// 	ps_fatal(&param, "Malloc");
	// ps_bubble_sort(&param);
	// printf("Instructions: %d\n", instructions.max_i + 1);
	// ft_putintarr(instructions.arr, instructions.max_i + 1);

	print_instruct(&instructions);
	free(instructions.arr);
	// free(stack_a.stack);
	// free(stack_b.stack);

	return (EXIT_SUCCESS);
}
 // While reading the instructions and writting them to stdout, if a swap_a is followed by a swap_b (or the other way around), write a swap_ab instead
 // Do same thing for rotate instructions