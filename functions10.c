#include "header.h"

int is_sorted(t_stack **a)
{
	t_stack *tmp1;
	t_stack *tmp2;
	tmp1 = *a;
	while (tmp1->next)
	{
		tmp2 = tmp1->next;
		if (tmp1->number > tmp2->number)
			return 0;
		tmp1 = tmp1->next;
	}
	return 1;
}

int push_to_b (t_stack **a, t_stack **b, int elements_size)
{
	t_stack *tmp;
	t_indexes index;

	index.c = elements_size / 2;
	while (a && elements_size > 3)
	{
		tmp = *a;
		push('b', a, b);
		if (tmp->index < index.c && stack_size(*b) > 1)
			shift_up ('b', b, elements_size, 1);
		elements_size--;
	}
	elements_size = stack_size(*b);
	return (elements_size);
}

void sort_3_elements (t_stack **head)
{
	t_indexes index;
	t_stack *tmp;

	tmp = *head;
	index.i = tmp->number;
	tmp = tmp->next;
	index.j = tmp->number;
	tmp = tmp->next;
	index.k = tmp->number;
	if (index.i > index.j) // 1 > 2
	{
		if (index.i > index.k) // 1 > 3
		{
			shift_up ('a', head, 3, 1);
			if (index.j > index.k) // 2 > 3
				swap('a', head, NULL);
		}
		else
			swap('a', head, NULL);
		return ;
	}
	shift_down ('a', head, 3, 1);
	if (index.i < index.k) // 1 < 3
		swap('a', head, NULL);
	return ;
}

void create_tops2 (t_stack *tmp, t_indexes index, int size)
{
	while (index.i <= (size - 1) / 2)
	{
		tmp->top = index.i;
		tmp->direction = 'u';
		index.i++;
		tmp = tmp->next;
	}
	tmp->top = index.i;
	tmp->direction = 'm';
	if (size % 2 != 0) {
		tmp->direction = 'd';
		tmp->top--;
	}
	index.c = tmp->top - 1;
	tmp = tmp->next;
	while (tmp || index.c)
	{
		tmp->top = index.c;
		tmp->direction = 'd';
		tmp = tmp->next;
		index.c--;
	}
	return ;
}
void create_tops (t_stack *head, int size)
{
	t_indexes index;

	index.i = 0;
	head->top = index.i;
	head->direction = 't';
	head = head->next;
	index.i++;
	if (size > 1)
		create_tops2 (head, index, size);	
	return ;
}
