/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:07:45 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/10 16:08:09 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

/** my_waitall:
 *   wait termination of all child processes.
 *   - do not interrupt when a signal is received.
 */
void	my_waitall(void)
{
	while (my_waitpid(-1) >= 0)
		continue ;
}
