/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/06 11:55:47 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <stddef.h> //NULL
#include "libft.h" //ft_putstr_fd, ft_memdel

#include "minishell/envlst.h"

int	my_builtin_pwd(t_envlst *env, char **args)
{
	char	*pwd;

	(void) env;
	(void) args;
	pwd = my_get_pwd();
	if (pwd == NULL)
		return (12);
	ft_putstr_fd(pwd, STDOUT);
	ft_putstr_fd("\n", STDOUT);
	ft_memdel(&pwd);
	return (0);
}
