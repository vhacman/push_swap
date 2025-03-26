/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:05:06 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/27 00:05:06 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack_node    *stack_a;
	t_stack_node    *stack_b;
	int             i;
	int             value;
	int             size;
	int             *temp_array;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0); // nessun numero da ordinare
	i = 1;
	while (i < ac)
	{
		value = ft_atoi(av[i]);
		create_stack(&stack_a, value);
		i++;
	}
	if (stack_size(stack_a) <= 1)
		return (0); // già ordinato o singolo elemento
	size = stack_size(stack_a);
	temp_array = convert_stack_to_array(stack_a, size);
	if (!temp_array)
		return (1);
	merge_sort(temp_array, size);
	assign_indices(stack_a, temp_array, size);
	free(temp_array);
	// Inserisci algoritmo ibrido
	push_chunks(&stack_a, &stack_b);
	rebuild_stack_a(&stack_a, &stack_b);
	// Alla fine libera la memoria
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
