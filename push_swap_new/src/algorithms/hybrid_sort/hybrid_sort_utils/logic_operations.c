/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:10:16 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/31 23:33:16 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Exchanges the first two elements of an array.
 *
 * This function swaps the values at array[0] and array[1]
 * if the array contains at least two elements.
 *
 * Out-of-scope commentary:
 * Swap is a basic operation in many sorting algorithms. It
 * is used to quickly correct local disorder, and forms the
 * basis for more complex sorting routines.
 */
void	swap(int *array, int size)
{
	int	temp;

	if (size < 2)
		return ;
	temp = array[0];
	array[0] = array[1];
	array[1] = temp;
}

/* Transfers the first element from the source array
 * to the destination array.
 *
 * The function moves the element at src[0] to the beginning
 * of dest, shifting existing elements in dest rightward.
 * The sizes of both arrays are updated accordingly.
 *
 * Out-of-scope commentary:
 * In stack-based algorithms, push is crucial to move data
 * between structures. It allows elements to be repositioned
 * and is key to methods that require temporary storage.
 */
void	push(int *src, int *src_size, int *dest, int *dest_size)
{
	int	i;

	i = *dest_size;
	if (*src_size == 0)
		return ;
	while (i > 0)
	{
		dest[i] = dest[i - 1];
		i--;
	}
	dest[0] = src[0];
	i = 0;
	while (i < *src_size - 1)
	{
		src[i] = src[i + 1];
		i++;
	}
	(*src_size)--;
	(*dest_size)++;
}

/* Rotates an array to the left.
 *
 * This function moves the first element to the end of the array,
 * shifting all other elements one position to the left.
 *
 * Out-of-scope commentary:
 * Rotation is a common operation in algorithms dealing with
 * cyclic data. It helps in repositioning elements without
 * changing the overall order, which is useful in sorting and
 * buffering techniques. */
void	rotate(int *array, int size)
{
	int	i;
	int	temp;

	i = 0;
	if (size < 2)
		return ;
	temp = array[0];
	while (i < size - 1)
	{
		array[i] = array[i + 1];
		i++;
	}
	array[size - 1] = temp;
}

/* Rotates an array to the right.
 *
 * This function moves the last element to the front of the array,
 * shifting all other elements one position to the right.
 *
 * Out-of-scope commentary:
 * Reverse rotation is the inverse of rotation. It is useful
 * when the last element must be brought to the front quickly,
 * and is an essential operation in many algorithms that manage
 * cyclic or circular data structures. */
void	reverse_rotate(int *array, int size)
{
	int	i;
	int	temp;

	i = size - 1;
	if (size < 2)
		return ;
	temp = array[size - 1];
	while (i > 0)
	{
		array[i] = array[i - 1];
		i--;
	}
	array[0] = temp;
}
