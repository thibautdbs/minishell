/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:13:04 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/14 09:58:43 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include <stdlib.h>//exit
#include <stddef.h>//NULL
#include <errno.h>
#include <limits.h>//PATH_MAX
#include <unistd.h>//execve
#include <signal.h>

#include "libft.h"
#include "minishell/utils.h"
#include "minishell/wordlst.h"
#include "minishell/envlst.h"

static t_success	loc_convert_argv_and_envp(
						t_wordlst *wordlst, t_envlst *envlst,
						char ***ret_argv, char ***ret_envp);

static void			loc_sigquit_handler(int signum);

int	my_execve(t_wordlst *wordlst, t_envlst *envlst)
{
	char	path_name[PATH_MAX];
	char	**argv;
	char	**envp;

	if (my_get_path(path_name, wordlst->content, envlst) == -1)
	{
		ft_putstr_fd(wordlst->content, STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
		my_wordlst_del(&wordlst);
		my_envlst_del(&envlst);
		exit(errno);
	}
	if (loc_convert_argv_and_envp(wordlst, envlst, &argv, &envp) == FAILURE)
		exit(errno);
	if (argv != NULL && envp != NULL)
	{
		my_signal(SIGQUIT, loc_sigquit_handler);
		execve((const char *)path_name, argv, envp);
	}
	ft_putstr_fd(argv[0], STDERR_FILENO);
	ft_putendl_fd(": command is not executable", STDERR_FILENO);
	ft_strsdel(&argv);
	ft_strsdel(&envp);
	exit(errno);
}

static t_success	loc_convert_argv_and_envp(
						t_wordlst *wordlst, t_envlst *envlst,
						char ***ret_argv, char ***ret_envp)
{
	*ret_argv = my_wordlst_to_args(wordlst);
	*ret_envp = my_envlst_to_envp(envlst);
	my_wordlst_del(&wordlst);
	my_envlst_del(&envlst);
	if (*ret_argv == NULL || *ret_envp == NULL)
	{
		ft_strsdel(ret_argv);
		ft_strsdel(ret_envp);
		return (FAILURE);
	}
	return (SUCCESS);
}

static void	loc_sigquit_handler(int signum)
{
	(void) signum;
}
