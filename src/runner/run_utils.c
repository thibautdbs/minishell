/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:56:41 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/14 11:52:49 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/pipelst.h"

#include <unistd.h> //close
#include <wait.h> //wait

int	my_dup_pipe(t_pipelst *pipes, int index)
{
	int	res;

	res = 0;
	if (index != 0)
		res = dup2(*(my_pipelst_at(pipes, index - 1)->out), 0);
	if (res == 0)
		res = dup2(*(my_pipelst_at(pipes, index)->in), 1);
	return (res);
}

void	my_close_stdfds(void)
{
	close(0);
	close(1);
}

void	my_wait_children(void)
{
	while (wait(NULL) > 0)
		continue ;
}
