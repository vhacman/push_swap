/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:48:55 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/31 23:09:00 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Initializes the target information structure.
 *
 * This function sets the target node pointer to NULL and initializes
 * the cost structure with default values. Specifically, it sets the
 * rotations for both stacks to 0, the rotation directions to 1 (normal),
 * and the total moves cost to INT_MAX to ensure any computed cost will
 * be lower.
 * Initializing target info is critical for optimizing moves in the 
 * algorithm. By starting with a maximum cost, the algorithm can 
 * effectively compare and select the best (i.e., least costly) move.
 * This setup supports the decision-making process when evaluating
 * different potential moves during the sorting operation. */
void	init_target_info(t_target_info *info)
{
	info->node = NULL;
	info->cost.rotations_a = 0;
	info->cost.rotations_b = 0;
	info->cost.direction_a = 1;
	info->cost.direction_b = 1;
	info->cost.total_moves = INT_MAX;
}

/* Calculates the number of nodes from the head of the stack
 * to the target node.
 *
 * This function iterates through the stack starting at the head, and counts
 * the nodes until it reaches the target node. It returns the distance as an
 * integer value representing how many nodes must be traversed.

 * Determining the distance to a specific node is important when optimizing
 * rotation operations. For example, if a target element is closer to the head,
 * a forward rotation may be preferable, whereas if it is near the bottom, a
 * reverse rotation might be more efficient. This function provides a simple
 * way to measure that distance, helping the algorithm decide the best move.*/
int	distance_to_top(t_stack_node *stack, t_stack_node *target)
{
	int		distance;

	distance = 0;
	while (stack && stack != target)
	{
		stack = stack->next;
		distance++;
	}
	return (distance);
}

/* Finds the optimal insertion position in stack_b.
 *
 * This function searches through stack_b to determine the best
 * position where an element with the given 'index' should be inserted.
 * It computes the difference between each node's index in stack_b and
 * the provided index. Only positive differences are considered, and
 * the function keeps track of the smallest positive difference.
 *
 * The function returns the zero-based position (best_pos) where the
 * element should be placed in stack_b.*/
int	find_target_position_b(t_stack_node *stack_b, int index)
{
	int		pos;
	int		best_pos;
	int		best_diff;
	int		diff;

	pos = 0;
	best_pos = 0;
	best_diff = INT_MAX;
	while (stack_b)
	{
		diff = stack_b->index - index;
		if (diff > 0 && diff < best_diff)
		{
			best_diff = diff;
			best_pos = pos;
		}
		stack_b = stack_b->next;
		pos++;
	}
	return (best_pos);
}
