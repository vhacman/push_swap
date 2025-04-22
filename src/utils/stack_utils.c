/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 21:22:25 by vhacman           #+#    #+#             */
/*   Updated: 2025/04/22 10:49:35 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Assigns each node in the stack a sorted index.
 *
 * This function receives:
 * - A linked list (stack) containing nodes with unsorted values.
 * - A sorted array that holds the same values in ascending order
 * - The total number of elements (size).
 *
 * For each node in the stack, it loops through the sorted_array
 * until it finds the element that matches the node's value.
 * When a match is found, the node's 'index' field is set
 * to the position (i.e., rank) in the sorted_array.
 * 
 * By assigning these indices, the algorithm normalizes the data,
 * allowing later operations (like chunking) to work with relative 
 * order rather than raw values.
 * This makes comparisons and moves more efficient, as the indices range 
 * from 0 to (n - 1) regardless of the original values.*/
void	assign_indices(t_stack_node *stack, int *sorted_array, int size)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (i < size)
		{
			if (stack->value == sorted_array[i])
			{
				stack->index = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
}

/* Returns the number of nodes in the stack.
 *
 * This function casts the stack pointer to a generic t_list pointer and
 * uses ft_lstsize to compute the total number of nodes. It assumes that
 * t_stack_node is compatible with t_list */
int	stack_size(t_stack_node *stack)
{
	return (ft_lstsize((t_list *)stack));
}

/* Converts a linked list stack into an array.
 *
 * This function allocates an integer array with a size equal to
 * stack_size. It then traverses the stack and copies each node's value
 * into the array sequentially.
 *
 * Converting a linked list to an array allows the use of efficient
 * sorting algorithms (like merge sort) on the data.*/
int	*convert_stack_to_array(t_stack_node *stack, int stack_size)
{
	int	*array;
	int	i;

	i = 0;
	array = malloc(sizeof(int) * stack_size);
	if (!array)
		return (NULL);
	while (stack)
	{
		array[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (array);
}

// /* Allocates and initializes a new stack node.
//  *
//  * This function allocates memory for a new t_stack_node, sets its value
//  * to the given integer, initializes its index to -1 (a placeholder because 
//  * we don't know the index yet), and sets its next
//  * pointer to NULL. This node is ready to be added to a stack.*/
// t_stack_node	*create_stack_node(int value)
// {
// 	t_stack_node	*node;

// 	node = malloc(sizeof(t_stack_node));
// 	if (!node)
// 		return (NULL);
// 	node->value = value;
// 	node->index = -1;
// 	node->next = NULL;
// 	return (node);
// }

/* Adds a new node with the given value to the end of the stack.
 *
 * This function allocates a new node, sets its value and next pointer,
 * and then appends it to the linked list. If the stack is empty, the new
 * node becomes the head.
 */
void	create_stack(t_stack_node **stack, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*temp;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		exit_error();
	new_node->value = value;
	new_node->next = NULL;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}
