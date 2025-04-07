/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultra_chunk_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:03:32 by vhacman           #+#    #+#             */
/*   Updated: 2025/04/07 16:32:25 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Returns the maximum index found in the stack.
 *
 * This function initializes 'max' with the index of the first node,
 * then traverses the stack comparing each node's index. If a node's
 * index is greater than the current 'max', it updates 'max'. Finally,
 * it returns the highest index encountered.
 *
 * This helper function is essential for determining the highest
 * priority element in a stack. It is often used in sorting routines
 * where the element with the maximum index needs to be moved or
 * repositioned. */
static int	find_max_index(t_stack_node *b)
{
	int	max_index;

	max_index = b->index;
	while (b)
	{
		if (b->index > max_index)
			max_index = b->index;
		b = b->next;
	}
	return (max_index);
}

/* Finds the position of a node with a given index in the stack.
 *
 * This function traverses the linked list 'stack' and increments a counter
 * until it finds a node whose 'index' matches the provided 'index' parameter.
 * It then returns the current position (zero-based). If no such node is found,
 * it returns the total number of nodes traversed.

 * Knowing the exact position of a node is useful for optimizing rotations
 * (e.g., choosing between normal or reverse rotation) to bring a specific
 * element to the top of the stack. This helper function simplifies that
 * decision-making process by providing a clear measure of how deep the element
 * is within the stack.*/
static int	find_position(t_stack_node *stack, int index)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->index == index)
			break ;
		stack = stack->next;
		position++;
	}
	return (position);
}

/* Moves the element with the highest index from stack_b to stack_a.
 *
 * The function repeatedly finds the element with the largest index in
 * stack_b. It then determines the position of this element and rotates
 * stack_b in the optimal direction (normal rotation if it's in the first
 * half, or reverse rotation if it's in the second half) until the element
 * is at the top. Once it is, the element is pushed to stack_a. This
 * continues until stack_b is empty.

 * This operation is crucial for reassembling the sorted order in stack_a.
 * By always moving the maximum element from stack_b back to stack_a,
 * the algorithm ensures that the highest remaining elements are placed
 * in order, effectively building the final sorted stack from the largest
 * values downward. */
static void	move_max_to_a(t_stack_node **stack_a,
							t_stack_node **stack_b)
{
	int	max_index;
	int	position;
	int	stack_b_size;

	while (*stack_b)
	{
		max_index = find_max_index(*stack_b);
		position = find_position(*stack_b, max_index);
		stack_b_size = stack_size(*stack_b);
		if (position <= stack_b_size / 2)
			while ((*stack_b)->index != max_index)
				rb(stack_b);
		else
			while ((*stack_b)->index != max_index)
				rrb(stack_b);
		pa(stack_b, stack_a);
	}
}

/* Pushes (chunks) of elements from stack 'a' to stack 'b'.
 *
 * This function calculates a moving "current_chunk_limit" based on the 
 * provided chunk_size. It then iterates over stack 'a' and pushes 
 * elements whose index is less than the current_chunk_limit to stack 'b'.
 * 
 * For each element in 'a':
 *   - If its index is below current_chunk_limit, it is pushed to 'b' using pb.
 *   - Additionally, if the element's index is in the lower half of the 
 *     current chunk (i.e., less than current_chunk_limit - chunk_size/2), the 
 *     function rotates 'b' (using rb) to help organize the pushed elements.
 *   - Otherwise, the function rotates 'a' (using ra) to bring new elements 
 *     into view.
 * 
 * The current_chunk_limit is then increased by chunk_size when the number of 
 * elements in 'b' reaches or exceeds the current limit.

 * By partitioning the dataset into chunks, the algorithm reduces the 
 * complexity of sorting large stacks. Pushing elements in (chunks) 
 * allows for more efficient rearrangement later on. The extra 
 * rotation on 'b' (rb) for lower-half indices further organizes the 
 * auxiliary stack, making it easier to merge the chunks back in order.
 */
static void	push_chunks_to_b(t_stack_node **stack_a,
								t_stack_node **stack_b, int chunk_size)
{
	int				current_chunk_limit;
	t_stack_node	*current_node;

	current_chunk_limit = chunk_size;
	while (*stack_a)
	{
		current_node = *stack_a;
		if (current_node->index < current_chunk_limit)
		{
			pb(stack_a, stack_b);
			if (current_node->index < current_chunk_limit - (chunk_size / 2))
				rb(stack_b);
		}
		else
			ra(stack_a);
		if (stack_size(*stack_b) >= current_chunk_limit)
			current_chunk_limit += chunk_size;
	}
}

/* Sorts a large stack by dividing it into smaller chunks.
 *
 * This function calculates the chunk size by dividing the total number
 * of elements (total_size) by 9. It then:
 *   1. Calls push_chunks_to_b() to push groups of elements from stack 'a'
 *      to stack 'b' based on the calculated chunk size.
 *   2. Calls move_max_to_a() to move the largest elements back from stack
 *      'b' to stack 'a' in the proper order.

 * Dividing a large dataset into smaller chunks simplifies the sorting
 * process. By processing each chunk separately, the algorithm reduces
 * the total number of moves required and improves efficiency. The
 * divisor (here 9) is a tunable parameter that can affect performance;
 * it is chosen based on experimental observations to optimize move count
 * in this particular implementation.*/
void	ultra_chunk_sort(t_stack_node **stack_a, t_stack_node **stack_b,
		int total_size)
{
	int	chunk_size;

	chunk_size = total_size / 9;
	push_chunks_to_b(stack_a, stack_b, chunk_size);
	move_max_to_a(stack_a, stack_b);
}
