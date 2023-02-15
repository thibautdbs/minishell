/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:00:41 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/15 17:42:20 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include <stdlib.h>//exit
#include <stddef.h>//NULL
#include <errno.h>
#include <limits.h>//PATH_MAX
#include <unistd.h>//execve

#include "libft.h"
#include "minishell/wordlst.h"
#include "minishell/envlst.h"

static char	**loc_wordlst2argv(t_wordlst *wordlst);
static char	**loc_envlst2argv(t_envlst *envlst);

int	my_execve(t_wordlst *wordlst, t_envlst *envlst)
{
	char	path_name[PATH_MAX];
	char	**argv;
	char	**envp;

	errno = 0;
	if (my_get_path(path_name, wordlst->content, envlst) == -1)
	{
		my_wordlst_del(&wordlst);
		my_envlst_del(&envlst);
		exit(errno);
	}
	argv = loc_wordlst2argv(wordlst);
	my_wordlst_del(&wordlst);
	envp = loc_envlst2argv(envlst);
	my_envlst_del(&envlst);
	if (argv != NULL && envp != NULL)
		execve((const char *)path_name, argv, envp);
	ft_strsdel(&argv);
	ft_strsdel(&envp);
	exit(errno);
}

static char	**loc_wordlst2argv(t_wordlst *wordlst)
{
	char	**argv;
	int		i;

	argv = ft_calloc(my_wordlst_size(wordlst) + 1, sizeof(t_wordlst));
	if (argv == NULL)
		return (NULL);
	i = 0;
	while (wordlst != NULL)
	{
		argv[i] = ft_strdup(wordlst->content);
		if (argv[i] == NULL)
		{
			ft_strsdel(&argv);
			return (NULL);
		}
		wordlst = wordlst->next;
	}
	return (argv);
}

static char	**loc_envlst2argv(t_envlst *envlst)
{
	char	**envp;
	int		i;

	envp = ft_calloc(my_envlst_size(envlst) + 1, sizeof(t_envlst));
	if (envp == NULL)
		return (NULL);
	i = 0;
	while (envlst != NULL)
	{
		envp[i] = ft_strdup(envlst->content);
		if (envp[i] == NULL)
		{
			ft_strsdel(&envp);
			return (NULL);
		}
		envlst = envlst->next;
	}
	return (envp);
}
