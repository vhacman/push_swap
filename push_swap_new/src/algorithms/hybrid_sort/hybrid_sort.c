/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hybrid_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:24:44 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/29 03:58:01 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_rotations(int pos, int size, int *direction, int *rotations)
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
	set_rotations(pos_a, size_a, &cost->direction_a, &cost->rotations_a);
	set_rotations(pos_b, size_b, &cost->direction_b, &cost->rotations_b);
	cost->total_moves = cost->rotations_a + cost->rotations_b;
}

void	update_if_better_target(t_stack_node **a, t_stack_node **b,
							int chunk_limit, t_target_info *target)
{
	t_stack_node	*curr;
	t_cost			cost;
	int				penalized_moves;

	curr = *a;
	while (curr)
	{
		if (curr->index < chunk_limit)
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

static void	move_chunks(t_stack_node **a, t_stack_node **b, int chunk_size)
{
	t_target_info	target;
	int				chunk_limit;

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
		execute_combo_move(a, b, target.cost);
	}
}

void	hybrid_sort(t_stack_node **a, t_stack_node **b)
{
	int		size;
	int		chunk_size;

	if (is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size <= 100)
		chunk_size = 50;
	else if (size <= 500)
		chunk_size = size / 25;
	else
		chunk_size = 30;
	move_chunks(a, b, chunk_size);
	if (is_stack_b_sorted(*b))
		while (*b)
			pa(b, a);
	else
		rebuild_stack_a(a, b);
	final_rotate_a(a);
}
