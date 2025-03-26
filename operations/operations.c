/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:10:16 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/26 22:10:16 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(int *array, int size)
{
    int temp;
    if (size < 2)
        return ;
    temp = array[0];
    array[0] = array[1];
    array[1] = temp;
}

void    push(int *src, int *src_size, int *dest, int *dest_size)
{
    int i;

    i = *dest_size; //dimensione attuale di dest
    if(*src_size == 0)
        return ;
    while (i > 0)
    {
        dest[i] = dest[i - 1]; //scorrendo all'indietro copio dest[i-1]in dest[i] per far spazio per il nuovo elemento
        i--;
    }
    //ho creato spazio e posso spostare il primo elemento di src in dest[0]
    dest[0] = src[0];
    i = 0;
    while (i > *src_size - 1) //sposto di una posizione a sinistra per riempire la posizione lasciata vuota dall'elemento spostato
    {
        src[i] = src[i + 1]; //In questo modo, l'elemento in posizione 0 (già trasferito in dest) viene "rimosso" e gli altri elementi vengono riorganizzati.
        i++;
    }
    (*src_size)--; //un elemento è stato rimosso - aggiorno
    (*dest_size)++; //un elemento è stato aggiunto -aggiorno
}

void    rotate(int *array, int size)
{
    int i;
    int temp;

    i = 0;
    if (size < 2)
        return (NULL);
    temp = array[0];
    while (i < size - 1)
    {
        array[i] = array[i + 1];
        i++;
    }
    array[size - 1] = temp;
}

void    reverse_rotate(int *array, int size)
{
    int i;
    int temp;

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
