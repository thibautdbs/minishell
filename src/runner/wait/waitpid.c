/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:05:23 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/11 03:59:11 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include <wait.h>
#include <errno.h>

/** my_waitpid:
 *   wait for termination of process denoted by `pid'.
 *   - do not abort when a signal is received.
 *   - on success, returns process exit status, or the number
 *     of the signal that caused termination.
 *   - on error (e.g. pid already terminated), returns -1.
 */
int	my_waitpid(int pid)
{
	int	wstatus;
	int	ret;

	while (1)
	{
		errno = 0;
		ret = waitpid(pid, &wstatus, 0);
		if (errno != EINTR)
			break ;
	}
	if (ret == -1)
		return (-1);
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	return (WTERMSIG(wstatus));
}
