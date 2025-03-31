/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:07:03 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/31 22:19:01 by vhacman          ###   ########.fr       */
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
void	handle_three_elements(t_stack_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(*a);
	else if (first > second && second > third)
	{
		sa(*a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(*a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
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
int	find_position_of_index(t_stack_node *stack, int index)
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
void	rotate_to_position(t_stack_node **a, int min_index)
{
	int	pos;

	pos = find_position_of_index(*a, min_index);
	if (pos <= stack_size(*a) / 2)
		while ((*a)->index != min_index)
			ra(a);
	else
		while ((*a)->index != min_index)
			rra(a);
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
void	mini_sort_a(t_stack_node **a, t_stack_node **b)
{
	int	size;
	int	min_index;

	size = stack_size(*a);
	min_index = 0;
	if (size == 2 && (*a)->value > (*a)->next->value)
		sa(*a);
	else if (size == 3)
		handle_three_elements(a);
	else if (size == 4 || size == 5)
	{
		while (stack_size(*a) > 3)
		{
			rotate_to_position(a, min_index);
			pb(a, b);
			min_index++;
		}
		mini_sort_a(a, b);
		while (*b)
			pa(b, a);
	}
}
