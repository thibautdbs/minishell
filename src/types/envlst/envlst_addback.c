/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_addback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:16:42 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/21 16:43:12 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> //NULL

#include "minishell/envlst.h"

t_envlst	*loc_envlst_last(t_envlst *env)
{
	t_envlst	*curr;

	curr = env;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr);
}

void	my_envlst_addback(t_envlst **env, t_envlst *to_add)
{
	if (*env == NULL)
	{
		*env = to_add;
		return ;
	}
	loc_envlst_last(*env)->next = to_add;
}
