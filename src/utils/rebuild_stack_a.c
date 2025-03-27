/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebuild_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:34:56 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/27 12:34:56 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rebuild_stack_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*curr;
	int				max_index;
	int				pos;
	int				size;
	int				i;

	while (*b)
	{
		curr = *b;
		max_index = curr->index;
		pos = 0;
		size = stack_size(*b);

		i = 0;
		// Trova il nodo con indice più alto
		while (curr)
		{
			if (curr->index > max_index)
			{
				max_index = curr->index;
				pos = i;
			}
			curr = curr->next;
			i++;
		}
		// Ruota lo stack b finché il nodo con max_index è in cima
		if (pos <= size / 2)
		{
			while ((*b)->index != max_index)
				rotate_stack(b); // ruota verso l’alto
		}
		else
		{
			while ((*b)->index != max_index)
				reverse_rotate_stack(b); // ruota verso il basso
		}

		push_stack(b, a); // push da b a a
	}
}
