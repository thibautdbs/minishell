/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/15 18:35:38 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <stddef.h> //NULL
#include <unistd.h> //chdir
#include <stdio.h> //perror
#include "libft.h" //ft_puterr

#include "minishell/envlst.h"

static	t_success	loc_addpath_to_env(char *content, char *id,
					t_envlst *penvlst);
static	int	loc_update_env(char *old_pwd, t_envlst *penvlst);

int	my_builtin_cd(char **args, t_envlst *penvlst)
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
	return (loc_update_env(old_pwd, penvlst));
}

static	t_success	loc_addpath_to_env(char *content, char *id,
		t_envlst *penvlst)
{
	char	*joined_args;
	char	**args;

	joined_args = ft_strjoin(id, content);
	ft_memdel(&content);
	if (joined_args == NULL)
		return (FAILURE);
	args = ft_split(joined_args, ' ');
	ft_memdel(&joined_args);
	if (args == NULL)
		return (FAILURE);
	if (my_builtin_export(args, penvlst) == 12)
	{
		ft_strsdel(&args);
		return (FAILURE);
	}
	ft_strsdel(&args);
	return (SUCCESS);
}

static	int	loc_update_env(char *old_pwd, t_envlst *penvlst)
{
	char	*new_pwd;

	if (loc_addpath_to_env(old_pwd, "export OLDPWD=", penvlst) == FAILURE)
		return (12);
	new_pwd = my_get_pwd();
	if (new_pwd == NULL)
		return (12);
	if (loc_addpath_to_env(new_pwd, "export PWD=", penvlst) == FAILURE)
		return (12);
	return (0);
}
