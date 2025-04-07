/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:13:57 by vhacman           #+#    #+#             */
/*   Updated: 2025/04/07 15:24:22 by vhacman          ###   ########.fr       */
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

// Represents a node in a stack (linked list), storing the input value,
// its index in sorted order, and a pointer to the next node.
typedef struct s_stack_node
{
	int						value;
	int						index;
	struct s_stack_node		*next;
}	t_stack_node;

// Stores rotation costs to move a node to its correct position in the stacks.
// Includes directions, number of rotations per stack, and total move count.
typedef struct s_cost
{
	int	rotations_a;
	int	rotations_b;
	int	direction_a;
	int	direction_b;
	int	total_moves;
}	t_cost;

// Defines a segment in an array for use in merge sort or chunk logic.
// Contains left, mid, and right bounds.
typedef struct s_bounds
{
	int	left;
	int	mid;
	int	right;
}	t_bounds;

// Same as s_bounds; used for clarity in recursive merge sort calls.
typedef struct s_range_limits
{
	int	left;
	int	mid;
	int	right;
}	t_range_limits;

// Stores the best candidate node to move, with its associated move cost.
typedef struct s_target_info
{
	t_stack_node	*node;
	t_cost			cost;
}	t_target_info;

// Represents chunk information during chunk-based sorting.
// limit is the upper index limit, size is chunk width.
typedef struct s_chunk_info
{
	int		limit;
	int		size;
}	t_chunk_info;
/* ========================= MAIN ENTRY POINT ======================== */

int					main(int ac, char **av);

/* ===================== INITIALIZATION & CLEANUP ===================== */
int					initialize_stack(int ac, char **av, t_stack_node **stack_a);
void				validate_input(char **av, int ac, t_stack_node **stack);
void				free_stack(t_stack_node *stack);
void				free_split(char **token);

/* ===================== SORTING ALGORITHMS ===================== */
void				perform_sorting(t_stack_node **stack_a,
						t_stack_node **stack_b, int size);
void				mini_sort_a(t_stack_node **a, t_stack_node **b);
void				ultra_chunk_sort(t_stack_node **a, t_stack_node **b,
						int total_size);
void				hybrid_sort(t_stack_node **a, t_stack_node **b);

/* ===================== INDEX UTILS & SORT ===================== */
void				merge_sort(int *array, int size);
void				assign_indices(t_stack_node *stack, int *sorted_array,
						int size);
void				merge_sort_recursive(int *array, int *arr_temp,
						t_range_limits limits);

/* ===================== CHUNK SORTING ===================== */
void				move_chunks(t_stack_node **a, t_stack_node **b,
						t_chunk_info chunk);
void				rebuild_stack_a(t_stack_node **a, t_stack_node **b);
void				smart_pb(t_stack_node **a, t_stack_node **b);

/* ===================== COST CALCULATION UTILS ===================== */
void				init_target_info(t_target_info *info);
void				set_rotations(int pos, int size, int *direction,
						int *rotations);
void				calculate_move_cost(t_stack_node **a, t_stack_node **b,
						t_stack_node *node, t_cost *cost);
int					distance_to_top(t_stack_node *stack, t_stack_node *target);
int					find_target_position_b(t_stack_node *stack_b, int index);
int					find_position_of_index(t_stack_node *stack, int index);

/* ===================== ARRAY-BASED OPERATIONS ===================== */
void				swap(int *array, int size);
void				push(int *src, int *src_size, int *dest, int *dest_size);
void				rotate(int *array, int size);
void				reverse_rotate(int *array, int size);
void				ss_array(int *s_a, int a_size, int *s_b, int b_size);
void				rr_array(int *s_a, int a_size, int *s_b, int b_size);
void				rrr_array(int *s_a, int a_size, int *s_b, int b_size);

/* ===================== LINKED LIST STACK OPS ===================== */
void				swap_stack(t_stack_node *stack_head, int size);
void				push_stack(t_stack_node **from_stack,
						t_stack_node **to_stack);
void				rotate_stack(t_stack_node **stack_head);
void				reverse_rotate_stack(t_stack_node **stack_head);

/* ========== DOUBLE STACK OPS (LINKED LIST VARIANT) ========== */
void				ss_stack(t_stack_node **src_stack, int src_size,
						t_stack_node **dest_stack, int dest_size);
void				rr_stack(t_stack_node **a, t_stack_node **b);
void				rrr_stack(t_stack_node **a, t_stack_node **b);

/* ===================== INSTRUCTION FUNCTIONS ===================== */
void				pb(t_stack_node **a, t_stack_node **b);
void				pa(t_stack_node **b, t_stack_node **a);
void				sb(t_stack_node *b);
void				sa(t_stack_node *a);
void				ra(t_stack_node **a);
void				rb(t_stack_node **b);
void				rra(t_stack_node **a);
void				rrb(t_stack_node **b);
void				ss(t_stack_node **a, t_stack_node **b);
void				rr(t_stack_node **a, t_stack_node **b);
void				rrr(t_stack_node **a, t_stack_node **b);

/* ===================== MOVE EXECUTION ===================== */
void				execute_combo_move(t_stack_node **a, t_stack_node **b,
						t_cost cost);
void				rotate_both(t_stack_node **a, t_stack_node **b,
						t_cost *cost);
void				rotate_individual(t_stack_node **a, t_stack_node **b,
						t_cost *cost);
void				final_rotate_a(t_stack_node **a);

/* ===================== STACK UTILS ===================== */
t_stack_node		*create_stack_node(int value);
void				create_stack(t_stack_node **stack, int value);
int					stack_size(t_stack_node *stack);
int					*convert_stack_to_array(t_stack_node *stack, int size);

/* ===================== ERROR HANDLING ===================== */
void				exit_error(void);
int					is_sorted(t_stack_node *stack);
int					is_number(char *str);
int					has_duplicates(t_stack_node *stack, int value);

/* ===================== DEBUGGING (OPTIONAL) ===================== */
// void	print_stack(t_stack_node *stack, char *label);
// void	print_indices(t_stack_node *stack);
#endif
