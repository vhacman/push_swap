/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:02:02 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/27 10:02:02 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Processes leading spaces and sign.
 *
 * This function advances the index *i in the input string by skipping
 * whitespace characters (space and control characters between 9 and 13).
 * It then checks for a '+' or '-' sign and adjusts the sign accordingly.
 * Separating the whitespace and sign handling into its own function
 * improves modularity. 
 * 
 * *i is used as a pointer to an index variable so that the function can 
 * update the index value outside its own scope. This allows the function to 
 * remember how far it has processed the string (skipping spaces and handling 
 * the sign).*/
static int	ft_handle_sign_and_spaces(const char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

/* Converts numeric characters in a string into a long integer.
 *
 * This function reads characters from the string starting at the index
 * pointed by *i, and accumulates their numeric value into a long.
 * It stops when a non-digit character is encountered.
 *
 * The function also checks for potential overflow:
 *   - If an overflow is detected and the sign is positive,
 *     it returns LONG_MAX.
 *   - If negative, it returns LONG_MIN.
 * 
 * This modular approach to number conversion separates the actual
 * digit accumulation logic from the initial parsing of sign and spaces.
 * It allows the conversion process to be reused in other contexts
 * while handling overflow in a consistent manner.*/
/* if (result > (LONG_MAX - (str[*i] - '0') / 10))
		 * Check for overflow before adding the new digit.
		 * The condition attempts to detect when multiplying by 10
		 * and adding the digit would exceed LONG_MAX.
 */
static long	ft_calculate_number(const char *str, int *i, int sign)
{
	long	result;

	result = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if (result > (LONG_MAX - (str[*i] - '0') / 10))
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

/*
 * Converts a string to a long integer.
 *
 * This function processes the input string by first handling any leading
 * spaces and the sign via ft_handle_sign_and_spaces(), then calculates the
 * numeric value using ft_calculate_number(). The final result is returned
 * with the proper sign applied.
 *
 * This custom implementation of atol separates the concerns of sign and
 * whitespace handling from the numerical conversion.*/
long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = ft_handle_sign_and_spaces(str, &i);
	result = ft_calculate_number(str, &i, sign);
	return (result * sign);
}
