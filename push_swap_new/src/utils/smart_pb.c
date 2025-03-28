/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:24:42 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/28 17:51:33 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smart_pb(t_stack_node **a, t_stack_node **b)
{
	int	size;
	int	index;

	if (!*a)
		return ;
	index = (*a)->index;
	size = stack_size(*a) + stack_size(*b);
	pb(a, b);
	if (*b && (*b)->next && stack_size(*b) > 4 && index < size / 2)
		rb(b);
}
