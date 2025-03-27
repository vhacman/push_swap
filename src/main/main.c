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

// static void	print_stack_indices(t_stack_node *a)
// {
//     write(1, "Indici stack_a: ", 17);
//     while (a)
//     {
//         char buf[20];
//         int len = sprintf(buf, "%d ", a->index);
//         write(1, buf, len);
//         a = a->next;
//     }
//     write(1, "\n", 1);
// }
// void	print_stack(t_stack_node *stack, char *label)
// {
// 	write(1, label, strlen(label));
// 	write(1, ": ", 2);
// 	while (stack)
// 	{
// 		char buf[20];
// 		int len = sprintf(buf, "%d ", stack->value);
// 		write(1, buf, len);
// 		stack = stack->next;
// 	}
// 	write(1, "\n", 1);
// }


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
	// write(1, "Input validato\n", 15);
	// print_stack(stack_a, "Contenuto di stack_a");


	if (stack_size(stack_a) <= 1)
		return (0);
	size = stack_size(stack_a);

	// char buf[50];
	// int len = sprintf(buf, "Stack size = %d\n", size);
	// write(1, buf, len);

	temp_array = convert_stack_to_array(stack_a, size);

	if (!temp_array)
	{
		write(1, "Errore: temp_array NULL\n", 25);
		return (1);
	}
	merge_sort(temp_array, size);
	assign_indices(stack_a, temp_array, size);
	// print_stack_indices(stack_a);

	free(temp_array);
	if (is_sorted_and_empty(stack_a, stack_b))
		return (0);
	// write(1, "Start hybrid_sort\n", 18);
	hybrid_sort(&stack_a, &stack_b);
	// write(1, "Hybrid sort completato\n", 24);
	rebuild_stack_a(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
