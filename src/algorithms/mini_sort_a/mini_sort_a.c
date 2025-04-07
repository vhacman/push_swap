/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:07:03 by vhacman           #+#    #+#             */
/*   Updated: 2025/04/07 16:39:06 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sorts a stack of exactly three elements.
 *
 * This function extracts the values of the first three nodes in stack 'a'
 * and compares them to determine their order. Based on the comparison, it
 * performs one or more operations.
 *   1. If first > second, second < third, and first < third:
 *      Only the first two elements are out of order, so perform a swap.
 *   2. If first > second and second > third:
 *      The stack is in descending order; swap the first two and then
 *      reverse rotate to achieve the ascending order.
 *   3. If first > second, second < third, and first > third:
 *      The largest element is at the top; a single rotation brings it
 *      to the bottom.
 *   4. If first < second, second > third, and first < third:
 *      The middle element is the largest; swapping the first two and
 *      then rotating places the largest at the bottom.
 *   5. If first < second, second > third, and first > third:
 *      The smallest element is in the middle; a reverse rotation
 *      brings it to the top.*/
static void	handle_three_elements(t_stack_node **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(*stack_a);
	else if (first > second && second > third)
	{
		sa(*stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(*stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}

/* Returns the position of the node with a specified index in the stack.
 *
 * The function traverses the linked list 'stack' and increments a
 * counter 'pos' for each node. When it finds a node whose 'index'
 * matches the given 'index' parameter, it returns the current
 * position. If no node is found with the matching index, it returns -1.
 *
 * This helper function is essential for determining the relative
 * position of an element in the stack. It is used to decide the optimal
 * rotation direction (normal or reverse) to bring a specific node to
 * the top of the stack, thereby minimizing the number of moves.*/
static int	find_position_of_index(t_stack_node *stack, int index)
{
	int		pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

/* Rotates stack 'a' so that the node with the
 * specified min_index is at the top.
 *
 * First, it finds the position of the node with the given index by
 * calling find_position_of_index(). It then checks if this position
 * is in the first half of the stack (<= stack_size/2). If it is,
 * it rotates normally (ra) until the node reaches the top.
 * Otherwise, it performs reverse rotations (rra).*/
static void	rotate_to_position(t_stack_node **stack_a, int min_index)
{
	int	pos;

	pos = find_position_of_index(*stack_a, min_index);
	if (pos <= stack_size(*stack_a) / 2)
		while ((*stack_a)->index != min_index)
			ra(stack_a);
	else
		while ((*stack_a)->index != min_index)
			rra(stack_a);
}

/* Sorts a small stack (2, 3, 4, or 5 elements).
 *
 * This function checks the size of stack 'a' and applies a specific
 * method:
 *   - If there are 2 elements and the first is greater than the
 *     second, it swaps them.
 *   - If there are 3 elements, it calls handle_three_elements().
 *   - For 4 or 5 elements, it rotates 'a' to bring the smallest
 *     unsorted element (indicated by min_index) to the top, pushes
 *     it to stack 'b', and increments min_index. This loop continues
 *     until only 3 elements remain in 'a'. Then, it recursively sorts
 *     'a' and pushes back all elements from 'b'.
 * 
 * Tailoring the sort strategy for very small datasets minimizes the
 * number of moves, which is crucial in push_swap for efficiency.*/
void	mini_sort_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	size;
	int	min_index;

	size = stack_size(*stack_a);
	min_index = 0;
	if (size == 2 && (*stack_a)->value > (*stack_a)->next->value)
		sa(*stack_a);
	else if (size == 3)
		handle_three_elements(stack_a);
	else if (size == 4 || size == 5)
	{
		while (stack_size(*stack_a) > 3)
		{
			rotate_to_position(stack_a, min_index);
			pb(stack_a, stack_b);
			min_index++;
		}
		mini_sort_a(stack_a, stack_b);
		while (*stack_b)
			pa(stack_b, stack_a);
	}
}
