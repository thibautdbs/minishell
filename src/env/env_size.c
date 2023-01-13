/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:18:45 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/13 11:21:26 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/env.h"

#include <stddef.h> //NULL

int	my_env_size(t_env *env)
{
	int	i;
	t_env	*curr;
	
	i = 0;
	curr = env;
	while (curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}
