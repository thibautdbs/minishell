/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:05:04 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/11 16:40:10 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/utils.h"

#include <signal.h>
#include <stddef.h>

/**	my_signal:
 *   signal fct look-a-like that uses recommended sigaction function.
 *   see (man signal).
 */
int	my_signal(int signum, void (handler)(int signum))
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	return (sigaction(signum, &sa, NULL));
}
