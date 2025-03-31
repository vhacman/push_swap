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

/* Swaps the values of the first two nodes of the stack.
 *
 * This function checks if there are at least two elements in the stack
 * (using the parameter 'size' and verifying that the head and its next
 * pointer are not NULL). If the condition is met, it swaps the 'value'
 * fields of the first node and the second node.
 *
 * The swap operation is a basic yet fundamental move in many 
 * sorting algorithms, including those used in push_swap. Instead of
 * physically reordering nodes in the linked list (which would involve
 * updating pointers), this implementation simply exchanges the data
 * (the 'value' fields) of the first two nodes. This approach is
 * efficient for small operations and helps to minimize the overall
 * number of moves required during sorting.*/
void	swap_stack(t_stack_node *stack_head, int size)
{
	int	temp_value;

	if (size < 2 || !stack_head || !stack_head->next)
		return ;
	temp_value = stack_head->value;
	stack_head->value = stack_head->next->value;
	stack_head->next->value = temp_value;
}

/* Moves the top node from one stack to another.
 *
 * This function removes the first node from the stack pointed to by
 * 'from_stack' and inserts it at the front of the stack pointed to by
 * 'to_stack'. It updates both stack pointers accordingly.
 *
 * By transferring the top element 
 * from one stack to another, it enables reordering of elements. */
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

/* Rotates the stack by moving the first element to the end.
 *
 * This function takes the head of the stack (a linked list) and moves 
 * the first node to the end. It first checks if the stack is empty or 
 * has only one node, in which case no rotation is needed.
 *
 * The rotation is achieved by saving the old head, updating the head
 * pointer to the second node, and detaching the old head by setting
 * its next pointer to NULL. Then, it traverses the list to find the 
 * tail and attaches the old head to the end. This operation is key in
 * the push_swap project for repositioning elements efficiently. */
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

/* Reverse rotates the stack.
 *
 * This function moves the last node of the linked list to the front,
 * effectively performing a reverse rotation on the stack.
 * 
 * The algorithm first checks if the stack is empty or has only one
 * element, in which case no rotation is needed. It then traverses the
 * list to locate the last node and its predecessor. The predecessor's
 * next pointer is set to NULL to detach the last node from its original
 * position. Afterwards, the last node is linked to the front of the list
 * by setting its next pointer to the previous head, and the head pointer
 * is updated accordingly. This operation is critical in the push_swap
 * algorithm to reposition elements efficiently and reduce overall moves.
 */
void	reverse_rotate_stack(t_stack_node **stack_head)
{
	t_stack_node	*previous_node;
	t_stack_node	*last_node;

	if (!stack_head || !*stack_head || !(*stack_head)->next)
		return ;
	previous_node = NULL;
	last_node = *stack_head;
	while (last_node->next)
	{
		previous_node = last_node;
		last_node = last_node->next;
	}
	previous_node->next = NULL;
	last_node->next = *stack_head;
	*stack_head = last_node;
}
