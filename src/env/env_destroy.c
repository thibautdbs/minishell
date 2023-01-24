/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:02:15 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/13 14:54:26 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/env.h"

#include <libft.h> //ft_memset

void	my_env_destroy(t_env **env)
{
	t_env	*curr;
	t_env	*next;

	curr = *env;
	while (curr != NULL)
	{
		ft_memdel(&curr->content);
		next = curr->next;
		ft_memdel(&curr);
		curr = next;
	}
	*env = NULL;
}
