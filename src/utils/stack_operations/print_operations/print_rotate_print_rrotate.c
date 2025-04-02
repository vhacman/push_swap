/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rotate_print_rrotate.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:54:04 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/27 11:54:04 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_node **a)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate_stack(b);
	write(1, "rb\n", 3);
}

void	rra(t_stack_node **a)
{
	reverse_rotate_stack(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	reverse_rotate_stack(b);
	write(1, "rrb\n", 4);
}
