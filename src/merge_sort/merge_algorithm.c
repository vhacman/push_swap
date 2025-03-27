/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:13:12 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/26 23:13:12 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** merge_arrays:
** Merges two sorted subarrays->from 'left' to 'mid' and from 'mid+1' to 'right'
** into a temporary array 'arr_temp', preserving sorted order.
** Does not modify the original 'array' directly; instead, it builds the merged
** result in 'arr_temp'.
*/
static void	merge_arrays(int *array, int *arr_temp, t_range_limits limits)
{
	int	i;
	int	j;
	int	k;

	i = limits.left;
	j = limits.mid + 1;
	k = limits.left;
	while (i <= limits.mid && j <= limits.right)
	{
		if (array[i] <= array[j])
			arr_temp[k++] = array[i++];
		else
			arr_temp[k++] = array[j++];
	}
	while (i <= limits.mid)
		arr_temp[k++] = array[i++];
	while (j <= limits.right)
		arr_temp[k++] = array[j++];
}

/*
** copy_arr_arr_temp_to_array:
** Copies the sorted segment from the temporary array 'arr_arr_temp'
** back to the original array 'array', only between the given indices
** 'left' and 'right'. This reflects the sorted order permanently in
** the original input.
*/
static void	copy_arr_arr_temp_to_array(int *array, int *arr_arr_temp,
										int left, int right)
{
	int	i;

	i = left;
	while (i <= right)
	{
		array[i] = arr_arr_temp[i];
		i++;
	}
}

/*
** merge_sort_recursive:
** Recursive implementation of the Merge Sort algorithm.
** It divides the array into two halves, recursively sorts each half,
** then merges the sorted halves into a temporary array.
** Finally, it copies the result back into the original array.
*/
static void	merge_sort_recursive(int *array, int *arr_temp,
								t_range_limits bounds)
{
	int	mid;

	if (bounds.left < bounds.right)
	{
		mid = bounds.left + (bounds.right - bounds.left) / 2;
		merge_sort_recursive(array, arr_temp,
			(t_range_limits){bounds.left, 0, mid});
		merge_sort_recursive(array, arr_temp,
			(t_range_limits){mid + 1, 0, bounds.right});
		bounds.mid = mid;
		merge_arrays(array, arr_temp, bounds);
		copy_arr_arr_temp_to_array(array, arr_temp, bounds.left, bounds.right);
	}
}

/*
** merge_sort:
** Entry point for the merge sort algorithm.
** Allocates a temporary array used during the merge process,
** initializes bounds to cover the full array, and starts the recursive sorting.
** Frees the temporary buffer after sorting is complete.
** If memory allocation fails, the function exits silently.
*/
void	merge_sort(int *array, int size)
{
	int				*arr_temp;
	t_range_limits	bounds;

	arr_temp = malloc(sizeof(int) * size);
	if (!arr_temp)
		return ;
	bounds.left = 0;
	bounds.right = size - 1;
	bounds.mid = 0;
	merge_sort_recursive(array, arr_temp, bounds);
	free(arr_temp);
}
