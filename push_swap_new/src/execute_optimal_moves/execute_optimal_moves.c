/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_optimal_moves.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:17:26 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/31 18:26:12 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b, t_cost *cost)
{
	while (cost->rotations_a > 0 && cost->rotations_b > 0)
	{
		if (cost->direction_a == 1 && cost->direction_b == 1)
		{
			rr(a, b);
			cost->rotations_a--;
			cost->rotations_b--;
		}
		else if (cost->direction_a == -1 && cost->direction_b == -1)
		{
			rrr(a, b);
			cost->rotations_a--;
			cost->rotations_b--;
		}
		else
			break ;
	}
}

static void	rotate_individual(t_stack_node **a, t_stack_node **b, t_cost *cost)
{
	while (cost->rotations_a > 0)
	{
		if (cost->direction_a == 1)
			ra(a);
		else
			rra(a);
		cost->rotations_a--;
	}
	while (cost->rotations_b > 0)
	{
		if (cost->direction_b == 1)
			rb(b);
		else
			rrb(b);
		cost->rotations_b--;
	}
}

void	execute_combo_rebuild(t_stack_node **a, t_stack_node **b, t_cost cost)
{
	if (cost.rotations_a == 0 && cost.rotations_b == 0)
	{
		pa(b, a);
		return ;
	}
	rotate_both(a, b, &cost);
	rotate_individual(a, b, &cost);
	pa(b, a);
}

void	execute_combo_move(t_stack_node **a, t_stack_node **b, t_cost cost)
{
	if (cost.rotations_a == 0 && cost.rotations_b == 0)
	{
		smart_pb(a, b);
		return ;
	}
	rotate_both(a, b, &cost);
	rotate_individual(a, b, &cost);
	smart_pb(a, b);
}

void	execute_optimal_move(t_stack_node **a, t_stack_node **b, t_cost cost)
{
	rotate_both(a, b, &cost);
	rotate_individual(a, b, &cost);
	pb(a, b);
}
