/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebuild_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:55:20 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/31 23:28:01 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Finds the position of the node with the maximum index in the stack.
 *
 * This function iterates through the linked list 'stack', and for each
 * node it compares the node's index to the current maximum (stored in
 * *max_index). It updates *max_index and the corresponding position
 * (max_pos) when a higher index is found.
 *
 * It returns the zero-based position (max_pos) of the node with the
 * highest index.*/
static int	find_max_position(t_stack_node *stack, int *max_index)
{
	int				pos;
	int				max_pos;
	t_stack_node	*curr;

	pos = 0;
	max_pos = 0;
	curr = stack;
	*max_index = curr->index;
	while (curr)
	{
		if (curr->index > *max_index)
		{
			*max_index = curr->index;
			max_pos = pos;
		}
		curr = curr->next;
		pos++;
	}
	return (max_pos);
}

/* Rebuilds stack 'a' by moving elements from stack 'b'.
 *
 * This function repeatedly finds the element with the maximum index in
 * stack 'b' (using find_max_position) and rotates stack 'b' to bring it
 * to the top. It chooses the optimal rotation direction (normal or reverse)
 * based on the position of the maximum element. Once the maximum element
 * is at the top, it is pushed to stack 'a' using pa(). This process repeats
 * until stack 'b' is empty.
 *
 * This operation is critical in reassembling the sorted stack 'a' from the
 * auxiliary stack 'b'. By always moving the maximum element from 'b' back
 * to 'a', the algorithm ensures that the final order in 'a' is correct. */
void	rebuild_stack_a(t_stack_node **a, t_stack_node **b)
{
	int	max_index;
	int	pos;
	int	size;

	while (*b)
	{
		size = stack_size(*b);
		pos = find_max_position(*b, &max_index);
		if (pos <= size / 2)
		{
			while ((*b)->index != max_index)
				rb(b);
		}
		else
		{
			while ((*b)->index != max_index)
				rrb(b);
		}
		pa(b, a);
	}
}
// int	get_max_index(t_stack_node *stack)
// {
// 	int	max;

// 	if (!stack)
// 		return (-1);
// 	max = stack->index;
// 	while (stack)
// 	{
// 		if (stack->index > max)
// 			max = stack->index;
// 		stack = stack->next;
// 	}
// 	return (max);
// }

// t_stack_node	*find_max_node(t_stack_node *stack)
// {
// 	t_stack_node	*max;

// 	if (!stack)
// 		return (NULL);
// 	max = stack;
// 	while (stack)
// 	{
// 		if (stack->index > max->index)
// 			max = stack;
// 		stack = stack->next;
// 	}
// 	return (max);
// }

// t_stack_node	*find_min_node(t_stack_node *stack)
// {
// 	t_stack_node	*min;

// 	if (!stack)
// 		return (NULL);
// 	min = stack;
// 	while (stack)
// 	{
// 		if (stack->index < min->index)
// 			min = stack;
// 		stack = stack->next;
// 	}
// 	return (min);
// }
