/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultra_chunk_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:03:32 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/28 18:24:23 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_index(t_stack_node *b)
{
	int	max;

	max = b->index;
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
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			break ;
		stack = stack->next;
		pos++;
	}
	return (pos);
}

static void	push_chunks_to_b(t_stack_node **a, t_stack_node **b,
								int chunk_size)
{
	int				chunk_limit;
	t_stack_node	*tmp;

	chunk_limit = chunk_size;
	while (*a)
	{
		tmp = *a;
		if (tmp->index < chunk_limit)
		{
			pb(a, b);
			if (tmp->index < chunk_limit - (chunk_size / 2))
				rb(b);
		}
		else
			ra(a);
		if (stack_size(*b) >= chunk_limit)
			chunk_limit += chunk_size;
	}
}

static void	move_max_to_a(t_stack_node **a, t_stack_node **b)
{
	int	max_index;
	int	pos;
	int	size;

	while (*b)
	{
		max_index = find_max_index(*b);
		pos = find_position(*b, max_index);
		size = stack_size(*b);
		if (pos <= size / 2)
			while ((*b)->index != max_index)
				rb(b);
		else
			while ((*b)->index != max_index)
				rrb(b);
		pa(b, a);
	}
}

void	ultra_chunk_sort(t_stack_node **a, t_stack_node **b, int total_size)
{
	int	chunk_size;

	chunk_size = total_size / 10;
	push_chunks_to_b(a, b, chunk_size);
	move_max_to_a(a, b);
}
