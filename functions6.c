#include "header.h"

t_extracter *correct_nb(char **av, int ac)
{
	t_extracter	*result;
	t_indexes	index;

	result = (t_extracter *) malloc (sizeof(t_extracter));
    if (!result)
        return (NULL);
	result->count = calculate_nbs(ac, av);
	if (result->count < 1)
		return (free_result(&result), NULL);
	result->str = (char **) malloc (result->count * (sizeof(char*)));
	if (!result->str)
		return (free_result (&result), NULL);
	index.r = fill_str(result, ac, av);
	if (index.r == -1)
		return (free_str2 (&result->str), free_result (&result), NULL);
	index.r = extract_nbs (result);
	index.i = 0;
	while (index.i < result->count)
		free_str (&result->str[index.i++]);
	free_str2 (&result->str);
	if (index.r == -1)
		return (free_result (&result), NULL);
	return (result);
}

int a_ready(int *a, int len)
{
	int i = 0;
	while (len - 1)
	{
		if (a[i] >= a[i + 1])
			return 0;
		i++;
	}
	return 1;
}

void push (char type, t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (type == 'a')
	{
		tmp = *b;
		(*b) = (*b)->next;
		tmp->next = (*a);
		(*a) = tmp;
		write (1, "pa\n", 3);
		return ;
	}
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = *b;
	(*b) = tmp;
	write (1, "pb\n", 3);
	return ;
}

void swap (char type, t_stack **a, t_stack **b)
{
	if (type == 'a')
	{
		t_stack *tmp;
		t_stack *tmp_a;
		tmp_a = *a;
		tmp = (*a)->next;
		tmp_a->next = tmp->next;
		tmp->next = tmp_a;
		*a = tmp;
		write (1, "sa\n", 3);
		return ;
	}
	t_stack *tmp;
	t_stack *tmp_b;
	tmp_b = *b;
	tmp = (*b)->next;
	tmp_b->next = tmp->next;
	tmp->next = tmp_b;
	*b = tmp_b;
	write (1, "sb\n", 3);
	return ;
}

void  shift_up(char type, t_stack **a, int len, int times)
{
	t_indexes index;
	t_stack *tmp;
	t_stack *first;
	if (len < 2)
		return ;
	index.i = 0;
	while (index.i < times)
	{
		first = *a;
		*a = (*a)->next;
		tmp = *a;
		first->next = NULL;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = first;
		if (type == 'a')
			write (1, "ra\n", 3);
		else if (type == 'b')
			write (1, "rb\n", 3);
		index.i++;
	}
}