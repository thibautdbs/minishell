/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/16 16:34:54 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/env.h"

#include <stddef.h> //NULL
#include "libft.h" //t_status, ft_strncmp, ft_strlen

static void loc_print_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strchr(envp[i], '=') != NULL)
			ft_putstr_fd(envp[i], STDOUT);
		i++;
	}
}

int	my_builtin_env(t_env *env, char **argv)
{
	char	**envp;

	if (argv[1] != NULL)
	{
		ft_puterr("env : No such file or directory");
		return (127);
	}
	envp = my_get_envp(env);
	if (envp == NULL)
		return (12);
	my_sort_env(envp);
	loc_print_env(envp);
	ft_strsdel(&envp);
	return (0);
}
