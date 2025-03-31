/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:08:33 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/31 23:29:21 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Checks if the stack is sorted in ascending order.
 *
 * This function iterates through the linked list that represents the
 * stack. It compares each node's value with its next node's value.
 * If any node's value is greater than its successor's, the function
 * returns 0, indicating that the stack is not sorted.
 *
 * If the iteration completes without finding any disorder, the function
 * returns 1, meaning the stack is sorted.
 *
 * This check is crucial before performing any sorting operations to
 * avoid unnecessary work.
 */
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

/*Initializes the stack from input arguments.
 *
 * This function processes the command-line arguments and builds the
 * linked list stack_a that holds the numbers to sort. It performs the
 * following steps:
 *   1. Sets stack_a to NULL.
 *   2. Validates the input via validate_input().
 *   3. Determines the size of the stack.
 *   4. If the stack has 1 or no element, it frees the stack and returns 0.
 *   5. Converts stack_a into an array, sorts it with merge_sort(), and
 *      assigns indices to nodes with assign_indices().
 *   6. Frees the temporary array and returns the stack size.
 *This initialization is essential to prepare the data for sorting. */
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

/*Chooses and executes the appropriate sorting
 * algorithm based on the size of stack_a.
 *
 * This function first checks if stack_a is already sorted. If so, it frees
 * stack_a and returns early.
 *
 * For input sizes up to 5 elements, it applies a mini sort using 
 * mini_sort_a(), which is efficient for small datasets.
 *
 * For inputs of 500 or more elements, it uses ultra_chunk_sort() to handle
 * large datasets by dividing them into chunks.
 *
 * For all other cases, it applies hybrid_sort() to optimize the sorting moves.
 *
 * After sorting, if stack_a is sorted and stack_b is empty, the function
 * frees stack_a. Otherwise, it frees both stacks.*/
void	perform_sorting(t_stack_node **stack_a, t_stack_node **stack_b,
						int size)
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
	if (is_sorted(*stack_a) && is_sorted(*stack_b))
	{
		free_stack(*stack_a);
		return ;
	}
	free_stack(*stack_a);
	free_stack(*stack_b);
}

/*Main Entry Point of the push_swap Program
 *It is responsible for:
 *   - Validating and initializing input data from the command-line
 *     arguments.
 *   - Building the primary data structure (stack_a) using a linked list
 *     to hold the numbers.
 *   - Deciding whether there is a need to sort (if the input contains more
 *     than one element).
 *   - Selecting and executing the appropriate sorting algorithm based on
 *     the number of elements.
 *   - Managing an auxiliary stack (stack_b) to facilitate certain sorting
 *     strategies.
 *   - Ensuring that memory allocated during initialization and sorting is
 *     properly released.
 *
 * The initialize_stack function validates the input, splits arguments into
 * individual tokens, checks for errors (such as non-numeric input or
 * duplicates), and creates a linked list of nodes.
 *
 * The perform_sorting function then picks a sorting method tailored for
 * small or large datasets. */
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
