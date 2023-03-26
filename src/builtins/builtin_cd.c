/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/26 21:22:28 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <stddef.h>//NULL
#include <unistd.h>//chdir
#include <stdio.h>//perror
#include <limits.h>//PATH_MAX
#include <errno.h>//errno

#include "libft.h"//ft_puterr
#include "minishell/envlst.h"

static	int	loc_update_env(char const *old_pwd, t_envlst **penvlst);

int	my_builtin_cd(t_wordlst *words, t_envlst **penvlst)
{
	char	cwd[PATH_MAX];
	char	*dst;

	if (my_wordlst_size(words) > 2)
	{
		ft_putendl_fd("minishell: cd: too many arguments", STDERR_FILENO);
		return (1);
	}
	if (my_wordlst_size(words) == 1)
		dst = my_envlst_get_value("HOME", *penvlst);
	else
		dst = my_wordlst_at(words, 1)->content;
	if (dst == NULL)
		return (0);
	errno = 0;
	if (getcwd(cwd, PATH_MAX) == NULL || chdir(dst) == -1)
	{
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(dst, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		perror("");
		return (1);
	}
	return (loc_update_env(cwd, penvlst));
}

static	int	loc_update_env(char const *old_pwd, t_envlst **penvlst)
{
	char	pwd[PATH_MAX];
	char	varspec[PATH_MAX + 7];

	if (getcwd(pwd, PATH_MAX) == NULL)
		return (errno);
	ft_strlcpy(varspec, "PWD=", PATH_MAX + 7);
	ft_strlcat(varspec, pwd, PATH_MAX + 7);
	if (my_envlst_apply(varspec, penvlst) != 0)
		return (errno);
	ft_strlcpy(varspec, "OLDPWD=", PATH_MAX + 7);
	ft_strlcat(varspec, old_pwd, PATH_MAX + 7);
	if (my_envlst_apply(varspec, penvlst) != 0)
		return (errno);
	return (0);
}
