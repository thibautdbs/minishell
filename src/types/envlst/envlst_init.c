/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:03:48 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/21 18:01:08 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

#include <stddef.h> //NULL

t_envlst	*my_envlst_init(char **envp)
{
	t_envlst	*env;
	t_envlst	*curr;
	int			i;

	i = 0;
	env = NULL;
	while (envp[i] != NULL)
	{
		curr = my_envlst_new(envp[i]);
		if (curr == NULL)
		{
			my_envlst_del(&env);
			return (NULL);
		}
		my_envlst_addback(&env, curr);
		i++;
	}
	return (env);
}
