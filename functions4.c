#include "header.h"

int its_space (char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int its_digit (char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int its_zaidnaqs (char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

t_indexes calculate_nbs2 (t_indexes index, char **av)
{
	while (its_space(av[index.i][index.j]))
	{
		index.r = 0;
		index.j += 1;
	}
	if (its_zaidnaqs(av[index.i][index.j]))
	{
		index.j++;
		if (its_digit(av[index.i][index.j]) == 0)
			return (index.c = -1, index);
	}
	while (its_digit(av[index.i][index.j]))
	{
		if (index.r == 0)
		{
			index.c ++;
			index.r = 1;
		}
		index.j += 1;
	}
	if (index.c > 0)
		index.r = 0;
	return (index);
}

int calculate_nbs(int ac, char **av)
{
	t_indexes index;

	index.i = 1;
	index.c = 0;
	index.r = 0;
	while (index.i < ac)
	{
		index.j = 0;
		if (!av[index.i][index.j])
			return (-3);
		while (av[index.i][index.j])
		{
			index = calculate_nbs2(index, av);
			if (index.c == -1)
				return (-1);
			if (!av[index.i][index.j])
				break;
			if (its_digit(av[index.i][index.j]) == 0 && its_space (av[index.i][index.j]) == 0)
				return -1;
		}
		index.i += 1;
	}
	return (index.c);
}