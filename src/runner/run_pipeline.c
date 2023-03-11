/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:52:30 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/10 16:10:25 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/pipelst.h"
#include "minishell/runner.h"

#include <wait.h>//wait, waitpid
#include <errno.h>
#include <stdlib.h>//exit
#include <unistd.h>//fork

#include "minishell/cmd.h"
#include "minishell/envlst.h"

static int	loc_redirect_piped_cmd(t_pipelst *pipes, int idx);
static int	loc_wait_pipeline(int pid);
static int	loc_run_piped_cmd(t_cmdlst *cmd, t_envlst **penvlst, int res,
				t_cmdtree **pcmdtree);

int	my_run_pipeline(t_cmdlst *pipeline, t_envlst **penvlst, int res,
	t_cmdtree **pcmdtree)
{
	int			pid;
	t_pipelst	*pipes;
	int			i;

	errno = 0;
	pipes = my_pipelst_init(my_cmdlst_size(pipeline) - 1);
	if (pipes == NULL)
		return (errno);
	i = 0;
	while (pipeline != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			loc_redirect_piped_cmd(pipes, i);
			my_pipelst_del(&pipes);
			if (errno != 0)
				exit(errno);
			exit(loc_run_piped_cmd(pipeline, penvlst, res, pcmdtree));
		}
		i++;
		pipeline = pipeline->next;
	}
	my_pipelst_del(&pipes);
	return (loc_wait_pipeline(pid));
}

static int	loc_redirect_piped_cmd(t_pipelst *pipes, int idx)
{
	t_pipelst	*left;
	t_pipelst	*right;
	int			res;

	left = my_pipelst_at(pipes, idx - 1);
	right = my_pipelst_at(pipes, idx);
	res = 0;
	if (left != NULL)
		res = dup2(left->fd[0], 0);
	if (right != NULL && res != -1)
		res = dup2(right->fd[1], 1);
	return (res);
}

static int	loc_wait_pipeline(int pid)
{
	int	res;

	res = my_waitpid(pid);
	my_waitall();
	return (res);
}

static int	loc_run_piped_cmd(t_cmdlst *cmd, t_envlst **penvlst, int res,
	t_cmdtree **pcmdtree)
{
	res = my_run_cmd(cmd, penvlst, res, pcmdtree);
	close(0);
	close(1);
	close(2);
	my_cmdtree_del(pcmdtree);
	my_envlst_del(penvlst);
	exit(res);
}
