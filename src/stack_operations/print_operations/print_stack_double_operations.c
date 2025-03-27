/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack_double_operations.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:49:48 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/27 11:49:48 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack_node *a, t_stack_node *b)
{
	swap_stack(a, stack_size(a));
	swap_stack(b, stack_size(b));
	write(1, "ss\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate_stack(a);
	rotate_stack(b);
	write(1, "rr\n", 3);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	write(1, "rrr\n", 4);
}
