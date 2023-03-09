/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:13:51 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/09 17:59:56 by tdubois          ###   ########.fr       */
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

static int	loc_run_execve(t_cmdlst *cmd, t_envlst **penvlst,
				t_cmdtree **pcmdtree);

static int	loc_run_subshell(t_cmdlst *cmd, t_envlst **penvlst, int res,
				t_cmdtree **pcmdtree);

int	my_run_cmd(t_cmdlst *cmd, t_envlst **penvlst, int res, t_cmdtree **pcmdtree)
{
	int			new_res;
	int const	stdin = dup(0);
	int const	stdout = dup(1);

	new_res = my_redirect(cmd->redirs, *penvlst, res);
	if (new_res == 0)
	{
		if (cmd->type == SIMPLECMD)
			new_res = loc_run_simple_cmd(cmd, penvlst, res, pcmdtree);
		else
			new_res = loc_run_subshell(cmd, penvlst, res, pcmdtree);
	}
	dup2(stdin, 0);
	dup2(stdout, 1);
	close(stdin);
	close(stdout);
	return (new_res);
}

static int	loc_run_simple_cmd(t_cmdlst *cmd, t_envlst **penvlst, int res,
	t_cmdtree **pcmdtree)
{
	errno = 0;
	my_expand_words(&cmd->words, *penvlst, res);
	if (errno != 0)
		return (errno);
	if (cmd->words == NULL || cmd->words->content == NULL)
		return (EXIT_SUCCESS);
	if (my_is_builtin(cmd->words->content))
		return (my_builtin(cmd->words, penvlst, res));
	return (loc_run_execve(cmd, penvlst, pcmdtree));
}

static int	loc_run_execve(t_cmdlst *cmd, t_envlst **penvlst,
				t_cmdtree **pcmdtree)
{
	int			pid;
	int			wstatus;
	t_wordlst	*words;

	pid = fork();
	if (pid == 0)
	{
		words = cmd->words;
		cmd->words = NULL;
		my_cmdtree_del(pcmdtree);
		exit(my_execve(words, *penvlst));
	}
	waitpid(pid, &wstatus, 0);
	return (WEXITSTATUS(wstatus));
}

static int	loc_run_subshell(t_cmdlst *cmd, t_envlst **penvlst, int res,
	t_cmdtree **pcmdtree)
{
	int	pid;
	int	wstatus;

	pid = fork();
	if (pid == 0)
	{
		res = my_run(cmd->subcmd, penvlst, res, pcmdtree);
		my_cmdtree_del(pcmdtree);
		my_envlst_del(penvlst);
		exit(res);
	}
	waitpid(pid, &wstatus, 0);
	return (WEXITSTATUS(wstatus));
}
