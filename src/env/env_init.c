/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:03:48 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/13 14:54:51 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/env.h"

#include <stddef.h> //NULL

t_env	*my_env_init(char	**envp)
{
	t_env	*env;
	t_env	*curr;
	int		i;

	i = 0;
	env = NULL;
	while (envp[i] != NULL)
	{
		curr = my_env_create(envp[i]);
		if (curr == NULL)
		{
			my_env_destroy(&env);
			return (NULL);
		}
		my_env_addback(&env, curr);
		i++;
	}
	return (env);
}
