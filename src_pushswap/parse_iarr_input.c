#include "push_swap.h"

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
			return (NULL);
		j = 0;
		while (j < i)
		{
			if (arr[j] == arr[i])
				return (NULL);
			j++;
		}
		i++;
	}
	return (arr);
}