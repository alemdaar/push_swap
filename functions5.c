#include "header.h"

void store_index(t_extracter *result, t_stack *head)
{
	t_indexes	index;
	t_stack		*tmp;

	index.j = 0;
	tmp = head;
	while (tmp)
	{
		index.i = 0;
		while (index.i < result->count)
		{
			if (tmp->number == result->nb[index.i])
			{
				tmp->index = index.i + 1;
				break;
			}
			index.i++;
		}
		tmp = tmp->next;
	}
	return;
}

void fill_index (t_stack *head, t_extracter *result)
{
	t_indexes index;

	index.i = 0;
	while (index.i < result->count - 1)
	{
		index.j = index.i + 1;
		while (index.j < result->count)
		{
			if (result->nb[index.i] > result->nb[index.j])
			{
				swap_nbs_with_tmp (result->nb + index.i, result->nb + index.j);
				index.j = index.i + 1;
				continue ;
			}
			index.j ++;
		}
		index.i ++;
	}
	store_index(result, head);
	return ;
}

int extract_nbs (t_extracter *result)
{
	t_indexes index;
	result->nb = (long long *) malloc (sizeof(long long) * result->count);
	if (!result->nb)
		return -1;
	index.i = 0;
	index.r = 1;
	index.k = 0;
	while (index.i < result->count)
	{
		result->nb[index.k] = 0;
		index.j = 0;
		if (result->str[index.i][index.j] == '+' || result->str[index.i][index.j] == '-')
			if (result->str[index.i][index.j++] == '-')
				index.r *= -1;
		while (result->str[index.i][index.j])
			result->nb[index.k] = (result->nb[index.k] * 10) + (result->str[index.i][index.j++] - 48);
		result->nb[index.k] *= index.r;
		if (result->nb[index.k] > 2147483647 || result->nb[index.k] < -2147483648)
			return (free(result->nb), -1);
		index.i++;
		index.k++;
		index.r = 1;
	}
	return (1);
}

int prepare_str (char **str, int count)
{
	int i = 0;
	*str = (char *) malloc (sizeof(char) * (count + 1));
	if (!*str)
		return -1;
	while (i < count)
	{
		(*str)[i] = 0;
		i++;
	}
	(*str)[count] = '\0';
	return 1;
}

int raqm_meawd (t_extracter *result)
{
	t_indexes index;
	index.i = 0;
	while (index.i < result->count)
	{
		index.j = index.i + 1;
		while (index.j < result->count)
		{
			if (result->nb[index.i] == result->nb[index.j])
				return (free_longlong (&result->nb), -1);
			index.j++;
		}
		index.i++;
	}
	return 0;
}
