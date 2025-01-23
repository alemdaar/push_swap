#include "header.h"

t_indexes fill_str2(t_indexes index, t_extracter *result, char **av)
{
	while (its_digit(av[index.i][index.j]) || its_zaidnaqs(av[index.i][index.j]))
	{
		if (index.r == 0)
		{
			if (prepare_str (&result->str[index.k], 12) == -1)
			{
				while (index.f < index.k)
					free_str (&result->str[index.f++]);
				return (index.i = -1, index); // -1 -> -1;
			}
			index.r = 1;
		}
		if (av[index.i][index.j] == '-' || av[index.i][index.j] == '+')
			result->str[index.k][index.c++] = av[index.i][index.j++];
		if (index.c >= 11)
		{
			while (index.f <= index.k)
				free_str (&result->str[index.f++]);
			return (index.i = -1, index); // 1 r-> -2
		}
		result->str[index.k][index.c++] = av[index.i][index.j++];
		result->str[index.k][index.c] = '\0';
	}
	return (index);
}

t_indexes fill_str_loop (t_indexes index, char **av)
{
	while (its_space(av[index.i][index.j]))
	{
		index.r = 0;
		index.j += 1;
	}
	return (index);
}
int fill_str(t_extracter *result, int ac, char **av)
{
	t_indexes index;

	result->overflow = 0;
	index.i = 1;
	index.r = 0;
	index.k = 0;
	index.f = 0;
	while (index.i < ac)
	{
		index.j = 0;
		while (av[index.i][index.j])
		{
			index.c = 0;
			index = fill_str_loop(index, av);
			index = fill_str2 (index, result, av);
			if (index.i == -1)
				return (-1);
			index.k++;
			index.r = 0;
			if (!av[index.i][index.j])
				break;
		}
		index.i += 1;
	}
	return 1;
}

void shift_down (char type, t_stack **head, int len, int times)
{
	t_indexes index;
	t_stack *tmp;
	t_stack *previous;

	if (len < 2)
		return ;
	index.i = 0;
	while (index.i < times)
	{
		tmp = *head;
		while (tmp->next)
		{
			previous = tmp;
			tmp = tmp->next;
		}
		previous->next = NULL;
		tmp->next = *head;
		*head = tmp;
		if (type == 'a')
			write (1, "rra\n", 4);
		else if (type == 'b')
			write (1, "rrb\n", 4);
		index.i++;
	}
	return ;
}

t_stack *make_stack_a(t_extracter *result)
{
	t_indexes index;
	t_stack *node;
	t_stack *head;

	head = NULL;
	index.i = 0;
	while (index.i < result->count)
	{
		node = ft_lstnew (result->nb[index.i]);
		if (!node)
		{
			while (head)
			{
				free_node(&head);
				head = head->next;
			}
			return (free_longlong (&result->nb), NULL);
		}
		ft_lstadd_back (&head, node);
		index.i++;
	}
  	return (fill_index(head, result), free_longlong (&result->nb), head);
}
