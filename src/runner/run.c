/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:01:02 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/14 08:06:26 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include <wait.h>//waitpid
#include <stdlib.h>//exit
#include <unistd.h>//fork

#include "minishell/cmd.h"
#include "minishell/envlst.h"

static int	loc_run_or(t_cmdtree *cmd, t_envlst **penvlst, int res,
				t_cmdtree **cmdtree);
static int	loc_run_and(t_cmdtree *cmd, t_envlst **penvlst, int res,
				t_cmdtree **cmdtree);
static int	loc_run_pipeline(t_cmdlst *pipeline, t_envlst **penvlst, int res,
				t_cmdtree **pcmdtree);

int	my_run(t_cmdtree *cmd, t_envlst **penvlst, int res, t_cmdtree **pcmdtree)
{
	if (cmd == NULL)
		return (0);
	if (cmd->type == OR)
		return (loc_run_or(cmd, penvlst, res, pcmdtree));
	if (cmd->type == AND)
		return (loc_run_and(cmd, penvlst, res, pcmdtree));
	return (loc_run_pipeline(cmd->pipeline, penvlst, res, pcmdtree));
}

static int	loc_run_or(t_cmdtree *cmd, t_envlst **penvlst, int res,
	t_cmdtree **pcmdtree)
{
	res = my_run(cmd->left, penvlst, res, pcmdtree);
	if (res == 0)
		return (res);
	return (my_run(cmd->right, penvlst, res, pcmdtree));
}

static int	loc_run_and(t_cmdtree *cmd, t_envlst **penvlst, int res,
	t_cmdtree **pcmdtree)
{
	res = my_run(cmd->left, penvlst, res, pcmdtree);
	if (res != 0)
		return (res);
	return (my_run(cmd->right, penvlst, res, pcmdtree));
}

static int	loc_run_pipeline(t_cmdlst *pipeline, t_envlst **penvlst, int res,
	t_cmdtree **pcmdtree)
{
	int	pid;

	if (my_cmdlst_size(pipeline) == 1)
		return (my_run_cmd(pipeline, penvlst, res, pcmdtree));
	while (pipeline != NULL)
	{
		pid = fork();
		if (pid == 0)
			exit(my_run_cmd(pipeline, penvlst, res, pcmdtree));
		pipeline = pipeline->next;
	}
	waitpid(pid, &res, 0);
	while (wait(NULL) > 0)
		continue ;
	return (WEXITSTATUS(res));
}
