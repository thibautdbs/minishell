/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:01:02 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/13 23:52:53 by tdubois          ###   ########.fr       */
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

static int	loc_run_or(t_cmdtree *cmd, t_envlst **penvlst, int res,
				t_cmdtree **cmdtree);
static int	loc_run_and(t_cmdtree *cmd, t_envlst **penvlst, int res,
				t_cmdtree **cmdtree);

static bool	loc_is_parent_shell(t_cmdlst *pipeline, t_cmdtree *cmdtree);

extern bool	g_sigint_received;

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
	if (res == -(128 + SIGQUIT)
		&& loc_is_parent_shell(cmd->pipeline, *pcmdtree))
		ft_putendl_fd("Quit (core dumped)", STDERR_FILENO);
	return (res);
}

static int	loc_run_or(t_cmdtree *cmd, t_envlst **penvlst, int res,
	t_cmdtree **pcmdtree)
{
	res = my_run(cmd->left, penvlst, res, pcmdtree);
	if (g_sigint_received)
	{
		if (res == -(128 + SIGINT))
			return (res);
		g_sigint_received = false;
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
