#include "header.h"
#include <stdio.h>

// void print_stack (t_stack *a, t_stack *b)
// {
// 	t_stack *aa;
// 	t_stack *bb;

// 	aa = a;
// 	bb = b;
// 	printf ("\n\n");
// 	while (aa || bb)
// 	{
// 		if (aa)
// 			printf ("%d", aa->number);
// 		printf ("             ");
// 		if (bb)
// 			printf ("%d", bb->number);
// 		printf ("\n");
// 		if (aa)
// 			aa = aa->next;
// 		if (bb)
// 			bb = bb->next;
// 	}
// 	printf ("-------\n");
// 	printf ("a       b\n\n\n");
// }

void free_str(char **adata)
{
	if (adata && *adata)
	{
		free(*adata);
		*adata = NULL;
	}
	return ;
}

void free_str2(char ***adata)
{
	if (adata && *adata)
	{
		free(*adata);
		*adata = NULL;
	}
	return ;
}

void free_longlong(long long **adata)
{
	if (adata && *adata)
	{
		free(*adata);
		*adata = NULL;
	}
	return ;
}

void free_result(t_extracter **adata)
{
	if (adata && *adata)
	{
		free(*adata);
		*adata = NULL;
	}
	return ;
}

void free_node(t_stack **adata)
{
	if (adata && *adata)
	{
		free(*adata);
		*adata = NULL;
	}
	return ;
}
