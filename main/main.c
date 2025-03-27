/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:18:41 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/27 09:18:41 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (stack_size(stack_a) <= 1)
		return (0);
	size = stack_size(stack_a);
	temp_array = convert_stack_to_array(stack_a, size);
	if (!temp_array)
		return (1);
	merge_sort(temp_array, size);
	assign_indices(stack_a, temp_array, size);
	free(temp_array);
	if (is_sorted_and_empty(stack_a, stack_b))
		return (0);
	hybrid_sort(&stack_a, &stack_b);
	rebuild_stack_a(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
