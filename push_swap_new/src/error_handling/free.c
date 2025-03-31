/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:41:52 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/31 21:41:52 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Frees all nodes in the stack to prevent memory leaks.
 *
 * This function traverses the linked list representing the stack and frees
 * each node one by one. It uses a temporary pointer to hold the next node
 * before freeing the current one, ensuring that the entire list is
 * deallocated properly. */
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

/*Frees a null-terminated array of strings.
 *
 * This function iterates over the array of tokens, freeing each string.
 * After all individual strings are freed, it frees the array itself.
 * This function is essential for preventing memory leaks, especially
 * after using functions like ft_split that dynamically allocate memory.
 */
void	free_split(char **token)
{
	int	i;

	if (!token)
		return ;
	i = 0;
	while (token[i])
	{
		free(token[i]);
		i++;
	}
	free(token);
}