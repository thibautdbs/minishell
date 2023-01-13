/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/13 18:32:45 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/env.h"

#include <stddef.h> //NULL
#include "libft.h" //t_status, ft_strncmp, ft_strlen

static int	loc_envp_len(char **envp)
{
	int i;

	while (envp[i] != NULL)
		i++;
	return (i);
}

static void	loc_sort_env(char **envp)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;
	
	len = loc_envp_len(envp);
	i = 0;
	while (i < len - 2)
	{
		j = 0;
		while (j < len - 1)
		{
			if (ft_strncmp(envp[j], envp[j + 1]) > 0)
			{
				tmp = envp[j];
				envp[j] = envp[j + 1];
				envp[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void my_print_env(char **envp)
{
	int	i;

	while (envp[i] != NULL)
	{
		
	}
}

void	my_builtin_env(t_env *env, char **argv)
{
	char	**envp;

	if (argv[1] != NULL)
	{
		perror("Invalid env arg");
		return ;
	}
	envp = my_get_envp(env);
	if (envp == NULL)
		return ;
	loc_sort_env(envp);
	loc_print_env(envp);
}
