#include "push_swap.h"

t_stack_func
	*set_stack_func_arr(void)
{
	static t_stack_func arr[AVAIL_INSTRUCT] = {
	{"sa", swap_a},
	{"sb", swap_b},
	{"ss", swap_ab},
	{"pa", push_a},
	{"pb", push_b},
	{"ra", rotate_a},
	{"rb", rotate_b},
	{"rr", rotate_ab},
	{"rra", rrotate_a},
	{"rrb", rrotate_b},
	{"rrr", rrotate_ab}};

	return (arr);
}