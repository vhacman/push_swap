/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_optimal_moves.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:17:26 by vhacman           #+#    #+#             */
/*   Updated: 2025/04/01 00:39:41 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Pushes the top element from stack 'a' to stack 'b' 
 * intelligently.
 *
 * This function first retrieves the index of the top element in 'a'
 * and calculates the total size of both stacks. It then pushes the 
 * element from 'a' to 'b' using pb(). After pushing, if stack 'b' 
 * has more than 4 elements and the pushed element's index is in the 
 * lower 1/7th portion of the total size, it rotates stack 'b' (rb) to
 * better position the element.
 *
 * The function is designed to optimize the push operation by adjusting 
 * the order of elements in 'b'. By checking if the pushed element's index 
 * is relatively low (index < size / 7), it ensures that smaller values 
 * get rotated towards a more favorable position, which helps reduce 
 * overall moves in the sorting algorithm. */
void	smart_pb(t_stack_node **a, t_stack_node **b)
{
	int	size;
	int	index;

	if (!*a)
		return ;
	index = (*a)->index;
	size = stack_size(*a) + stack_size(*b);
	pb(a, b);
	if (*b && (*b)->next && stack_size(*b) > 4
		&& index < size / 7)
		rb(b);
}

/* Rotates both stacks simultaneously.
 *
 * This function rotates stacks 'a' and 'b' at the same time while both
 * require rotations, as specified by the cost structure. If both stacks
 * need normal rotation (direction 1), rr() is called to rotate them
 * together. If both require reverse rotation (direction -1), rrr() is
 * used. This combined rotation reduces the total number of moves.*/
void	rotate_both(t_stack_node **a, t_stack_node **b, t_cost *cost)
{
	while (cost->rotations_a > 0 && cost->rotations_b > 0)
	{
		if (cost->direction_a == 1 && cost->direction_b == 1)
		{
			rr(a, b);
			cost->rotations_a--;
			cost->rotations_b--;
		}
		else if (cost->direction_a == -1 && cost->direction_b == -1)
		{
			rrr(a, b);
			cost->rotations_a--;
			cost->rotations_b--;
		}
		else
			break ;
	}
}

/* Rotates each stack individually based on cost.
 *
 * This function applies the required rotations on stack 'a' and stack 'b'
 * as specified by the cost structure. For stack 'a', it uses either normal
 * rotation (ra) or reverse rotation (rra) based on the direction, and then
 * decrements the rotation count. It does the same for stack 'b' using rb or 
 * rrb.*/
void	rotate_individual(t_stack_node **a, t_stack_node **b, t_cost *cost)
{
	while (cost->rotations_a > 0)
	{
		if (cost->direction_a == 1)
			ra(a);
		else
			rra(a);
		cost->rotations_a--;
	}
	while (cost->rotations_b > 0)
	{
		if (cost->direction_b == 1)
			rb(b);
		else
			rrb(b);
		cost->rotations_b--;
	}
}

/* Rotates stack 'a' so that the node with index 0 
 * becomes the top.
 *
 * The function finds the position of the node whose index is 0.
 * Based on whether it is in the first or second half of the stack,
 * it performs normal rotations (ra) or reverse rotations (rra)
 * to bring it to the top.
 */
void	final_rotate_a(t_stack_node **a)
{
	int				size;
	int				pos;
	t_stack_node	*curr;

	curr = *a;
	size = stack_size(*a);
	pos = 0;
	while (curr && curr->index != 0)
	{
		pos++;
		curr = curr->next;
	}
	if (pos <= size / 2)
		while ((*a)->index != 0)
			ra(a);
	else
		while ((*a)->index != 0)
			rra(a);
}

/* Executes a combined move on both stacks.
 *
 * If no rotations are needed (rotations_a and rotations_b are 0), it
 * directly pushes the top element from 'a' to 'b' using smart_pb.
 * Otherwise, it first rotates both stacks together (rotate_both),
 * then performs any remaining individual rotations (rotate_individual),
 * and finally pushes the element using smart_pb.
 *
 * This function minimizes the total move count by combining
 * simultaneous rotations with individual ones. By reducing the
 * rotations needed on both stacks in one step, then handling the
 * leftover rotations, the algorithm efficiently repositions the
 * target element before pushing it. This combo move is critical
 * for optimizing the overall performance in push_swap.*/
void	execute_combo_move(t_stack_node **a, t_stack_node **b, t_cost cost)
{
	if (cost.rotations_a == 0 && cost.rotations_b == 0)
	{
		smart_pb(a, b);
		return ;
	}
	rotate_both(a, b, &cost);
	rotate_individual(a, b, &cost);
	smart_pb(a, b);
}
// void	execute_combo_rebuild(t_stack_node **a, t_stack_node **b, t_cost cost)
// {
// 	if (cost.rotations_a == 0 && cost.rotations_b == 0)
// 	{
// 		pa(b, a);
// 		return ;
// 	}
// 	rotate_both(a, b, &cost);
// 	rotate_individual(a, b, &cost);
// 	pa(b, a);
// }

// void	execute_optimal_move(t_stack_node **a, t_stack_node **b, t_cost cost)
// {
// 	rotate_both(a, b, &cost);
// 	rotate_individual(a, b, &cost);
// 	pb(a, b);
// }
