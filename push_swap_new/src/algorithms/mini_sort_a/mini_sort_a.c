/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:07:03 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/28 17:12:38 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
