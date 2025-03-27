/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:48:15 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/27 11:48:15 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node *a)
{
	swap_stack(a, stack_size(a));
	write(1, "sa\n", 3);
}

void	sb(t_stack_node *b)
{
	swap_stack(b, stack_size(b));
	write(1, "sb\n", 3);
}

void	pa(t_stack_node **b, t_stack_node **a)
{
	// write(2, "DEBUG: pa()\n", 12); 
	push_stack(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push_stack(a, b);
	write(1, "pb\n", 3);
}
