/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/24 12:01:36 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/env.h"

#include <stddef.h> //NULL
#include "libft.h" //ft_strchr, ft_puterr, ft_putstr_fd

int	my_builtin_env(t_env *env, char **args)
{
	t_env	*curr;

	curr = env;
	if (args[1] != NULL)
	{
		ft_puterr("env : No such file or directory");
		return (127);
	}
	while (curr != NULL)
	{
		if (ft_strchr(env->content, '=') != NULL)
			ft_putstr_fd(env->content, STDOUT);
		curr = curr->next;
	}
	return (0);
}
