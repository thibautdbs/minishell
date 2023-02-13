/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:32:29 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/13 17:51:56 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include <wait.h>//waitpid
#include <stdlib.h>//exit
#include <unistd.h>//fork
#include <limits.h>//CHAR_BIT

#include "minishell/cmd.h"
#include "minishell/envlst.h"

static int	loc_run_simple_cmd(t_cmdlst *cmd, t_envlst **penvlst, int res,
				t_cmdtree **pcmdtree);
static int	loc_run_subshell(t_cmdlst *cmd, t_envlst **penvlst, int res,
				t_cmdtree **pcmdtree);

int	my_run_cmd(t_cmdlst *cmd, t_envlst **penvlst, int res, t_cmdtree **pcmdtree)
{
	if (cmd->type == SIMPLECMD)
		return (loc_run_simple_cmd(cmd, penvlst, res, pcmdtree));
	return (loc_run_subshell(cmd, penvlst, res, pcmdtree));
}

//TODO
static int	loc_run_simple_cmd(t_cmdlst *cmd, t_envlst **penvlst, int res,
				t_cmdtree **pcmdtree);

//TODO
static int	loc_run_subshell(t_cmdlst *cmd, t_envlst **penvlst, int res,
	t_cmdtree **pcmdtree)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		res = my_redirect(cmd->redirs);
		if (res == 0)
			exit(my_run(cmd->subcmd, penvlst, res, pcmdtree));
		my_cmdtree_del(pcmdtree);
		my_envlst_del(penvlst);
		exit(res);
	}
	waitpid(pid, &res, 0);
	return (res >> CHAR_BIT);
}
