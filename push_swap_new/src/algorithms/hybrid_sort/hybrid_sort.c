/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hybrid_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:24:44 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/31 23:09:32 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rotations(int pos, int size, int *direction, int *rotations)
{
	if (pos > size / 2)
	{
		*direction = -1;
		*rotations = size - pos;
	}
	else
	{
		*direction = 1;
		*rotations = pos;
	}
}

void	calculate_move_cost(t_stack_node **stack_a, t_stack_node **stack_b,
								t_stack_node *node, t_cost *cost)
{
	int	size_a;
	int	size_b;
	int	pos_a;
	int	pos_b;

	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);
	pos_a = distance_to_top(*stack_a, node);
	pos_b = find_target_position_b(*stack_b, node->index);
	set_rotations(pos_a, size_a, &cost->direction_a, &cost->rotations_a);
	set_rotations(pos_b, size_b, &cost->direction_b, &cost->rotations_b);
	cost->total_moves = cost->rotations_a + cost->rotations_b;
}


void	update_if_better_target(t_stack_node **a, t_stack_node **b,
							int chunk_limit, t_target_info *target,
							int	chunk_size)
{
	t_stack_node	*curr;
	t_cost			cost;
	int				penalized_moves;
	
	curr = *a;
	while (curr)
	{
		if(curr->index >= chunk_limit - chunk_size && curr->index < chunk_limit)
		{
			calculate_move_cost(a, b, curr, &cost);
			penalized_moves = cost.total_moves;
			if (penalized_moves < target->cost.total_moves)
			{
				target->cost = cost;
				target->node = curr;
				if (cost.rotations_a == 0 && cost.rotations_b == 0)
					break ;
			}
		}
		curr = curr->next;
	}
}

/* Moves chunks of elements from stack 'a' to stack 'b'.
 *
 * This function uses a chunk-based approach to gradually move elements 
 * from 'a' to 'b'. It sets an initial chunk_limit equal to chunk_size, 
 * then repeatedly:
 *   1. Initializes target info (target cost and node).
 *   2. Calls update_if_better_target() to find the best candidate 
 *      within the current chunk.
 *   3. If no target is found (target.node is NULL), the chunk_limit is 
 *      increased by chunk_size, and the process repeats.
 *   4. If a valid target is found, execute_combo_move() is called to 
 *      perform the necessary rotations and push the element from 'a' 
 *      to 'b'.
 * This chunk-based method breaks the problem into smaller parts, which 
 * simplifies sorting by reducing the number of moves needed. 
 * The update_if_better_target function evaluates each element's
 * cost to determine the optimal move.
 * By adjusting the chunk_limit dynamically, the algorithm efficiently 
 * handles varying distributions of elements in stack 'a'. */
static void	move_chunks(t_stack_node **a, t_stack_node **b, int chunk_size)
{
	t_target_info	target;
	int				chunk_limit;

	chunk_limit = chunk_size;
	while (*a)
	{
		init_target_info(&target);
		update_if_better_target(a, b, chunk_limit, &target, chunk_size);
		if (!target.node)
		{
			chunk_limit += chunk_size;
			continue ;
		}
		execute_combo_move(a, b, target.cost);
	}
}

/* Sorts stack 'a' using a hybrid approach for 
 * medium-sized inputs (6 <= size < 500).
 *
 * This function first checks if the stack is already sorted.
 * It then calculates the size of 'a' and determines a chunk size:
 *   - For sizes between 6 and 100, the chunk size is computed as 
 *     size / 5.5.
 *   - For sizes greater than 100 (up to 499), a fixed chunk size of 12
 *     is used.
 *
 * The function calls move_chunks() to push groups of elements from 
 * 'a' to 'b' based on the determined chunk size. After moving chunks, 
 * if stack 'b' is sorted, all elements are pushed back to 'a' with 
 * pa(), followed by a final rotation (final_rotate_a()). Otherwise, 
 * rebuild_stack_a() is used to merge 'b' back into 'a' before the 
 * final rotation.
 *
 * hybrid_sort is applied only when the total number of elements is between 
 * 6 and 499. For 5 or fewer elements, mini_sort_a is used, and for 500 or 
 * more elements, ultra_chunk_sort is employed.*/
void	hybrid_sort(t_stack_node **a, t_stack_node **b)
{
	int		size;
	int		chunk_size;

	if (is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size >= 6 && size <= 100 )
		chunk_size = size / 5.5;
	else
		chunk_size = 12;
	move_chunks(a, b, chunk_size);
	if (is_stack_b_sorted(*b))
	{
		while (*b)
			pa(b, a);
		final_rotate_a(a);
	}
	else
	{
		rebuild_stack_a(a, b);
		final_rotate_a(a);
	}
}
