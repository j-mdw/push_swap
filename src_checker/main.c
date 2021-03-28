#include "push_swap.h"

// int
// 	is_sort(int *arr, int len);

typedef struct	s_check_param {
	int *arr_a;
	int *arr_b;
	int len_a;
}				t_check_param;

void
	fatal(t_check_param *param, char *error_msg)
{
	free(param->arr_a);
	free(param->arr_b);
	dprintf(STDERR_FILENO, "Error: %s\n", error_msg);
	exit(EXIT_FAILURE);
}

int
	input_isintarr(int len, char **arr)
{
	int i;

	i = 0;
	while (i < len)
	{
		// printf("%s\n", arr[i]);
		if (!ft_isnumber(arr[i]))
			return (i);
		i++;
	}
	return (-1);
}

void
	init_param(t_check_param *param, char **input, int len)
{
	int i;
	int overflow;

	param->len_a = len;
	param->arr_b = NULL;
	if (!(param->arr_a = (int *)malloc(sizeof(int) * len)))
		fatal(param, "Malloc error");
	if (!(param->arr_b = (int *)malloc(sizeof(int) * len)))
		fatal(param, "Malloc error");
	i = 0;
	while (i < len)
	{
		param->arr_a[i] = ft_atoi_overflow(input[i], &overflow);
		if (overflow == 1)
			fatal(param, "Input larger than INT");
		i++;
	}
	ft_putintarr(param->arr_a, len);
}

int
	main(int ac, char **av)
{
	t_check_param	param;
	int				ret;

	av++;
	if (ac <= 1)
		dprintf(STDERR_FILENO, "Error - No input\n");
	else if ((ret = input_isintarr(ac - 1, av)) != -1)
		dprintf(STDERR_FILENO, "Error: Input '%s': not a number\n", av[ret]);
	else
	{
		init_param(&param, av, ac - 1);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
