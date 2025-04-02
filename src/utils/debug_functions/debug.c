/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:01:40 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/31 23:38:01 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// /*
//  * print_stack - Prints the stack's values with a label.
//  *
//  * This function writes the label followed by ": ", then iterates over
//  * the stack and prints each node's value.
//  *
//  * Out-of-scope commentary:
//  * Debug output like this helps trace the current state of the stack
//  * during execution, useful for verifying sorting and other logic.
//  */
// void	print_stack(t_stack_node *stack, char *label)
// {
// 	char	buf[20];
// 	int		len;

// 	write(1, label, strlen(label));
// 	write(1, ": ", 2);
// 	while (stack)
// 	{
// 		len = sprintf(buf, "%d ", stack->value);
// 		write(1, buf, len);
// 		stack = stack->next;
// 	}
// 	write(1, "\n", 1);
// }

// /*
//  * print_indices - Prints the indices of nodes in the stack.
//  *
//  * This function iterates through the stack and writes each node's
//  * index to standard output.
//  *
//  * Out-of-scope commentary:
//  * Printing the indices is useful for debugging purposes, to check
//  * that the index assignment is correct and to monitor the order of
//  * nodes during the sort process.
//  */
// void	print_indices(t_stack_node *stack)
// {
// 	char	buf[20];

// 	while (stack)
// 	{
// 		sprintf(buf, "%d ", stack->index);
// 		write(1, buf, strlen(buf));
// 		stack = stack->next;
// 	}
// 	write(1, "\n", 1);
// }
