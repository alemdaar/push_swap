#include "header.h"

void the_smallest(t_stack **current, t_stack *a)
{
	t_stack *tmp;
	t_stack *store;

	tmp = a;
	store = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		if (store->number > tmp->number)
			store = tmp;
		tmp = tmp->next;
	}
	(*current)->target = store;
}

int nothing_bigger (int number, t_stack *a)
{
	t_stack *tmp;

	tmp = a;
	while (tmp)
	{
		if (number < tmp->number)
			return 1;
		tmp = tmp->next;
	}
	return -1;
}

void make_target(t_stack *a, t_stack **b)
{
	t_stack *tmp_b;

	tmp_b = *b;
	while (tmp_b)
	{
		find_target_in_b (&tmp_b, a);
		tmp_b = tmp_b->next;
	}
	return ;
}
void update_totals(t_stack *head)
{
	t_stack *tmp;
	t_stack *target;

	tmp = head;
	while (tmp)
	{
		target = tmp->target;
		if (tmp->direction != 't' && target->direction != 't')
		{
			if ((tmp->direction == 'u' && target->direction == 'd') || (tmp->direction == 'd' && target->direction == 'u'))
				return ;
			if (tmp->direction != 'd' && target->direction != 'd')
				tmp->total = bigger_total (tmp);
			else if (tmp->direction != 'u' && target->direction != 'u')
				tmp->total = bigger_total (tmp);
		}
		tmp = tmp->next;
	}
}

int smaller_top (t_stack *shortest)
{
	t_stack *tmp;

	tmp = shortest->target;
	if (shortest->top >= tmp->top)
		return (tmp->top);
	return (shortest->top);
}

int bigger_total (t_stack *head)
{
	t_stack *tmp;

	tmp = head->target;
	if (tmp->top >= head->top)
		return (tmp->top);
	return (head->top);
}