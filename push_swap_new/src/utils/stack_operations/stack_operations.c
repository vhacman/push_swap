/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:04:27 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/27 09:04:27 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * swap_stack - Swaps the values of the first two nodes of a stack.
 * @stack_head: Pointer to the head of the stack.
 * @size: The size of the stack (used to prevent invalid operations).
 *
 * If the stack has fewer than two elements or is NULL, nothing happens.
 * The function swaps the content (value pointer) of the top two nodes.
 *
 * Example:
 *     Input stack: [3, 2, 1] → After swap_stack: [2, 3, 1]
 */
void	swap_stack(t_stack_node *stack_head, int size)
{
	int	temp_value;

	if (size < 2 || !stack_head || !stack_head->next)
		return ;
	temp_value = stack_head->value;
	stack_head->value = stack_head->next->value;
	stack_head->next->value = temp_value;
}

/**
 * push_stack - Pushes the top node from one stack to another.
 * @from_stack: Pointer to the source stack (node will be removed from here).
 * @to_stack: Pointer to the destination stack (node will be added here).
 *
 * If the source stack is empty or any pointer is invalid, nothing happens.
 * The first node of from_stack is removed and becomes the new head of to_stack.
 *
 * Example:
 *     from_stack: [5, 6], to_stack: [2, 1]
 *     After push_stack: from_stack: [6], to_stack: [5, 2, 1]
 */
void	push_stack(t_stack_node **from_stack, t_stack_node **to_stack)
{
	t_stack_node	*node_to_move;

	if (!from_stack || !*from_stack || !to_stack)
		return ;
	node_to_move = *from_stack;
	*from_stack = (*from_stack)->next;
	node_to_move->next = *to_stack;
	*to_stack = node_to_move;
}

/**
 * rotate_stack - Moves the top element of the stack to the bottom.
 * @stack_head: Pointer to the head of the stack.
 *
 * If the stack has fewer than two elements, nothing happens.
 * The head becomes the last node, and the second node becomes the new head.
 *
 * Example:
 *     Input stack: [1, 2, 3] → After rotate_stack: [2, 3, 1]
 */
void	rotate_stack(t_stack_node **stack_head)
{
	t_stack_node	*old_head;
	t_stack_node	*current_tail;

	if (!stack_head || !*stack_head || !(*stack_head)->next)
		return ;
	old_head = *stack_head;
	*stack_head = old_head->next;
	old_head->next = NULL;
	current_tail = *stack_head;
	while (current_tail->next)
		current_tail = current_tail->next;
	current_tail->next = old_head;
}

/**
 * reverse_rotate_stack - Moves the last element of the stack to the top.
 * @stack_head: Pointer to the head of the stack.
 *
 * If the stack has fewer than two elements, nothing happens.
 * The last node becomes the new head, and all other elements shift down.
 *
 * Example:
 *     Input stack: [1, 2, 3] → After reverse_rotate_stack: [3, 1, 2]
 */
void	reverse_rotate_stack(t_stack_node **stack_head)
{
	t_stack_node	*second_last_node;
	t_stack_node	*last_node;

	if (!stack_head || !*stack_head || !(*stack_head)->next)
		return ;
	second_last_node = NULL;
	last_node = *stack_head;
	while (last_node->next)
	{
		second_last_node = last_node;
		last_node = last_node->next;
	}
	second_last_node->next = NULL;
	last_node->next = *stack_head;
	*stack_head = last_node;
}
