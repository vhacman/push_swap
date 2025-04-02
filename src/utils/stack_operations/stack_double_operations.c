/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_double_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:10:10 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/27 09:10:10 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Simultaneously swaps the top two elements of both stacks.
 *
 * This function calls swap_stack() on the first stack and on the second
 * stack using their respective sizes. Each call swaps the first two nodes
 * (if there are at least two nodes in the stack).*/
void	ss_stack(t_stack_node **src_stack, int src_size,
			t_stack_node **dest_stack, int dest_size)
{
	swap_stack(*src_stack, src_size);
	swap_stack(*dest_stack, dest_size);
}

/* Rotates both stacks simultaneously.
 *
 * This function calls rotate_stack() for both src_stack and 
 * dest_stack, moving the top element of each stack to its bottom.*/
void	rr_stack(t_stack_node **src_stack, t_stack_node **dest_stack)
{
	rotate_stack(src_stack);
	rotate_stack(dest_stack);
}

/*
 * rrr_stack - Reverse rotates both stacks simultaneously.
 *
 * This function performs a reverse rotation on two stacks: it moves the
 * last element of each stack (src_stack and dest_stack) to the top. */
void	rrr_stack(t_stack_node **src_stack, t_stack_node **dest_stack)
{
	reverse_rotate_stack(src_stack);
	reverse_rotate_stack(dest_stack);
}
