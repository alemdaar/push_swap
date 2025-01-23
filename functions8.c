#include "header.h"

void move_it (t_stack **a, t_stack **b, t_stack *shortest, int a_size, int b_size)
{
	t_stack *aa;

	aa = shortest->target;
	if (shortest->direction == 't')
	{
		if (aa->direction == 'u' || aa->direction == 'm')
			shift_up('a', a, a_size, aa->top);
		else
			shift_down('a', a, a_size, aa->top);
	}
	else if (aa->direction == 't')
	{
		if (shortest->direction == 'u' || shortest->direction == 'm')
			shift_up('b', b, b_size, shortest->top);
		else
			shift_down('b', b, b_size, shortest->top);
	}
	if (shortest->direction == aa->direction)
		shift_same_direction (a, b, shortest, a_size, b_size);
	else if (shortest->direction == 'm' || aa->direction == 'm')
		shift_with_m (a, b, shortest, a_size, b_size);
	else
		shift_not_same_direction (a, b, shortest, a_size, b_size);
	push ('a', a, b);
}

t_stack *aqrab_treq(t_stack *head)
{
	t_stack *tmp;
	t_stack *store;

	tmp = head;
	store = tmp;
	tmp = tmp->next;
	if (store->total != 0)
	{
		while (tmp)
		{
			if (store->total > tmp->total)
				store = tmp;
			tmp = tmp->next;
		}
	}
	return (store);

}

t_stack *magic_trick (t_stack *head)
{
	t_stack *aqrab_wahda;
	update_totals(head);
	aqrab_wahda  = aqrab_treq(head);
	return (aqrab_wahda);
}

t_stack *shortest_move (t_stack *head)
{
	t_stack *tmp_b;
	t_stack *tmp_target;
	t_stack *aqrab_wahda;

	tmp_b = head;
	while (tmp_b)
	{
		tmp_target = tmp_b->target;
		tmp_b->total = tmp_target->top + tmp_b->top ;
		tmp_b = tmp_b->next;
	}
	aqrab_wahda = magic_trick (head);
	return (aqrab_wahda);
}

void sort_sghera (t_stack **a, int elements_size)
{
	if (is_sorted(a) == 0)
	{
		if (elements_size == 2)
		{
			swap ('a', a , NULL);
			// print_stack (*a, NULL);
			return ;
		}
		sort_3_elements(a);
		// print_stack (*a, NULL);
	}
}
