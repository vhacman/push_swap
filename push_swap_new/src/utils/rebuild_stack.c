/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebuild_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:55:20 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/28 18:01:12 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_position(t_stack_node *stack, int *max_index)
{
	int				pos;
	int				max_pos;
	t_stack_node	*curr;

	pos = 0;
	max_pos = 0;
	curr = stack;
	*max_index = curr->index;
	while (curr)
	{
		if (curr->index > *max_index)
		{
			*max_index = curr->index;
			max_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	return (max_pos);
}

void	rebuild_stack_a(t_stack_node **a, t_stack_node **b)
{
	int	max_index;
	int	pos;
	int	size;

	while (*b)
	{
		size = stack_size(*b);
		pos = find_max_position(*b, &max_index);
		if (pos <= size / 2)
		{
			while ((*b)->index != max_index)
				rb(b);
		}
		else
		{
			while ((*b)->index != max_index)
				rrb(b);
		}
		pa(b, a);
	}
}
