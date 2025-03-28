/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:10:16 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/28 17:21:58 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *array, int size)
{
	int	temp;

	if (size < 2)
		return ;
	temp = array[0];
	array[0] = array[1];
	array[1] = temp;
}

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
