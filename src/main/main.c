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

#include <unistd.h>
#include <stdio.h>  // per sprintf

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

	for (int i = 1; i < ac; i++)
	{
		write(1, "Arg: ", 5);
		write(1, av[i], strlen(av[i]));
		write(1, "\n", 1);
	}

	for (int i = 1; i < ac; i++)
	{
		write(1, "Arg: ", 5);
		write(1, av[i], strlen(av[i]));
		write(1, "\n", 1);
	}

	validate_input(av, ac, &stack_a);
	write(1, "DEBUG: prima di is_sorted\n", 26);
	print_stack(stack_a, "stack_a");
	if (is_sorted(stack_a))
	{
		write(1, "DEBUG: è già ordinato\n", 23);
		free_stack(stack_a);
		return (0);
	}

	if (stack_size(stack_a) <= 1 || is_sorted(stack_a))
	{
		free_stack(stack_a);
		return (0);
	}

	size = stack_size(stack_a);
	temp_array = convert_stack_to_array(stack_a, size);
	if (!temp_array)
	{
		write(1, "Errore: temp_array NULL\n", 25);
		return (1);
	}

	merge_sort(temp_array, size);
	assign_indices(stack_a, temp_array, size);
	free(temp_array);

	hybrid_sort(&stack_a, &stack_b);
	rebuild_stack_a(&stack_a, &stack_b);

	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
