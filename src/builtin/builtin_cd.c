/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/23 15:54:11 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <stddef.h> //NULL
#include <unistd.h> //chdir
#include <stdio.h> //perror
#include "libft.h" //ft_puterr

#include "minishell/env.h"

static	t_success	loc_addpath_to_env(t_env *env, char *content, char *label)
{
	char	*joined_args;
	char	**args;

	joined_args = ft_strjoin(label, content);
	ft_memdel(&content);
	if (joined_args == NULL)
		return (FAILURE);
	args = ft_split(joined_args, ' ');
	ft_memdel(&joined_args);
	if (args == NULL)
		return (FAILURE);
	if (my_builtin_export(env, args) == 12)
	{
		ft_strsdel(&args);
		return (FAILURE);
	}
	ft_strsdel(&args);
	return (SUCCESS);
}

static	int	loc_update_env(t_env *env, char *old_pwd)
{
	char	*new_pwd;

	if (loc_addpath_to_env(env, old_pwd, "export OLDPWD=") == FAILURE)
		return (12);
	new_pwd = my_get_pwd();
	if (new_pwd == NULL)
		return (12);
	if (loc_addpath_to_env(env, new_pwd, "export PWD=") == FAILURE)
		return (12);
	return (0);
}

int	my_builtin_cd(t_env *env, char **args)
{
	char	*old_pwd;
	if (args[1] == NULL)
		return (0);
	if (args[2] != NULL)
	{
		ft_puterr("cd: too many arguments");
		return (1);
	}
	old_pwd = my_get_pwd();
	if (old_pwd == NULL)
		return (12);
	if (chdir(args[1]) == -1)
	{
		ft_memdel(&old_pwd);
		perror("cd");
		return (1);
	}
	return (loc_update_env(env, old_pwd));
}
