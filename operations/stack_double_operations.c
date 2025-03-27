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

/**
 * ss_stack - Simultaneously swaps the first two nodes of both stacks.
 * @src_stack: Head of the first stack.
 * @src_size: Size of the first stack.
 * @dest_stack: Head of the second stack.
 * @dest_size: Size of the second stack.
 *
 * Applies swap_stack to both stacks at the same time.
 */
void	ss_stack(t_stack_node *src_stack, int src_size,
			t_stack_node *dest_stack, int dest_size)
{
	swap_stack(src_stack, src_size);
	swap_stack(dest_stack, dest_size);
}

/**
 * rr_stack - Simultaneously rotates both stacks.
 * @src_stack: Pointer to the head pointer of the first stack.
 * @dest_stack: Pointer to the head pointer of the second stack.
 *
 * Moves the first element of each stack to the bottom.
 */
void	rr_stack(t_stack_node **src_stack, t_stack_node **dest_stack)
{
	rotate_stack(src_stack);
	rotate_stack(dest_stack);
}

/**
 * rrr_stack - Simultaneously reverse rotates both stacks.
 * @src_stack: Pointer to the head pointer of the first stack.
 * @dest_stack: Pointer to the head pointer of the second stack.
 *
 * Moves the last element of each stack to the top.
 */
void	rrr_stacl(t_stack_node **src_stack, t_stack_node **dest_stack)
{
	reverse_rotate_stack(src_stack);
	reverse_rotate_stack(dest_stack);
}
