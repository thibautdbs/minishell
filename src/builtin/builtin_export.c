/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/15 18:57:23 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <stddef.h> //NULL

#include "libft.h" //t_success, ft_strlen, ft_strchr
#include "minishell/envlst.h"

static int			loc_set_vars(char **args, t_envlst *penvlst);
static t_success	loc_update_env(char *var, t_envlst *penvlst);

int	my_builtin_export(char **args, t_envlst *penvlst)
{
	if (args[0] == NULL || args[1] == NULL)
		return (my_print_export(penvlst));
	return (loc_set_vars(args + 1, penvlst));
}

static t_success	loc_update_env(char *var, t_envlst *penvlst)
{
	t_envlst	*env_var;

	env_var = my_envlst_find_var(penvlst, var);
	if (env_var == NULL)
		return (my_add_var(var, penvlst));
	if (ft_strlen(ft_strchr(var, '=')) - ft_strlen(ft_strchr(var, '+')) == 1)
		return (my_append_var(var, env_var));
	if (ft_strchr(var, '=') != NULL)
		return (my_overwrite_var(var, env_var));
	return (SUCCESS);
}

static int	loc_set_vars(char **args, t_envlst *penvlst)
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
		else if (loc_update_env(args[i], penvlst) == FAILURE)
			return (12);
		i++;
	}
	return (error_status);
}
