/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:12:55 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/27 10:12:55 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicates(t_stack_node **stack, int value)
{
	while (*stack)
	{
		if ((*stack)->value == value)
			return (1);
		*stack = (*stack)->next;
	}
	return (0);
}

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	validate_input(char **av, int ac, t_stack_node **stack)
{
	int		i;
	long	num;

	i = 1;
	while (i < ac)
	{
		if (!is_number(av[i]))
			exit_error();
		num = ft_atol(av[i]);
		if (num > INT_MAX || num < INT_MIN)
			exit_error();
		if (has_duplicates(stack, (int)num))
			exit_error();
		create_stack(stack, (int)num);
		i++;
	}
}
