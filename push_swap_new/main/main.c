/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:08:33 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/29 04:26:34 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

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

int	initialize_stack(int ac, char **av, t_stack_node **stack_a)
{
	int	size;
	int	*temp_array;

	*stack_a = NULL;
	size = 0;
	if (ac < 2)
		return (0);
	validate_input(av, ac, stack_a);
	size = stack_size(*stack_a);
	if (size <= 1)
	{
		free_stack(*stack_a);
		return (0);
	}
	temp_array = convert_stack_to_array(*stack_a, size);
	if (!temp_array)
		return (1);
	merge_sort(temp_array, size);
	assign_indices(*stack_a, temp_array, size);
	free(temp_array);
	return (size);
}

void	perform_sorting(t_stack_node **stack_a, t_stack_node **stack_b, int size)
{
	if (is_sorted(*stack_a))
	{
		free_stack(*stack_a);
		return ;
	}
	if (size <= 5)
	{
		mini_sort_a(stack_a, stack_b);
		free_stack(*stack_a);
		return ;
	}
	if (size >= 500)
		ultra_chunk_sort(stack_a, stack_b, size);
	else
		hybrid_sort(stack_a, stack_b);
	if (is_sorted_and_empty(*stack_a, *stack_b))
	{
		free_stack(*stack_a);
		return ;
	}
	free_stack(*stack_a);
	free_stack(*stack_b);
}

int	main(int ac, char **av)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	int				size;

	stack_b = NULL;
	size = initialize_stack(ac, av, &stack_a);
	if (size <= 1)
		return (0);
	perform_sorting(&stack_a, &stack_b, size);
	return (0);
}
