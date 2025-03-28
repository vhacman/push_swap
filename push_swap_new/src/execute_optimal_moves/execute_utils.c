/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:54:41 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/28 18:00:52 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotate_a(t_stack_node **a)
{
	int				size;
	int				pos;
	t_stack_node	*curr;

	curr = *a;
	size = stack_size(*a);
	pos = 0;
	while (curr && curr->index != 0)
	{
		pos++;
		curr = curr->next;
	}
	if (pos <= size / 2)
		while ((*a)->index != 0)
			ra(a);
	else
		while ((*a)->index != 0)
			rra(a);
}

int	is_stack_b_sorted(t_stack_node *b)
{
	while (b && b->next)
	{
		if (b->index < b->next->index)
			return (0);
		b = b->next;
	}
	return (1);
}
