/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/16 13:36:19 by ffeaugas         ###   ########.fr       */
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

void	my_builtin_env(t_env *env, char **argv)
{
	char	**envp;

	if (argv[1] != NULL)
	{
		ft_puterr("env : No such file or directory");
		return ;
	}
	envp = my_get_envp(env);
	if (envp == NULL)
		return ;
	my_sort_env(envp);
	loc_print_env(envp);
	ft_strsdel(&envp);
}
/*
int	main(int argc, char **argv, char **envp)
{
	t_env	*env;

	(void) argc;
	(void) argv;
	env = my_env_init(envp);
	my_builtin_env(t_env *env, {"env", ""});
}
*/
