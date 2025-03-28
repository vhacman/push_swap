/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:01:40 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/28 17:06:01 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack_node *stack, char *label)
{
	char	buf[20];
	int		len;

	write(1, label, strlen(label));
	write(1, ": ", 2);
	while (stack)
	{
		len = sprintf(buf, "%d ", stack->value);
		write(1, buf, len);
		stack = stack->next;
	}
	write(1, "\n", 1);
}

void	print_indices(t_stack_node *stack)
{
	char	buf[20];

	while (stack)
	{
		sprintf(buf, "%d ", stack->index);
		write(1, buf, strlen(buf));
		stack = stack->next;
	}
	write(1, "\n", 1);
}
