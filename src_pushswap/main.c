#include "push_swap.h"


int
	main(int ac, char **av)
{
	printf("%s\n", av[ac - 1]);
	return (0);
}
 // While reading the instructions and writting them to stdout, if a swap_a is followed by a swap_b (or the other way around), write a swap_ab instead
 // Do same thing for rotate instructions