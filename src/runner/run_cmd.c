/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:13:51 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/21 15:35:03 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include <wait.h>//waitpid
#include <stdlib.h>//exit
#include <unistd.h>//fork, dup, dup2
#include <errno.h>

#include "minishell/cmd.h"
#include "minishell/envlst.h"
#include "minishell/builtin.h"
#include "minishell/wordlst.h"
#include "minishell/expand.h"

static int	loc_run_simple_cmd(t_cmdlst *cmd, t_envlst **penvlst, int res,
				t_cmdtree **pcmdtree);
static int	loc_run_builtin(t_cmdlst *cmd, t_envlst **penvlst, int res);
static int	loc_run_execve(t_cmdlst *cmd, t_envlst **penvlst, int res,
				t_cmdtree **pcmdtree);
static int	loc_run_subshell(t_cmdlst *cmd, t_envlst **penvlst, int res,
				t_cmdtree **pcmdtree);

int	my_run_cmd(t_cmdlst *cmd, t_envlst **penvlst, int res, t_cmdtree **pcmdtree)
{
	if (cmd->type == SIMPLECMD)
		return (loc_run_simple_cmd(cmd, penvlst, res, pcmdtree));
	return (loc_run_subshell(cmd, penvlst, res, pcmdtree));
}

static int	loc_run_simple_cmd(t_cmdlst *cmd, t_envlst **penvlst, int res,
	t_cmdtree **pcmdtree)
{
	errno = 0;
	my_expand_words(&cmd->words, *penvlst, res);
	if (errno != 0)
		return (errno);
	if (cmd->words != NULL && cmd->words->content != NULL
			&& my_is_builtin(cmd->words->content))
	{
		return (loc_run_builtin(cmd, penvlst, res));
	}
	return (loc_run_execve(cmd, penvlst, res, pcmdtree));
}

static int	loc_run_builtin(t_cmdlst *cmd, t_envlst **penvlst, int res)
{
	int const	stdin = dup(0);
	int const	stdout = dup(1);

	res = my_redirect(cmd->redirs, *penvlst, res);
	if (res == 0)
		res = my_builtin(cmd->words, penvlst, res);
	dup2(stdin, 0);
	dup2(stdout, 1);
	close(stdin);
	close(stdout);
	return (res);
}

static int	loc_run_execve(t_cmdlst *cmd, t_envlst **penvlst, int res,
	t_cmdtree **pcmdtree)
{
	int			pid;
	t_wordlst	*words;

	pid = fork();
	if (pid == 0)
	{
		words = cmd->words;
		cmd->words = NULL;
		res = my_redirect(cmd->redirs, *penvlst, res);
		my_cmdtree_del(pcmdtree);
		if (res == 0)
			exit(my_execve(words, *penvlst));
		close(0);
		close(1);
		my_wordlst_del(&words);
		my_envlst_del(penvlst);
		exit(res);
	}
	waitpid(pid, &res, 0);
	return (WEXITSTATUS(res));
}

static int	loc_run_subshell(t_cmdlst *cmd, t_envlst **penvlst, int res,
	t_cmdtree **pcmdtree)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		res = my_redirect(cmd->redirs, *penvlst, res);
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
