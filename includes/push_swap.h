/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:50:34 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/26 20:50:34 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack_node
{
	int						value;
	int						index;
	struct s_stack_node		*next;
}	t_stack_node;

typedef struct s_cost
{
	int	rotations_a;
	int	rotations_b;
	int	direction_a;
	int	direction_b;
	int	total_moves;
}	t_cost;

typedef struct s_bounds
{
	int	left;
	int	mid;
	int	right;
}	t_bounds;

typedef struct s_range_limits
{
	int	left;
	int	mid;
	int	right;
}	t_range_limits;

//STACK_UTILS --> stack_utils.c f
void			free_stack(t_stack_node *stack);
int				*convert_stack_to_array(t_stack_node *stack, int stack_size);
int				stack_size(t_stack_node *stack);
void			*create_stack(t_stack_node **stack, int value);
t_stack_node	*create_stack_node(int value);
int				is_sorted_and_empty(t_stack_node *stack_a, t_stack_node *stack_b);

//ERROR_HANDLING.C
void			exit_error(void);
void			validate_input(char **av, int ac, t_stack_node **stack);

//STACK_OPERATIONS.C e STACK_DOUBLE_OPERATIONS.C
void			swap_stack(t_stack_node *stack_head, int size);
void			push_stack(t_stack_node **from_stack, t_stack_node **to_stack);
void			rotate_stack(t_stack_node **stack_head);
void			reverse_rotate_stack(t_stack_node **stack_head);
void			ss_stack(t_stack_node *src_stack, int src_size,
					t_stack_node *dest_stack, int dest_size);
void			rr_stack(t_stack_node **src_stack, t_stack_node **dest_stack);
void			rrr_stack(t_stack_node **src_stack, t_stack_node **dest_stack);

// COST_UTILS.C
int				distance_to_top(t_stack_node **stack, t_stack_node **target);
int				find_target_position_b(t_stack_node **stack_b, int index);

//HYBRID_SORT_ALGORITHM.c
void			hybrid_sort(t_stack_node **a, t_stack_node **b);

//MERGE_ALGORITHM.C
void			merge_sort(int *array, int size);

//OPERATIONS --> OPERATIONS.C E DOUBLE_OPERATIONS.C - SU ARRAY PER LAVORARE
//SULL'ALGORITMO
void			swap(int *array, int size);
void			push(int *src, int *src_size, int *dest, int *dest_size);
void			rotate(int *array, int size);
void			reverse_rotate(int *array, int size);
void			ss(int *s_a, int a_size, int *s_b, int b_size);
void			rr(int *s_a, int a_size, int *s_b, int b_size);
void			rrr(int *s_a, int a_size, int *s_b, int b_size);
#endif