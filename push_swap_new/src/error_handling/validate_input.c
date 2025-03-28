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

static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	is_number(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicates(t_stack_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static void	process_token(char *token, t_stack_node **stack)
{
	long	num;

	if (!is_number(token))
		exit_error();
	num = ft_atol(token);
	if (num > INT_MAX || num < INT_MIN)
		exit_error();
	if (has_duplicates(*stack, (int)num))
		exit_error();
	create_stack(stack, (int)num);
}

void	validate_input(char **av, int ac, t_stack_node **stack)
{
	int		i;
	int		j;
	char	**tokens;

	i = 1;
	while (i < ac)
	{
		tokens = ft_split(av[i], ' ');
		if (!tokens)
			exit_error();
		j = 0;
		while (tokens[j])
		{
			process_token(tokens[j], stack);
			j++;
		}
		free_split(tokens);
		i++;
	}
}
