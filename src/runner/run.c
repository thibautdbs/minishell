/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:01:02 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/14 16:52:40 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>
#include <stdlib.h>

#include "libft.h"
#include "minishell/cmd.h"
#include "minishell/envlst.h"
#include "minishell/utils.h"

static int	loc_run_or(t_cmdtree *cmd, t_envlst **penvlst, int res,
				t_cmdtree **cmdtree);
static int	loc_run_and(t_cmdtree *cmd, t_envlst **penvlst, int res,
				t_cmdtree **cmdtree);

static bool	loc_is_parent_shell(t_cmdlst *pipeline, t_cmdtree *cmdtree);

extern t_globals	g_globals;

int	my_run(t_cmdtree *cmd, t_envlst **penvlst, int res, t_cmdtree **pcmdtree)
{
	if (cmd == NULL)
		return (res);
	if (cmd->type == OR)
		return (loc_run_or(cmd, penvlst, res, pcmdtree));
	if (cmd->type == AND)
		return (loc_run_and(cmd, penvlst, res, pcmdtree));
	if (my_cmdlst_size(cmd->pipeline) == 1)
		res = my_run_cmd(cmd->pipeline, penvlst, res, pcmdtree);
	else
		res = my_run_pipeline(cmd->pipeline, penvlst, res, pcmdtree);
	if (g_globals.did_exit == true)
	{
		if (loc_is_parent_shell(cmd->pipeline, *pcmdtree))
			ft_putendl_fd("exit", STDOUT_FILENO);
		my_cmdtree_del(pcmdtree);
		my_envlst_del(penvlst);
		my_close_all();
		exit(res);
	}
	if (res == -(128 + SIGQUIT)
		&& loc_is_parent_shell(cmd->pipeline, *pcmdtree))
		ft_putstr_fd("Quit (core dumped)", STDERR_FILENO);
	return (res);
}

static int	loc_run_or(t_cmdtree *cmd, t_envlst **penvlst, int res,
	t_cmdtree **pcmdtree)
{
	res = my_run(cmd->left, penvlst, res, pcmdtree);
	if (g_globals.did_receive_sigint == true)
	{
		if (res == -(128 + SIGINT))
			return (res);
		g_globals.did_receive_sigint = false;
	}
	if (res == EXIT_SUCCESS)
		return (res);
	return (my_run(cmd->right, penvlst, res, pcmdtree));
}

static int	loc_run_and(t_cmdtree *cmd, t_envlst **penvlst, int res,
	t_cmdtree **pcmdtree)
{
	res = my_run(cmd->left, penvlst, res, pcmdtree);
	if (res != EXIT_SUCCESS)
		return (res);
	return (my_run(cmd->right, penvlst, res, pcmdtree));
}

static bool	loc_is_parent_shell(t_cmdlst *pipeline, t_cmdtree *cmdtree)
{
	if (cmdtree->type == PIPELINE)
		return (cmdtree->pipeline == pipeline);
	if (loc_is_parent_shell(pipeline, cmdtree->left))
		return (true);
	return (loc_is_parent_shell(pipeline, cmdtree->right));
}
