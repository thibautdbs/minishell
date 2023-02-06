/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:58:26 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/06 11:51:16 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include "libft.h" //ft_isdigit, ft_islong, ft_atol
#include <stdlib.h> //exit

#include "minishell/envlst.h"

static int	loc_is_longnumeric(char *str);

int	my_builtin_exit(t_envlst *env, char **args)
{
	(void) env;
	if (args[1] == NULL)
		exit(0);
	if (loc_is_longnumeric(args[1]))
	{
		if (args[2] != NULL)
		{
			ft_puterr("exit : too many arguments");
			return (0);
		}
		exit((unsigned char) ft_atol(args[1]));
	}
	ft_puterr("exit : numeric argument required");
	exit(2);
}

static int	loc_is_longnumeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (ft_islong(str) == FALSE)
		return (0);
	return (1);
}
