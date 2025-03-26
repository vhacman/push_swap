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
** Fonde due sotto-array ordinati (da 'left' a 'mid' e da 'mid+1' a 'right')
** in un array temporaneo, mantenendo l'ordine crescente.
** Non modifica direttamente l'array originale, ma costruisce una versione ordinata
** nell'array temporaneo 'arr_temp'.
*/
static void merge_arrays(int *array, int *arr_temp, int left, int mid, int right)
{
	int i; //indice per iterare sul sub_array sx (da left a mid)
	int j; //indice per iterare sul sub_array dx (mid +1 a right)
	int k; //indice per posizionare gli elementi ordinati in arr_temp

	i = left;
	j = mid + 1;
	k = left; //posizione corrente nell'array temporaneo
	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			arr_temp[k++] = array[i++];
		else
			arr_temp[k++] = array[j++];
	}
	while (i <= mid)
		arr_temp[k++] = array[i++];
	while (j <= right)
		arr_temp[k++] = array[j++];
}

/*
** copy_arr_arr_temp_to_array:
** Copia i valori ordinati dall'array temporaneo 'arr_arr_temp' all'array originale 'array',
** limitandosi alla porzione compresa tra gli indici 'left' e 'right'.
** Serve a riflettere nell'array di partenza l'effettivo ordinamento calcolato.
*/
static void	copy_arr_arr_temp_to_array(int *array, int *arr_arr_temp, int left, int right)
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
** Implementa ricorsivamente l'algoritmo di Merge Sort.
** Divide l'array in due metà, ordina ciascuna ricorsivamente,
** poi le fonde con 'merge_arrays' e copia il risultato ordinato nell'array originale.
*/
static void merge_sort_recursive(int *array, int *arr_arr_temp, int left, int right)
{
	int mid;
      //se c'è almeno un elemento da ordinare, quindi se ci sono almeno due elementi
	if (left < right)
	{
		//Calcola il mid evitando l'overflow: usa left + (right - left) / 2 invece di (left + right) / 2
		mid = left + (right - left) / 2;
		merge_sort_recursive(array, arr_arr_temp, left, mid);
		merge_sort_recursive(array, arr_arr_temp, mid + 1, right);
		merge_arrays(array, arr_arr_temp, left, mid, right);
		copy_arr_arr_temp_to_array(array, arr_arr_temp, left, right);
	}
}

/*
** merge_sort:
** Funzione di avvio per l'algoritmo Merge Sort.
** Alloca un array temporaneo e chiama la funzione ricorsiva per ordinare l'array.
** Libera la memoria temporanea alla fine del processo.
** Se malloc fallisce, non fa nulla.
*/
void    merge_sort(int *array, int size)
{
	int *arr_temp;

	arr_temp = malloc(sizeof(int) * size);
	if (!arr_temp)
		return ;
	merge_sort_recursive(array, arr_temp, 0, size - 1);
	free (arr_temp);
}
