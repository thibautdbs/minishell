/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:32:29 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/14 13:51:12 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include <wait.h>//waitpid
#include <stdlib.h>//exit
#include <unistd.h>//fork, dup, dup2
#include <errno.h>

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
static int	loc_run_builtin(t_cmdlst *cmd, t_envlst **penvlst, int res,
	t_cmdtree **pcmdtree)
{
	int const	stdin = dup(0);
	int const	stdout = dup(1);

	res = my_redirect(cmd->redirs, res);
	if (res == 0)
	{
		//blah my_builtin(cmd->words, penvlst);
	}
	dup2(stdin, 0);
	dup2(stdout, 1);
	close(stdin);
	close(stdout);
	return (res);
}

static int	loc_run_exec(t_cmdlst *cmd, t_envlst **penvlst, int res,
	t_cmdtree **pcmdtree)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		res = my_redirect(cmd->redirs);
		if (res == 0)
		{
			res = my_exec(cmd->words, *penvlst);
			close(0);
			close(1);
		}
		my_cmdtree_del(pcmdtree);
		my_envlst_del(penvlst);
		exit(res);
	}
	waitpid(pid, &res, 0);
	return (WEXITSTATUS(res));
}

static int	loc_run_simple_cmd(t_cmdlst *cmd, t_envlst **penvlst, int res,
	t_cmdtree **pcmdtree)
{
	errno = 0;
	my_expand_args(cmd, *penvlst, res);
	if (errno != 0)
		return (errno);
	if (my_is_builtin(cmd->words))
		return (my_run_builtin(cmd, penvlst, res, pcmdtree));
	return (my_run_exec(cmd, penvlst, res, pcmdtree));
}

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
		{
			res = my_run(cmd->subcmd, penvlst, res, pcmdtree);
			close(0);
			close(1);
		}
		my_cmdtree_del(pcmdtree);
		my_envlst_del(penvlst);
		exit(res);
	}
	waitpid(pid, &res, 0);
	return (WEXITSTATUS(res));
}
