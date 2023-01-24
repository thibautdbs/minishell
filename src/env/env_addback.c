/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_addback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:16:42 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/24 12:10:55 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> //NULL

#include "minishell/env.h"

t_env	*loc_env_last(t_env *env)
{
	t_env	*curr;

	curr = env;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}

void	my_env_addback(t_env **env, t_env *to_add)
{
	if (env == NULL || to_add == NULL)
		return ;
	if (*env == NULL)
		*env = to_add;
	else
		loc_env_last(*env)->next = to_add;
}
