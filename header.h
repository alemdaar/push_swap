/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:05:44 by oelhasso          #+#    #+#             */
/*   Updated: 2025/01/24 20:29:20 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct stack_st {
	int				number;
	int				index;
	int				top;
	int				total;
	char			direction;
	struct stack_st	*target;
	struct stack_st	*next;
}	t_stack;

typedef struct extracter_st {
	long long	*nb;
	int			count;
	char		**str;
	int			overflow;
}	t_extracter;

typedef struct indexes_st {
	int			i;
	int			j;
	int			k;
	int			r;
	int			f;
	long long	c;
}	t_indexes;


int bigger_total (t_stack *head);
// void print_stack (t_stack *a, t_stack *b);


// f1
void free_str(char **adata);
void free_str2(char ***adata);
void free_longlong(long long **adata);
void free_result(t_extracter **adata);
void free_node(t_stack **adata);
// f2
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void swap_nbs_with_tmp (long long *a, long long *b);
int stack_size(t_stack *head);
// f3
void shift_up_2(t_stack **a, t_stack **b, int a_size, int b_size, int times);
void shift_down_2(t_stack **a, t_stack **b, int a_size, int b_size, int times);
void shift_same_direction (t_stack **a, t_stack **b, t_stack *shortest, int a_size, int b_size);
void shift_with_m (t_stack **a, t_stack **b, t_stack *shortest, int a_size, int b_size);
void shift_not_same_direction (t_stack **a, t_stack **b, t_stack *shortest, int a_size, int b_size);
// f4
int its_space (char c);
int its_digit (char c);
int its_zaidnaqs (char c);
t_indexes calculate_nbs2 (t_indexes index, char **av);
int calculate_nbs(int ac, char **av);
// f5
void store_index(t_extracter *result, t_stack *head);
void fill_index (t_stack *head, t_extracter *result);
int extract_nbs (t_extracter *result);
int prepare_str (char **str, int count);
int raqm_meawd (t_extracter *result);
// f6
t_extracter *correct_nb(char **av, int ac);
int a_ready(int *a, int len);
void push (char type, t_stack **a, t_stack **b);
void swap (char type, t_stack **a, t_stack **b);
void  shift_up(char type, t_stack **a, int len, int times);
// f7
void comeback_to_a (t_stack **a, t_stack **b, int b_size);
t_stack *a_location(t_stack *a);
void topping_a(t_stack **a, int elements_size);
int algorithm(t_stack **a, t_stack **b, int elements_size);
void push_swap (t_stack **a, int elements_size);
// f8
void move_it (t_stack **a, t_stack **b, t_stack *shortest, int a_size, int b_size);
t_stack *aqrab_treq(t_stack *head);
t_stack *magic_trick (t_stack *head);
t_stack *shortest_move (t_stack *head);
void sort_sghera (t_stack **a, int elements_size);
// f9
t_indexes fill_str2(t_indexes index, t_extracter *result, char **av);
t_indexes fill_str_loop (t_indexes index, char **av);
int fill_str(t_extracter *result, int ac, char **av);
void shift_down (char type, t_stack **head, int len, int times);
t_stack *make_stack_a(t_extracter *result);
// f10
int is_sorted(t_stack **a);
int push_to_b (t_stack **a, t_stack **b, int elements_size);
void sort_3_elements (t_stack **head);
void create_tops2 (t_stack *tmp, t_indexes index, int size);
void create_tops (t_stack *head, int size);
// f11
void the_smallest(t_stack **current, t_stack *a);
int nothing_bigger (int number, t_stack *a);
void make_target(t_stack *a, t_stack **b);
void update_totals(t_stack *head);
int smaller_top (t_stack *shortest); 
// f12
void find_target_in_b (t_stack **current_b, t_stack *a);

#endif