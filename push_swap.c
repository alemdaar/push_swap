#include "header.h"

void lll()
{
	system("leaks -q push_swap");
}

int main (int ac, char **av) {
	t_stack *a;
	t_extracter *result;

	// atexit(lll);
	if (ac == 1)
 		return 0;
 	result = correct_nb(av, ac);
	if (result == NULL)
		return (write (2, "Error\n", 6), 1);
	if (raqm_meawd (result) == -1)
		return (write (2, "Error\n", 6), free_result (&result), 1);
	a = make_stack_a(result);
	// print_stack (a, NULL);
	if (!a)
		return (write (2, "Error\n", 6), free_result(&result), 1);
	if (result->count == 1)
		return (free_result(&result), 0);
	else if (result->count < 4) {
		sort_sghera(&a, result->count);
		return (free(a), free_result(&result), 0);
	}
	push_swap(&a, result->count);
	free_result(&result);
	return(0);
}
