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
	while (*b)
	{
		// write(1, "Current value in stack_b: ", 25);
		// char buf1[20];
		// int len1 = sprintf(buf1, "%d\n", (*b)->value);
		t_stack_node	*curr;
		int				max_index;
		int				pos;
		int				size;
		int				i;
		// write(1, buf1, len1);
		curr = *b;
		max_index = curr->index;
		pos = 0;
		i = 0;
		size = stack_size(*b);
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
		// write(1, "Max index: ", 11);
        // char buf[20];
        // int len = sprintf(buf, "%d, pos: %d\n", max_index, pos);
        // write(1, buf, len);

		// Ruota lo stack b finché il nodo con max_index è in cima
		if (pos <= size / 2)
		{
			while ((*b)->index != max_index)
				rb(b); // ruota verso l’alto
		}
		else
		{
			while ((*b)->index != max_index)
				rrb(b); // ruota verso il basso
		}

		if (*b == NULL)
		{	
			return ;
		}
		else
			pa(b, a);
	
 // push da b a a
		        // Debugging - check the stack contents after push
		// write(1, "Stack A after push: ", 19);
		// print_stack(*a, "A"); // You can implement this print function to print stack content
		// write(1, "Stack B after push: ", 19);
		// print_stack(*b, "B");
		
	}
}
