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

/* Process a single input token and add it to the stack.
 *
 * This function converts a token (a string) into a number and performs
 * several checks before adding it to the stack:
 *   1. Verifies the token is a valid number using is_number().
 *   2. Converts the token to a long integer using ft_atol().
 *   3. Checks that the number is within the range of an int.
 *   4. Checks for duplicates in the current stack.
 *   5. Adds the number to the stack using create_stack().
 *
 * This helper ensures that only valid, unique numbers within the proper
 * range are added to the stack. It protects the sorting algorithm from
 * corrupt or invalid data by terminating the program if any check fails.
 */
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

/*Validates and processes command-line input.
 *
 * This function iterates over each command-line argument (except the
 * program name), splits the argument into tokens using spaces as
 * delimiters, and then processes each token. Each token is converted
 * to an integer and added to the stack. If any error occurs (e.g.,
 * invalid token, empty token array), the program terminates with an
 * error.
 *This input validation step is critical for ensuring that only
 * proper numeric values are processed by the sorting routines.
 * It prevents the introduction of duplicates and non-numeric
 * characters into the stack, thereby maintaining the integrity
 * of the data before sorting begins.*/
void	validate_input(char **av, int ac, t_stack_node **stack)
{
	int		i;
	int		j;
	char	**tokens;

	i = 1;
	while (i < ac)
	{
		tokens = ft_split(av[i], ' ');
		if (!tokens || !tokens[0])
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
