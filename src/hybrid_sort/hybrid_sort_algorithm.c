/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hybrid_sort_algorithm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:24:44 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/27 00:24:44 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Calculates the number of moves (rotations) required to bring a given node
 * to the top of stack A and insert it into the correct position in stack B.
 * It updates the cost struct with the move count and direction (normal or 
 * reverse).
 */
static void	calculate_move_cost(t_stack_node **stack_a, t_stack_node **stack_b,
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
	cost->rotations_a = pos_a;
	if (pos_a > size_a / 2)
	{
		cost->direction_a = -1;
		cost->rotations_a = size_a - pos_a;
	}
	else
		cost->direction_a = 1;
	cost->rotations_b = pos_b;
	if (pos_b > size_b / 2)
	{
		cost->direction_b = -1;
		cost->rotations_b = size_b - pos_b;
	}
	else
		cost->direction_b = 1;
	cost->total_moves = cost->rotations_a + cost->rotations_b;
}

/*
 * Scans through stack A to find the best candidate node to push to stack B,
 * based on whether its index is within the current chunk limit.
 * For each valid node, it calculates the cost and updates the target
 * if a better (cheaper) move is found.
 */
static void	update_if_better_target(t_stack_node **a, t_stack_node **b,
									int chunk_limit, t_target_info *target)
{
	t_stack_node	*curr;
	t_cost			cost;

	curr = *a;
	while (curr)
	{
		if (curr->index < chunk_limit)
		{
			calculate_move_cost(a, b, curr, &cost);
			if (cost.total_moves < target->cost.total_moves)
			{
				target->cost = cost;
				target->node = curr;
			}
		}
		curr = curr->next;
	}
}

/*
 * Main hybrid sort logic:
 * Uses a greedy approach in combination with chunks to iteratively select
 * and push the best node (within the chunk limit) from stack A to B.
 * If no valid node is found in the current chunk, the chunk limit is increased.
 * This continues until stack A is empty.
 */
void	hybrid_sort(t_stack_node **a, t_stack_node **b)
{
	int				chunk_size;
	int				chunk_limit;
	t_target_info	target;

	chunk_size = 25;
	chunk_limit = chunk_size;
	while (*a)
	{
		init_target_info(&target);
		update_if_better_target(a, b, chunk_limit, &target);
		if (!target.node)
		{
			chunk_limit += chunk_size;
			continue ;
		}
		execute_optimal_move(a, b, target.cost);
		push_stack(a, b);
	}
}
