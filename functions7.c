#include "header.h"

void comeback_to_a (t_stack **a, t_stack **b, int b_size)
{
	t_indexes index;
	t_stack *shortest;
	t_stack *tmp;
	// char var[1];

	index.i = 3;
	while (b_size)
	{
		// print_stack (*a, *b);
		// scanf("%s", var);
		// printf ("heere i : %s\n", var);
		create_tops (*a, index.i);
		create_tops (*b, b_size);
		make_target(*a, b);
		shortest = shortest_move (*b);
		tmp = shortest->target;
		// printf ("a : %d\n", tmp->number);
		// printf ("b : %d\n", shortest->number);
		// printf ("a direction : %c\n", tmp->direction);
		// printf ("b direction : %c\n", shortest->direction);
		if (shortest->direction == 't' && tmp->direction == 't')
		{
			// printf ("bjuj f top !");
			push ('a', a, b);
			b_size--;
			index.i++;
			continue ;
		}
		move_it (a, b, shortest, index.i, b_size);
		index.i++;
		b_size--;
	}
}

t_stack *a_location(t_stack *a)
{
	t_stack *tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->index == 1)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

void topping_a(t_stack **a, int elements_size)
{
	t_stack *aa;

	create_tops (*a, elements_size);
	aa = a_location(*a);
	if (aa->direction == 'u' || aa->direction == 'm')
		shift_up ('a', a, elements_size, aa->top);
	else
		shift_down ('a', a, elements_size, aa->top);
	return ;
}

int algorithm(t_stack **a, t_stack **b, int elements_size)
{
	push_to_b (a, b, elements_size);
	if (!is_sorted(a))
		sort_3_elements (a);
	comeback_to_a (a, b, elements_size - 3);
	if ((*a)->index != 1)
		topping_a(a, elements_size);
	return 0;
}


void push_swap (t_stack **a, int elements_size)
{
	t_stack *b;

	b = NULL;
	if (!is_sorted(a))
	{
		algorithm(a, &b, elements_size);
		// print_stack (*a, b);
		while ((*a))
		{
			free (*a);
			(*a) = (*a)->next;
		}
	}
	return ;
}