/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/20 17:30:32 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <stddef.h> //NULL
#include "libft.h" //t_success, ft_strlen, ft_strchr

#include "minishell/env.h"

static int			loc_set_vars(t_env *env, char **args);
static t_success	loc_update_env(t_env *env, char *var);

int	my_builtin_export(t_env *env, char **args)
{
	if (args[0] == NULL || args[1] == NULL)
		return (my_print_export(env));
	return (loc_set_vars(env, args + 1));
}

static t_success	loc_update_env(t_env *env, char *var)
{
	t_env	*env_var;
	env_var = my_env_find_var(env, var);
	if (env_var == NULL)
		return (my_add_var(env, var));
	if (ft_strlen(ft_strchr(var, '=')) - ft_strlen(ft_strchr(var, '+')) == 1)
		return (my_append_var(env_var, var));
	if (ft_strchr(var, '=') != NULL)
		return (my_overwrite_var(env_var, var));
	return (SUCCESS);
}

static int	loc_set_vars(t_env *env, char **args)
{
	int	error_status;
	int	i;

	error_status = 0;
	i = 0;
	while (args[i] != NULL)
	{
		if (my_check_varname(args[i], '=') == FAILURE)
		{
			ft_puterr(args[i]);
			ft_puterr(" : not a valid identifier");
			error_status = 1;
		}
		else if	(loc_update_env(env, args[i]) == FAILURE)
			return (12);
		i++;
	}
	return (error_status);
}
