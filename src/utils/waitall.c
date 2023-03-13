/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:07:45 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/13 13:10:12 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/utils.h"

/** my_waitall:
 *   wait termination of all child processes.
 *   - do not interrupt when a signal is received.
 */
void	my_waitall(void)
{
	while (my_waitpid(-1) != -1)
		continue ;
}
