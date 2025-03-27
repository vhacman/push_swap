/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:14:26 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/27 00:14:26 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(int *s_a, int a_size, int *s_b, int b_size)
{
	swap(s_a, a_size);
	swap(s_b, b_size);
}

void	rr(int *s_a, int a_size, int *s_b, int b_size)
{
	rotate(s_a, a_size);
	rotate(s_b, b_size);
}

void	rrr(int *s_a, int a_size, int *s_b, int b_size)
{
	reverse_rotate(s_a, a_size);
	reverse_rotate(s_b, b_size);
}
