#include "header.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->number = content;
	node->next = NULL;
	return (node);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last_node;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}

void swap_nbs_with_tmp (long long *a, long long *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int stack_size(t_stack *head)
{
	t_indexes index;
	t_stack *tmp;

	tmp = head;
	index.i = 0;
	while (tmp)
	{
		index.i++;
		tmp = tmp->next;
	}
	return (index.i);
}

