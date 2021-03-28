#include "push_swap.h"

int
	input_isintarr(int len, char **arr)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (!ft_isnumber(arr[i]))
			return (i);
		i++;
	}
	return (-1);
}