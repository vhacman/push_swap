/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:50:34 by vhacman           #+#    #+#             */
/*   Updated: 2025/04/01 00:56:00 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ========================== LIBRARIES ========================== */
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
/* ======================== DATA STRUCTURES ======================== */
/**
 * struct s_stack_node
 * -------------------
 * Represents a single element (node) in a stack (implemented as a linked list).
 * Each node stores:
 * - value: the actual integer from input
 * - index: the position of the value in the sorted order (used for ranking)
 * - next: pointer to the next node in the stack
 */
typedef struct s_stack_node
{
	int						value;
	int						index;
	struct s_stack_node		*next;
}	t_stack_node;

/**
 * struct s_cost
 * -------------
 * Stores the cost of moving a specific node from stack_a to its target
 * position in stack_b (or vice versa) during sorting.
 * Includes:
 * - rotations_a / rotations_b: number of rotations required for each stack
 * - direction_a / direction_b: 1 (rotate) or -1 (reverse rotate)
 * - total_moves: sum of rotations needed to execute the move
 */
typedef struct s_cost
{
	int	rotations_a;
	int	rotations_b;
	int	direction_a;
	int	direction_b;
	int	total_moves;
}	t_cost;

/**
 * struct s_bounds
 * ---------------
 * Defines a range inside an array for sorting algorithms.
 * Used for merge sort or chunk limits.
 * - left: starting index
 * - mid: middle index (split point)
 * - right: ending index
 */
typedef struct s_bounds
{
	int	left;
	int	mid;
	int	right;
}	t_bounds;

/**
 * struct s_range_limits
 * ---------------------
 * Identical in purpose to s_bounds.
 * Some functions (like merge sort) use this structure for clarity.
 */
typedef struct s_range_limits
{
	int	left;
	int	mid;
	int	right;
}	t_range_limits;

/**
 * struct s_target_info
 * --------------------
 * Stores information about a candidate node to move from stack_a to stack_b.
 * Includes:
 * - node: pointer to the node in stack_a to be moved
 * - cost: associated cost (rotations, direction, total)
 */
typedef struct s_target_info
{
	t_stack_node	*node;
	t_cost			cost;
}	t_target_info;

/**
 * struct s_chunk_info
 * -------------------
 * Used during chunk-based sorting.
 * - limit: current chunk threshold (upper index limit for selection)
 * - size: size of each chunk
 */
typedef struct s_chunk_info
{
	int		limit;
	int		size;
}	t_chunk_info;

/* ===================== MAIN ENTRY POINT ===================== */

int		main(int ac, char **av);

/* ===================== INITIALIZATION & CLEANUP ===================== */

int		initialize_stack(int ac, char **av, t_stack_node **stack_a);
void	validate_input(char **av, int ac, t_stack_node **stack);
void	free_stack(t_stack_node *stack);
void	free_split(char **token);

/* ===================== SORTING ALGORITHMS ===================== */

void	perform_sorting(t_stack_node **stack_a, t_stack_node **stack_b,
			int size);
void	mini_sort_a(t_stack_node **a, t_stack_node **b);
void	ultra_chunk_sort(t_stack_node **a, t_stack_node **b, int total_size);
void	hybrid_sort(t_stack_node **a, t_stack_node **b);

/* ===================== INDEX ASSIGNMENT & ARRAY UTIL ===================== */

void	merge_sort(int *array, int size);
void	assign_indices(t_stack_node *stack, int *sorted_array, int size);
int		*convert_stack_to_array(t_stack_node *stack, int stack_size);

/* ===================== STACK CREATION & SIZE ===================== */

t_stack_node		*create_stack_node(int value);
void				create_stack(t_stack_node **stack, int value);
int					stack_size(t_stack_node *stack);

/* ===================== LINKED LIST STACK OPERATIONS ===================== */

void	swap_stack(t_stack_node *stack_head, int size);
void	push_stack(t_stack_node **from_stack, t_stack_node **to_stack);
void	rotate_stack(t_stack_node **stack_head);
void	reverse_rotate_stack(t_stack_node **stack_head);

/* ================== DOUBLE OPERATIONS (LINKED STACKS) ================ */
void	ss_stack(t_stack_node **src_stack, int src_size,
			t_stack_node **dest_stack, int dest_size);
void	rr_stack(t_stack_node **a, t_stack_node **b);
void	rrr_stack(t_stack_node **a, t_stack_node **b);
/* ===================== LOGICAL OPERATIONS FOR ARRAYS ===================== */
void	swap(int *array, int size);
void	push(int *src, int *src_size, int *dest, int *dest_size);
void	rotate(int *array, int size);
void	reverse_rotate(int *array, int size);
void	ss_array(int *s_a, int a_size, int *s_b, int b_size);
void	rr_array(int *s_a, int a_size, int *s_b, int b_size);
void	rrr_array(int *s_a, int a_size, int *s_b, int b_size);
/* ===================== COST CALCULATION UTILS ===================== */
void	calculate_move_cost(t_stack_node **stack_a,
			t_stack_node **stack_b, t_stack_node *node, t_cost *cost);
void	set_rotations(int pos, int size, int *direction, int *rotations);
int		distance_to_top(t_stack_node *stack, t_stack_node *target);
int		find_target_position_b(t_stack_node *stack_b, int index);
int		find_position_of_index(t_stack_node *stack, int index);
void	init_target_info(t_target_info *info);
/* ===================== CHUNK SORTING ===================== */
void	move_chunks(t_stack_node **a, t_stack_node **b, t_chunk_info chunk);
void	rebuild_stack_a(t_stack_node **a, t_stack_node **b);
void	smart_pb(t_stack_node **a, t_stack_node **b);
/* ===================== MOVE EXECUTION ===================== */
void	execute_combo_move(t_stack_node **a, t_stack_node **b, t_cost cost);
void	rotate_both(t_stack_node **a, t_stack_node **b, t_cost *cost);
void	rotate_individual(t_stack_node **a, t_stack_node **b, t_cost *cost);
void	final_rotate_a(t_stack_node **a);
/* ===================== ERROR HANDLING & HELPERS ===================== */
void	exit_error(void);
int		is_sorted(t_stack_node *stack);
int		is_number(char *str);
int		has_duplicates(t_stack_node *stack, int value);
/* ===================== BASIC COMMANDS FOR INSTRUCTION LIST ======= */
void	pb(t_stack_node **a, t_stack_node **b);
void	pa(t_stack_node **b, t_stack_node **a);
void	sb(t_stack_node *b);
void	sa(t_stack_node *a);
void	ra(t_stack_node **a);
void	rb(t_stack_node **b);
void	rra(t_stack_node **a);
void	rrb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);
void	rrr(t_stack_node **a, t_stack_node **b);
/* ===================== DEBUG (OPTIONAL) ===================== */
//	void	print_stack(t_stack_node *stack, char *label);
//	void	print_indices(t_stack_node *stack);
#endif