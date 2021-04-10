#include "push_swap.h"

void
	select_sort_b(t_stack *stack_a, t_stack *stack_b, t_dyn_iarr *instruct, int len)
{
    int arr[QS_OPTI];
	int i;
	int val1;
	int val2;

	i = 0;
	while (i < len)
	{
		arr[i] = stack_b->stack[stack_b->top + i];
		i++;
	}
	quick_sort(arr, len);
	i = len - 1;
    while (i > 0)
    {
        val1 = arr[i];
        val2 = arr[i - 1];
        if (i < 3)
        {
            if (i == 2)
            {
                ps_rotate_top(stack_b, instruct, stack_get_index(stack_b, val1));
                ps_push_a(stack_a, stack_b, instruct);
                i--;
            }
            val1 = arr[i];
            val2 = arr[i - 1];
            while (stack_len(stack_b) > 2 &&
            (stack_get_index(stack_b, val1) == stack_b->bottom - 1 || 
            stack_get_index(stack_b, val2) == stack_b->bottom - 1))
                ps_rotate_down(stack_b, instruct);
            if (stack_b->stack[stack_b->top] < stack_b->stack[stack_b->top + 1])
                ps_swap_top(stack_b, instruct);
            ps_push_a_n(stack_a, stack_b, instruct, 2);
            break;
        }
        else if (stack_is_closest(stack_b, val1, val2) == 1)
        {
            ps_rotate_top(stack_b, instruct, stack_get_index(stack_b, val1));
            ps_push_a(stack_a, stack_b, instruct);
            ps_rotate_top(stack_b, instruct, stack_get_index(stack_b, val2));
            ps_push_a(stack_a, stack_b, instruct);
        }
        else
        {
            ps_rotate_top(stack_b, instruct, stack_get_index(stack_b, val2));
            ps_push_a(stack_a, stack_b, instruct);
            ps_rotate_top(stack_b, instruct, stack_get_index(stack_b, val1));
            ps_push_a(stack_a, stack_b, instruct);
            ps_swap_top(stack_a, instruct);
        }
        i -= 2;
    }
}

void
    select_sort_a(t_stack *stack_a, t_stack *stack_b, t_dyn_iarr *instruct, int len)
{
    int arr[QS_OPTI];
	int i;
	int val1;
	int val2;

	i = 0;
	while (i < len)
	{
		arr[i] = stack_a->stack[stack_a->top + i];
		i++;
	}
	quick_sort(arr, len);
	i = 0;
    while (i < len - 1)
    {
        val1 = arr[i];
        val2 = arr[i + 1];
        if (i >= (len - 3))
        {   //printf("i: %d|len: %d\n", i, len);
            if (i == (len - 3))
            {
                ps_rotate_top(stack_a, instruct, stack_get_index(stack_a, val1));
                ps_push_b(stack_a, stack_b, instruct);
                i++;
            }
            val1 = arr[i];
            val2 = arr[i + 1];
            while (stack_len(stack_a) > 2 &&
            (stack_get_index(stack_a, val1) == stack_a->bottom - 1 || 
            stack_get_index(stack_a, val2) == stack_a->bottom - 1))
                ps_rotate_down(stack_a, instruct);
            if (stack_a->stack[stack_a->top] > stack_a->stack[stack_a->top + 1])
                ps_swap_top(stack_a, instruct);
            break;
        }
        else if (stack_is_closest(stack_a, val1, val2) == 1)
        {
            ps_rotate_top(stack_a, instruct, stack_get_index(stack_a, val1));
            ps_push_b(stack_a, stack_b, instruct);
            ps_rotate_top(stack_a, instruct, stack_get_index(stack_a, val2));
            ps_push_b(stack_a, stack_b, instruct);
        }
        else
        {
            ps_rotate_top(stack_a, instruct, stack_get_index(stack_a, val2));
            ps_push_b(stack_a, stack_b, instruct);
            ps_rotate_top(stack_a, instruct, stack_get_index(stack_a, val1));
            ps_push_b(stack_a, stack_b, instruct);
            ps_swap_top(stack_b, instruct);
        }
        i += 2;
    }
    while (stack_a->stack[stack_a->top] != arr[0])
        ps_push_a(stack_a, stack_b, instruct);
}

void
	magic_selec_sort_n(t_stack *stack_1, t_stack *stack_2, t_dyn_iarr *instruct, int len)
{
    if (stack_1->ref == STACK_A)
        select_sort_a(stack_1, stack_2, instruct, len);
    else
		select_sort_b(stack_2, stack_1, instruct, len);
}