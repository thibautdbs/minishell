/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:36:57 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/21 18:21:08 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include <unistd.h>//access, getcwd
#include <limits.h>//PATH_MAX
#include <stdlib.h>

#include "libft.h" //ft_strlcpy, ft_strlcat, ft_strtok_r, ft_strchr
#include "minishell/envlst.h"

int	my_get_path(char *buf, char const *name, t_envlst *envlst)
{
	char	*saveptr;
	char	*tok;
	char	*path;

	if (ft_strchr(name, '/') != NULL)
	{
		ft_strlcpy(buf, name, PATH_MAX);
		return (access(buf, F_OK));
	}
	saveptr = NULL;
	path = ft_strdup(my_envlst_get_value("PATH", envlst));
	tok = ft_strtok_r(path, ":", &saveptr);
	while (tok != NULL && *name != '\0')
	{
		ft_strlcpy(buf, tok, PATH_MAX);
		ft_strlcat(buf, "/", PATH_MAX);
		ft_strlcat(buf, name, PATH_MAX);
		if (access(buf, F_OK) == 0)
			free(path);
		if (access(buf, F_OK) == 0)
			return (0);
		tok = ft_strtok_r(NULL, ":", &saveptr);
	}
	free(path);
	return (-1);
}
