/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:13:51 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/13 23:44:19 by tdubois          ###   ########.fr       */
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
#include "minishell/utils.h"

static int	loc_run_subshell(t_cmdlst *cmd, t_envlst **penvlst, int res,
				t_cmdtree **pcmdtree);

static int	loc_run_simple_cmd(t_cmdlst *cmd, t_envlst **penvlst, int res,
				t_cmdtree **pcmdtree);

static int	loc_run_builtin(t_cmdlst *cmd, t_envlst **penvlst, int res);

static int	loc_run_execve(t_cmdlst *cmd, t_envlst **penvlst, int res,
				t_cmdtree **pcmdtree);

int	my_run_cmd(t_cmdlst *cmd, t_envlst **penvlst, int res, t_cmdtree **pcmdtree)
{
	if (cmd->type == SUBSHELL)
		return (loc_run_subshell(cmd, penvlst, res, pcmdtree));
	return (loc_run_simple_cmd(cmd, penvlst, res, pcmdtree));
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
		return (loc_run_builtin(cmd, penvlst, res));
	return (loc_run_execve(cmd, penvlst, res, pcmdtree));
}

static int	loc_run_subshell(t_cmdlst *cmd, t_envlst **penvlst, int res,
	t_cmdtree **pcmdtree)
{
	int	pid;
	int	new_res;

	pid = fork();
	if (pid == 0)
	{
		new_res = my_redirect(cmd->redirs, *penvlst, res);
		if (new_res != EXIT_SUCCESS)
		{
			my_cmdtree_del(pcmdtree);
			my_envlst_del(penvlst);
			exit(new_res);
		}
		res = my_run(cmd->subcmd, penvlst, res, pcmdtree);
		my_cmdtree_del(pcmdtree);
		my_envlst_del(penvlst);
		my_exit_or_raise(res);
	}
	return (my_waitpid(pid));
}

static int	loc_run_builtin(t_cmdlst *cmd, t_envlst **penvlst, int res)
{
	int			new_res;
	int const	saved_stdin = dup(STDIN_FILENO);
	int const	saved_stdout = dup(STDERR_FILENO);

	new_res = my_redirect(cmd->redirs, *penvlst, res);
	if (new_res == EXIT_SUCCESS)
		new_res = my_builtin(cmd->words, penvlst, res);
	dup2(saved_stdin, STDIN_FILENO);
	dup2(saved_stdout, STDERR_FILENO);
	close(saved_stdin);
	close(saved_stdout);
	return (new_res);
}

static int	loc_run_execve(t_cmdlst *cmd, t_envlst **penvlst, int res,
				t_cmdtree **pcmdtree)
{
	int			pid;
	int			new_res;
	t_wordlst	*words;

	pid = fork();
	if (pid == 0)
	{
		new_res = my_redirect(cmd->redirs, *penvlst, res);
		if (new_res != EXIT_SUCCESS)
		{
			my_cmdtree_del(pcmdtree);
			my_envlst_del(penvlst);
			exit(new_res);
		}
		words = cmd->words;
		cmd->words = NULL;
		my_cmdtree_del(pcmdtree);
		exit(my_execve(words, *penvlst));
	}
	return (my_waitpid(pid));
}
