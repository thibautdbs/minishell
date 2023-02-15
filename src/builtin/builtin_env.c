/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/15 18:28:00 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

#include <stddef.h> //NULL
#include "libft.h" //ft_strchr, ft_puterr, ft_putstr_fd

int	my_builtin_env(char **args, t_envlst *penvlst)
{
	t_envlst	*curr;

	curr = penvlst;
	if (args[1] != NULL)
	{
		ft_puterr("env : No such file or directory");
		return (127);
	}
	while (curr != NULL)
	{
		if (ft_strchr(penvlst->content, '=') != NULL)
			ft_putstr_fd(penvlst->content, STDOUT);
		curr = curr->next;
	}
	return (0);
}
