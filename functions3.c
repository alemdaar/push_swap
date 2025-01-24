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
		write (1, "rrr\n", 4);
		i++;
	}
}

void shift_same_direction (t_stack **a, t_stack **b, t_stack *shortest, int a_size, int b_size)
{
	t_indexes index;

	index.c = smaller_top (shortest);
	index.i = bigger_total(shortest) - index.c;
	// printf ("same direction !");
	if (shortest->direction == 'u' || shortest->direction == 'm')
	{
		shift_up_2(a, b, a_size, b_size, index.c);
		if (index.i)
		{
			if (shortest->top != index.c) // means asghar wahid mashi b, so shift a
				shift_up ('b', b, b_size, index.i);
			else
				shift_up ('a', a, a_size, index.i);
		}
		return ;
	}
	shift_down_2(a, b, a_size, b_size, index.c);
	if (index.i)
	{
		if (shortest->top != index.c)
			shift_down ('b', b, b_size, index.i);
		else
			shift_down ('a', a, a_size, index.i);
	}
}

void shift_with_m (t_stack **a, t_stack **b, t_stack *shortest, int a_size, int b_size)
{
	t_indexes index;
	t_stack *tmp;

	tmp = shortest->target;
	// printf ("with m !");
	index.c = smaller_top (shortest);
	index.i = bigger_total(shortest) - index.c;
	if (shortest->direction == 'u' || tmp->direction == 'u')
	{
		shift_up_2(a, b, a_size, b_size, index.c);
		if (index.i)
		{
			if (shortest->top != index.c)
				shift_up ('b', b, b_size, index.i);
			else
				shift_up ('a', a, a_size, index.i);
		}
		return ;
	}
	shift_down_2(a, b, a_size, b_size, index.c);
	if (index.i)
	{
		if (shortest->top != index.c)
			shift_down ('b', b, b_size, index.i);
		else
			shift_down ('a', a, a_size, index.i);
	}
}

void shift_not_same_direction (t_stack **a, t_stack **b, t_stack *shortest, int a_size, int b_size)
{
	t_stack *tmp;

	tmp = shortest->target;
	// printf ("not same !");
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
