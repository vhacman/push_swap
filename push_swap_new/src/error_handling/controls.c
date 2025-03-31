/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:30:38 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/31 17:30:38 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Checks if a string represents a valid integer.
 *
 * This function verifies that a given string is a valid number.
 * It allows an optional '+' or '-' at the beginning, and then
 * ensures that every subsequent character is a digit.
 * It returns 1 if the string is a valid number, otherwise 0.

 * Input validation is critical for ensuring that only numeric
 * values are processed. This function helps prevent errors during
 * conversion by catching non-digit characters early.
 */
int	is_number(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*Check if the given value already exists in the stack.
 *
 * This function iterates over the linked list representing the stack.
 * If it finds a node with the same value as the one provided, it returns
 * 1, indicating that a duplicate exists. Otherwise, it returns 0.
 *
 * The duplicate check is crucial for ensuring that only unique values
 * are added to the stack. This prevents unexpected behavior in later
 * stages of the program, as the sorting algorithm relies on distinct
 * elements to function correctly.*/
int	has_duplicates(t_stack_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
