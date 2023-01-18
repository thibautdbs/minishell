/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/18 20:09:17 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/env.h"

#include <stddef.h> //NULL
#include <unistd.h> //getcwd
#include "libft.h" //ft_calloc, ft_puterr, ft_putstr_fd, ft_memdel

int	my_builtin_pwd(t_env *env, char **args)
{
	char	*buf;
	int		size;

	(void) env;
	(void) args;
	size = 1;
	while (1)
	{
		buf = ft_calloc(sizeof(char), size);
		if (buf == NULL)
		{
			ft_puterr("malloc error when creating pwd buf");
			return (12);
		}
		if (getcwd(buf, size) != NULL)
			break ;
		ft_memdel(&buf);
		size++;
	}
	ft_putstr_fd(buf, STDOUT);
	ft_putstr_fd("\n", STDOUT);
	ft_memdel(&buf);
	return (0);
}
