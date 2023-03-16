/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raise.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:13:17 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/13 23:15:44 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/utils.h"

#include <signal.h>

int	my_raise(int signum)
{
	int	pid;

	pid = my_getpid();
	if (pid <= 0)
		return (-1);
	return (kill(pid, signum));
}
