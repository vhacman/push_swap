/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:50:34 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/28 18:26:41 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>

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

typedef struct	s_target_info
{
	t_stack_node	*node;
	t_cost			cost;
}	t_target_info;

int	main(int ac, char **av);
int	initialize_stack(int ac, char **av, t_stack_node **stack_a);
void	perform_sorting(t_stack_node **stack_a, t_stack_node **stack_b);
void	init_target_info(t_target_info *info);
int	distance_to_top(t_stack_node *stack, t_stack_node *target);
int	find_target_position_b(t_stack_node *stack_b, int index);
void	ss_array(int *s_a, int a_size, int *s_b, int b_size);
void	rr_array(int *s_a, int a_size, int *s_b, int b_size);
void	rrr_array(int *s_a, int a_size, int *s_b, int b_size);
void	swap(int *array, int size);
void	push(int *src, int *src_size, int *dest, int *dest_size);
void	rotate(int *array, int size);
void	reverse_rotate(int *array, int size);
void	update_if_better_target(t_stack_node **a, t_stack_node **b,
		int chunk_limit, t_target_info *target);
void	hybrid_sort(t_stack_node **a, t_stack_node **b);
void	merge_sort(int *array, int size);
int		find_position_of_index(t_stack_node *stack, int index);
void	handle_three_elements(t_stack_node **a);
void	rotate_to_position(t_stack_node **a, int min_index);
void	mini_sort_a(t_stack_node **a, t_stack_node **b);
void	ultra_chunk_sort(t_stack_node **a, t_stack_node **b, int total_size);
void	validate_input(char **av, int ac, t_stack_node **stack);
void	execute_combo_move(t_stack_node **a, t_stack_node **b, t_cost cost);
void	execute_optimal_move(t_stack_node **a, t_stack_node **b, t_cost cost);
void	final_rotate_a(t_stack_node **a);
int	is_stack_b_sorted(t_stack_node *b);
void	print_stack(t_stack_node *stack, char *label);
void	print_indices(t_stack_node *stack);
void	assign_indices(t_stack_node *stack, int *sorted_array, int size);
void	rebuild_stack_a(t_stack_node **a, t_stack_node **b);
void	smart_pb(t_stack_node **a, t_stack_node **b);
int	is_sorted_and_empty(t_stack_node *stack_a, t_stack_node *stack_b);
t_stack_node	*create_stack_node(int value);
void	create_stack(t_stack_node **stack, int value);
int	stack_size(t_stack_node *stack);
int	*convert_stack_to_array(t_stack_node *stack, int stack_size);
void	free_stack(t_stack_node *stack);


#endif