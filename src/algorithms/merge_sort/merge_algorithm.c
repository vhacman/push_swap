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

/* Merges two sorted subarrays into a temporary array.
 *- left_index: Traverses the left subarray (from limits.left to limits.mid).
 *- right_index: Traverses the right subarray
 		(from limits.mid+1 to limits.right).
 *- merged_index: Tracks the current position in the temporary array.
 *
 * It compares elements from both subarrays and copies the smaller one 
 * into arr_temp until one subarray is exhausted, then copies 
 * any remaining elements.*/
static void	merge_arrays(int *array, int *arr_temp, t_range_limits limits)
{
	int	left_index;
	int	right_index;
	int	merged_index;

	left_index = limits.left;
	right_index = limits.mid + 1;
	merged_index = limits.left;
	while (left_index <= limits.mid && right_index <= limits.right)
	{
		if (array[left_index] <= array[right_index])
			arr_temp[merged_index++] = array[left_index++];
		else
			arr_temp[merged_index++] = array[right_index++];
	}
	while (left_index <= limits.mid)
		arr_temp[merged_index++] = array[left_index++];
	while (right_index <= limits.right)
		arr_temp[merged_index++] = array[right_index++];
}

/* Copies a segment from the temporary array
 * back to the original array.
 *
 * This function iterates over the indices from limits.left to 
 * limits.right (inclusive) and copies each element from arr_temp 
 * into the original array.
 *
 * In the merge sort algorithm, after merging sorted segments into 
 * a temporary array, it is necessary to update the original array 
 * so that it reflects the newly sorted order. This helper function 
 * ensures that only the specified segment is overwritten.*/
static void	copy_temp_to_array(int *array, int *arr_temp,
										t_range_limits limits)
{
	int	i;

	i = limits.left;
	while (i <= limits.right)
	{
		array[i] = arr_temp[i];
		i++;
	}
}

/* Recursively sorts a segment of an array.
 *
 * This function uses the classic divide-and-conquer strategy of merge sort.
 * It splits the array segment defined by limits.left and limits.right into
 * two halves by calculating the midpoint. It then recursively sorts the left
 * half and the right half. After both halves are sorted, it merges them using
 * merge_arrays and copies the sorted segment back to the original array via
 * copy_temp_to_array.
 *
 * This implementation of merge sort exemplifies the power of recursion in
 * breaking down a large problem into smaller, manageable subproblems. By
 * repeatedly dividing the array into two halves, the function ensures that
 * each recursive call handles a smaller portion of the data until reaching
 * the base case (a segment with one or zero elements). The merge step then
 * efficiently combines these sorted segments, maintaining the overall order.
 * This approach, with its O(n log n) complexity, is widely used due to its
 * predictable performance even on large datasets.*/
static void	merge_sort_recursive(int *array, int *arr_temp,
								t_range_limits limits)
{
	int				mid;
	t_range_limits	left;
	t_range_limits	right;

	if (limits.left < limits.right)
	{
		mid = limits.left + (limits.right - limits.left) / 2;
		left = (t_range_limits){limits.left, 0, mid};
		right = (t_range_limits){mid + 1, 0, limits.right};
		merge_sort_recursive(array, arr_temp, left);
		merge_sort_recursive(array, arr_temp, right);
		limits.mid = mid;
		merge_arrays(array, arr_temp, limits);
		copy_temp_to_array(array, arr_temp, limits);
	}
}

/*
** merge_sort:
** Entry point for the merge sort algorithm.
** Allocates a temporary array used during the merge process,
** initializes limits to cover the full array, and starts the recursive sorting.
** Frees the temporary buffer after sorting is complete.
** If memory allocation fails, the function exits silently.
*/
void	merge_sort(int *array, int size)
{
	int				*arr_temp;
	t_range_limits	limits;

	arr_temp = malloc(sizeof(int) * size);
	if (!arr_temp)
		return ;
	limits.left = 0;
	limits.right = size - 1;
	merge_sort_recursive(array, arr_temp, limits);
	free(arr_temp);
}
