/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_logic_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:14:26 by vhacman           #+#    #+#             */
/*   Updated: 2025/04/01 00:37:37 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Simultaneously swaps the first two elements of 
 * two arrays.
 *
 * This function calls swap() on s_a and s_b using their sizes.
 *
 * Out-of-scope commentary:
 * This operation mimics swapping the top elements of two stacks
 * simultaneously. It is useful when you need to adjust both arrays
 * in parallel during sorting.*/
void	ss_array(int *s_a, int a_size, int *s_b, int b_size)
{
	swap(s_a, a_size);
	swap(s_b, b_size);
}

/* Simultaneously rotates two arrays.
 *
 * This function calls rotate() on both s_a and s_b, moving the first 
 * element of each array to the end.
 *
 * Out-of-scope commentary:
 * Simultaneous rotation is used to keep arrays in sync. It is akin 
 * to rotating two stacks together in sorting algorithms. */
void	rr_array(int *s_a, int a_size, int *s_b, int b_size)
{
	rotate(s_a, a_size);
	rotate(s_b, b_size);
}

/* Simultaneously reverse rotates two arrays.
 *
 * This function calls reverse_rotate() on both s_a and s_b, moving the 
 * last element of each array to the front.
 * 
 * Reverse rotating both arrays together optimizes moves when the 
 * desired elements are closer to the end. It is similar to reverse 
 * rotating two stacks at the same time. */
void	rrr_array(int *s_a, int a_size, int *s_b, int b_size)
{
	reverse_rotate(s_a, a_size);
	reverse_rotate(s_b, b_size);
}
