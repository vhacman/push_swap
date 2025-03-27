/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:08:33 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/27 17:08:33 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
void	print_stack(t_stack_node *stack, char *label)
{
	write(1, label, strlen(label));
	write(1, ": ", 2);
	while (stack)
	{
		char buf[20];
		int len = sprintf(buf, "%d ", stack->value);
		write(1, buf, len);
		stack = stack->next;
	}
	write(1, "\n", 1);
}

void	print_indices(t_stack_node *stack)
{
	while (stack)
	{
		char buf[20];
		sprintf(buf, "%d ", stack->index);
		write(1, buf, strlen(buf));
		stack = stack->next;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	int				size;
	int				*temp_array;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);

	validate_input(av, ac, &stack_a);

	size = stack_size(stack_a);
	if (size <= 1)
	{
		free_stack(stack_a);
		return (0);
	}

	temp_array = convert_stack_to_array(stack_a, size);
	if (!temp_array)
		return (1);

	merge_sort(temp_array, size);
	assign_indices(stack_a, temp_array, size);
	if (size == 500)
		ultra_chunk_sort(&stack_a, &stack_b, size);
	else
		hybrid_sort(&stack_a, &stack_b);

	free(temp_array);
	if (is_sorted_and_empty(stack_a, stack_b))
	{
		free_stack(stack_a);
		return (0);
	}
	// write(1, "FINAL STACK A: ", 15);
	// print_stack(stack_a, "A");

	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

