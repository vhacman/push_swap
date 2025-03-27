/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultra_chunk_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:03:32 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/27 22:03:32 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static int	find_max_index(t_stack_node *b)
{
	int	max = b->index;
	while (b)
	{
		if (b->index > max)
			max = b->index;
		b = b->next;
	}
	return (max);
}

static int	find_position(t_stack_node *stack, int index)
{
	int	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			break ;
		stack = stack->next;
		pos++;
	}
	return (pos);
}

void	ultra_chunk_sort(t_stack_node **a, t_stack_node **b, int total_size)
{
	int	chunk_size = total_size / 13;
	int	chunk_limit = chunk_size;
	int	i;
	t_stack_node *tmp;

	while (*a)
	{
		tmp = *a;
		if (tmp->index < chunk_limit)
		{
			pb(a, b);
			if (tmp->index < chunk_limit - (chunk_size / 2))
				rb(b);
			i++;
		}
		else
			ra(a);
		if (stack_size(*b) >= chunk_limit)
			chunk_limit += chunk_size;
	}
	while (*b)
	{
		int	max_index = find_max_index(*b);
		int	pos = find_position(*b, max_index);
		int	size = stack_size(*b);

		if (pos <= size / 2)
			while ((*b)->index != max_index)
				rb(b);
		else
			while ((*b)->index != max_index)
				rrb(b);
		pa(b, a);
	}
}
