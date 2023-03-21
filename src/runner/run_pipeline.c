/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:52:30 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/21 14:29:28 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include <wait.h>//wait, waitpid
#include <errno.h>
#include <stdlib.h>//exit
#include <unistd.h>//fork
#include <stdio.h>

#include "libft.h"
#include "minishell/cmd.h"
#include "minishell/utils.h"
#include "minishell/envlst.h"

static void	loc_apply_pipes_or_exit(int fds[2]);
static void	loc_run_piped_cmd_and_exit(t_cmdlst *cmd, t_envlst **penvlst,
				int res, t_cmdtree **pcmdtree);
static int	loc_wait_pipeline(int pid);

int	my_run_pipeline(t_cmdlst *pipeline, t_envlst **penvlst, int res,
	t_cmdtree **pcmdtree)
{
	int	fds_tmp[2];
	int	fds[2];
	int	pid;

	fds[0] = STDIN_FILENO;
	fds[1] = STDOUT_FILENO;
	while (pipeline != NULL)
	{
		fds_tmp[1] = STDOUT_FILENO;
		if (pipeline->next != NULL)
			pipe(fds_tmp);
		if (fds[1] != STDOUT_FILENO)
			close(fds[1]);
		fds[1] = fds_tmp[1];
		pid = fork();
		if (pid == 0)
			loc_apply_pipes_or_exit(fds);
		if (pid == 0)
			loc_run_piped_cmd_and_exit(pipeline, penvlst, res, pcmdtree);
		pipeline = pipeline->next;
		if (fds[0] != STDIN_FILENO)
			close(fds[0]);
		fds[0] = fds_tmp[0];
	}
	return (loc_wait_pipeline(pid));
}

static void	loc_apply_pipes_or_exit(int fds[2])
{
	if (dup2(fds[0], STDIN_FILENO) == -1)
	{
		perror("minishell: Couldn't redirect stdin");
		my_close_all();
		exit(1);
	}
	if (dup2(fds[1], STDOUT_FILENO) == -1)
	{
		perror("minishell: Couldn't redirect stdout");
		my_close_all();
		exit(1);
	}
	my_close_all();
}

static int	loc_wait_pipeline(int pid)
{
	int	res;

	res = my_waitpid(pid);
	my_waitall();
	return (res);
}

static void	loc_run_piped_cmd_and_exit(t_cmdlst *cmd, t_envlst **penvlst,
				int res, t_cmdtree **pcmdtree)
{
	res = my_run_cmd(cmd, penvlst, res, pcmdtree);
	my_cmdtree_del(pcmdtree);
	my_envlst_del(penvlst);
	my_exit_or_raise(res);
}
