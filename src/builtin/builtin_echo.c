/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/06 11:50:05 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/envlst.h"

#include <stddef.h> //NULL
#include "libft.h" //ft_putstr_fd

static int	loc_is_nl_flag(char *str);

int	my_builtin_echo(t_envlst *env, char **args)
{
	int	i;

	(void) env;
	i = 1;
	while (loc_is_nl_flag(args[i]))
		i++;
	while (args[i] != NULL)
	{
		ft_putstr_fd(args[i], STDOUT);
		i++;
		if (args[i] != NULL)
			ft_putstr_fd(" ", STDOUT);
	}
	if (loc_is_nl_flag(args[1]) == 0)
		ft_putstr_fd("\n", STDOUT);
	return (0);
}

static int	loc_is_nl_flag(char *str)
{
	int	i;

	if (str[0] != '-')
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}
