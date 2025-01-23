#include "header.h"

void shift_up_2(t_stack **a, t_stack **b, int a_size, int b_size, int times)
{
	int i;

	i = 0;
	while (i < times)
	{
		shift_up ('c', a, a_size, 1);
		shift_up ('c', b, b_size, 1);
		write (1, "rr\n", 3);
		i++;
	}
}

void shift_down_2(t_stack **a, t_stack **b, int a_size, int b_size, int times)
{
	int i;

	i = 0;
	while (i < times)
	{
		shift_down ('c', a, a_size, 1);
		shift_down ('c', b, b_size, 1);
		write (1, "rrr\n", 3);
		i++;
	}
}

void shift_same_direction (t_stack **a, t_stack **b, t_stack *shortest, int a_size, int b_size)
{
	t_indexes index;

	index.c = smaller_top (shortest);
	index.i = shortest->total - index.i;
	if (shortest->direction == 'u' || shortest->direction == 'm')
	{
		shift_up_2(a, b, a_size, b_size, index.c);
		if (shortest->top != shortest->top)
		{
			if (shortest->top > shortest->top)
				shift_up ('b', b, b_size, shortest->total - shortest->top);
			else
				shift_up ('a', a, a_size, shortest->total - shortest->top);
		}
		return ;
	}
	shift_down_2(a, b, a_size, b_size, index.c);
	if (shortest->top != shortest->top)
	{
		if (shortest->top > shortest->top)
			shift_down ('b', b, b_size, shortest->total - shortest->top);
		else
			shift_down ('a', a, a_size, shortest->total - shortest->top);
	}
}

void shift_with_m (t_stack **a, t_stack **b, t_stack *shortest, int a_size, int b_size)
{
	t_indexes index;

	index.c = smaller_top (shortest);
	index.i = shortest->total - index.i;
	if (shortest->direction == 'u' || shortest->direction == 'u')
	{
		shift_up_2(a, b, a_size, b_size, index.c);
		if (shortest->top != shortest->top)
		{
			if (shortest->top > shortest->top)
				shift_up ('b', b, b_size, index.c);
			else
				shift_up ('a', a, a_size, index.c);
		}
		return ;
	}
	shift_down_2(a, b, a_size, b_size, index.c);
	if (shortest->top != shortest->top)
	{
		if (shortest->top > shortest->top)
			shift_down ('b', b, b_size, index.c);
		else
			shift_down ('a', a, a_size, index.c);
	}
}

void shift_not_same_direction (t_stack **a, t_stack **b, t_stack *shortest, int a_size, int b_size)
{
	t_stack *tmp;

	tmp = shortest;
	if (shortest->direction == 'u')
		shift_up ('b', b, b_size, shortest->top);
	else if (shortest->direction == 'd')
		shift_down ('b', b, b_size, shortest->top);
	if (tmp->direction == 'u')
		shift_up ('a', a, a_size, tmp->top);
	else if (tmp->direction == 'd')
		shift_down ('a', a, a_size, tmp->top);
	return ;
}
