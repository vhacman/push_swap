/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:38:04 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/27 11:38:04 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted_and_empty(t_stack_node *stack_a, t_stack_node *stack_b)
{
    t_stack_node    *curr;

    if (stack_b != NULL)
        return (0);
    curr = stack_a;
    while (curr && curr->next)
    {
        if (curr->value > curr->next->value)
            return (0);
        curr = curr->next;
    }
    return (1);
}
