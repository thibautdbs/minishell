/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/16 17:15:09 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <stddef.h> //NULL

#include "libft.h" //ft_strchr, ft_puterr, ft_putendl_fd
#include "minishell/envlst.h"

int	my_builtin_env(t_wordlst *words, t_envlst *envlst)
{
	if (my_wordlst_size(words) > 1)
	{
		ft_puterr("minishell: env: too many arguments");
		return (1);
	}
	while (envlst != NULL)
	{
		if (ft_strchr(envlst->content, '=') != NULL)
			ft_putendl_fd(envlst->content, STDOUT);
		envlst = envlst->next;
	}
	return (0);
}
