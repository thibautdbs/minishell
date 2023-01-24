/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_get_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:36:57 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/24 12:19:30 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" //ft_strncmp, ft_split, ft_strsdel, ft_strjoin_sep, ft_memdel

#include <unistd.h> //access

static char	**loc_get_path_tab(char **my_env);
static char	*loc_select_path(char **path_tab, char *cmd);

char	*my_get_path(char **args, char **my_env)
{
	char	**path_tab;
	char	*path;

	path_tab = loc_get_path_tab(my_env);
	if (path_tab == NULL)
		return (NULL);
	path = loc_select_path(path_tab, args[0]);
	ft_strsdel(&path_tab);
	return (path);
}

static char	**loc_get_path_tab(char **my_env)
{
	char	**path_tab;
	int		i;

	i = 0;
	while (my_env[i] != NULL && ft_strncmp(my_env[i], "PATH=", 5) != 0)
		i++;
	if (ft_strncmp(my_env[i], "PATH=", 5) != 0)
		return (NULL); //No PATH var found is env
	path_tab = ft_split(my_env[i] + 5, ':');
	return (path_tab);
}

static char	*loc_select_path(char **path_tab, char *cmd)
{
	char	*path;
	int		i;

	i = 0;
	while (path_tab[i] != 0)
	{
		path = ft_strjoin_sep(path_tab[i], cmd, "/");
		if (path == NULL)
			return (NULL);
		if (access(path, 0) == 0)
			return (path);
		ft_memdel(&path);
		i++;
	}
	return (NULL); //Cmd doesn't exist or none of the path worked
}
