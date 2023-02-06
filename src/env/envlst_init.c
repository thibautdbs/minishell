/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:03:48 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/06 11:40:56 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

#include <stddef.h> //NULL

t_envlst	*my_envlst_init(char	**envp)
{
	t_envlst	*env;
	t_envlst	*curr;
	int			i;

	i = 0;
	env = NULL;
	while (envp[i] != NULL)
	{
		curr = my_envlst_create(envp[i]);
		if (curr == NULL)
		{
			my_envlst_destroy(&env);
			return (NULL);
		}
		my_envlst_addback(&env, curr);
		i++;
	}
	return (env);
}
