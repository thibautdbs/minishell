/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:13:04 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/13 12:04:53 by tdubois          ###   ########.fr       */
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

static void	loc_sigquit_handler(int	signum)
{
	(void) signum;
}

int	my_execve(t_wordlst *wordlst, t_envlst *envlst)
{
	char	path_name[PATH_MAX];
	char	**argv;
	char	**envp;

	errno = 0;
	if (wordlst->content[ft_strspn(wordlst->content, " \t\n")] == '\0'
		|| my_get_path(path_name, wordlst->content, envlst) == -1)
	{
		ft_puterr(wordlst->content);
		ft_puterr(": command not found\n");
		my_wordlst_del(&wordlst);
		my_envlst_del(&envlst);
		exit(errno);
	}
	argv = my_wordlst_to_args(wordlst);
	my_wordlst_del(&wordlst);
	envp = my_envlst_to_envp(envlst);
	my_envlst_del(&envlst);
	if (argv != NULL && envp != NULL)
	{
		my_signal(SIGQUIT, loc_sigquit_handler);
		execve((const char *)path_name, argv, envp);
	}
	ft_strsdel(&argv);
	ft_strsdel(&envp);
	exit(errno);
}
