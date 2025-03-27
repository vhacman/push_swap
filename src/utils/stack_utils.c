/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 21:22:25 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/26 21:22:25 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*create_stack_node(int value)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

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
		return;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}



int	stack_size(t_stack_node *stack)
{
	return (ft_lstsize((t_list *)stack));
}

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

void	free_stack(t_stack_node *stack)
{
	t_stack_node	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
