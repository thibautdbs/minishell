/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_get_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:36:57 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/10 12:02:28 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**loc_get_path_tab(char const **my_env)
{
	char	**path_tab;
	int		i;

	i = 0;
	while (my_env[i] != NULL && ft_strncmp(my_env[i], "PATH=", 5) != 0)
		i++;
	if (ft_strncmp(my_env[i], "PATH=", 5) != 0)
		return (NULL);
	path_tab = ft_split(my_env[i] + 5, ':');
	return (path_tab);
}

static char	*loc_select_path(char const **path_tab, char const **my_env)
{
}

char	*my_get_path(char **args, char **my_env)
{
	char	**path_tab;
	char	*path;

	path_tab = loc_get_path_tab(my_env);
	if (path_tab == NULL)
		return (NULL);
	path = loc_select_path(path_tab, args)
	if (path == NULL)
	{
		ft_strsdel(&path_tab);
		return (NULL);
	}
	return (path);
}
