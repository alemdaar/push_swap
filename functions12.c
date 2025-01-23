#include "header.h"

void find_target_in_b (t_stack **current_b, t_stack *a)
{
	t_stack *store;

	if (nothing_bigger ((*current_b)->number, a) == -1)
	{
		the_smallest(current_b, a);
		return ;
	}
	while (a)
	{
		if (a->number > (*current_b)->number)
		{
			store = a;
			break ;
		}
		a = a->next;
	}
	a = a->next;
	while (a)
	{
		if (store->number > a->number && a->number > (*current_b)->number)
			store = a;
		a = a->next;
	}
	(*current_b)->target = store;
}