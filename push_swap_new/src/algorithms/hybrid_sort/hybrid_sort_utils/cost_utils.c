/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:48:55 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/28 17:21:06 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_target_info(t_target_info *info)
{
	info->node = NULL;
	info->cost.rotations_a = 0;
	info->cost.rotations_b = 0;
	info->cost.direction_a = 1;
	info->cost.direction_b = 1;
	info->cost.total_moves = INT_MAX;
}

int	distance_to_top(t_stack_node *stack, t_stack_node *target)
{
	int		dist;

	dist = 0;
	while (stack && stack != target)
	{
		stack = stack->next;
		dist++;
	}
	return (dist);
}

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
