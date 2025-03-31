/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hybrid_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:24:44 by vhacman           #+#    #+#             */
/*   Updated: 2025/04/01 00:37:16 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Determines the rotation direction and count.
 *
 * If the position is in the second half of the stack, it is more
 * efficient to use reverse rotations. In that case, the direction is
 * set to -1 and the number of rotations is calculated as 
 * (size - pos). Otherwise, the direction is set to 1 (normal rotation)
 * and the number of rotations equals pos.
 *
 * This function helps minimize the total moves by choosing the shorter 
 * rotation path.*/
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

/* Computes the move cost for shifting a node
 * from stack_a to its correct position in stack_b.
 *
 * It calculates the sizes of both stacks, the distance of the node 
 * from the top of stack_a, and the target position in stack_b.
 * Then, it uses set_rotations() to determine the rotation count
 * and direction for each stack. The total cost is the sum of the 
 * rotations required.*/
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

/* Update the target if a better move is found.
 *
 * This function iterates through stack 'a' and checks if a node's
 * index is within the current chunk range (from
 * chunk_limit - chunk_size to chunk_limit). For each node in the range,
 * it calculates the move cost using calculate_move_cost(). If the cost
 * is lower than the current target's cost, the target info is updated.
 * If a node requires zero rotations on both stacks, the search stops.
 *
 * This selection process helps minimize the total number of moves by
 * choosing the node with the lowest cost. It is a critical step in
 * optimizing the overall sorting process in push_swap.
 */
void	update_if_better_target(t_stack_node **a, t_stack_node **b,
		t_chunk_info chunk, t_target_info *target)
{
	t_stack_node	*curr;
	t_cost			cost;
	int				penalized_moves;

	curr = *a;
	while (curr)
	{
		if (curr->index >= chunk.limit - chunk.size
			&& curr->index < chunk.limit)
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
void	move_chunks(t_stack_node **a, t_stack_node **b, t_chunk_info chunk)
{
	t_target_info	target;

	while (*a)
	{
		init_target_info(&target);
		update_if_better_target(a, b, chunk, &target);
		if (!target.node)
		{
			chunk.limit += chunk.size;
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
	int				size;
	t_chunk_info	chunk;

	if (is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size >= 6 && size <= 100)
		chunk.size = size / 5.5;
	else
		chunk.size = 12;
	chunk.limit = chunk.size;
	move_chunks(a, b, chunk);
	if (is_sorted(*b))
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
