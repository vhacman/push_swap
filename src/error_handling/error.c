/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:29:49 by vhacman           #+#    #+#             */
/*   Updated: 2025/03/31 17:29:49 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Print an error message and exit the program.
 *
 * This function writes "Error\n" to the standard error output 
 * (file descriptor 2) and terminates the program with a failure 
 * status. It centralizes error handling for consistency.
 *
 * Centralizing error handling in a single function simplifies 
 * maintenance and debugging, as all error exits produce the same 
 * message and exit status.*/
void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
