/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:48:55 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/27 09:48:55 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_target_info(t_target_info *info)
{
	info->node = NULL;
	info->cost.total_moves = INT_MAX;
}

//Restituisce il numero di mosse nevessarie per portare target in cima 
//allo stack scorrendo dall'alto verso il basso
//parte dalla cima dello stack e scende nodo per nodo fino a trovare target
//tiene vponto dei passi effettuati con dist.
int	distance_to_top(t_stack_node **stack, t_stack_node **target)
{
	int	dist;

	dist = 0;
	while (*stack && *stack != *target)
	{
		*stack = (*stack)->next;
		dist++;
	}
	return (dist);
}

//trova la posizione migliore in cui inserire un nodo con un 
//certo index nello stack B,rispettando l'ordine
//crescente degli indici. Scorre lo stack B nono per nodo
//calcola la differenza tra l'indice del nodo corrente in B e
//l'indice del nodo da inserirw
//se la diff è positiva(quindi il nodo B ha indic più alto) e 
//più piccola trovata finora, salva quella posizione
//restituisce la posizione migliore trovata.
int	find_target_position_b(t_stack_node **stack_b, int index)
{
	int	pos;
	int	best_diff;
	int	best_pos;
	int	diff;

	best_diff = 2147483647;
	while (*stack_b)
	{
		diff = (*stack_b)->index - index;
		if (diff > 0 && diff < best_diff)
		{
			best_diff = diff;
			best_pos = pos;
		}
		*stack_b = (*stack_b)->next;
		pos++;
	}
	return (best_pos);
}
