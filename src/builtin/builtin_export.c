/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/17 17:50:09 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <stddef.h> //NULL
#include <unistd.h> //write
#include "libft.h" //t_status, ft_strncmp, ft_strlen, t_success

#include "minishell/env.h"

static int	loc_set_vars(t_env *env, char **args);
static t_success	loc_update_env(t_env *env, char *var);
static int loc_print_env(t_env *env);

int	my_builtin_export(t_env *env, char **args)
{
	if (args[1] == NULL)
		return (loc_print_env(env));
	return (loc_set_vars(env, args + 1));
}

static void	loc_print_formalized(char *str)
{
	int		label_len;

	label_len = ft_strlen(str) - ft_strlen(ft_strchr(str, '='));
	ft_putstr_fd("declare -x ", STDOUT);
	write(STDOUT, str, label_len);
	if (ft_strchr(str, '=') != NULL)
	{
		ft_putstr_fd("=\"", STDOUT);
		ft_putstr_fd(ft_strchr(str, '=') + 1, STDOUT);
		ft_putstr_fd("\"\n", STDOUT);
	}
	else
		ft_putstr_fd("\n", STDOUT);
}

static int loc_print_env(t_env *env)
{
	char	**envp;
	int	i;

	i = 0;
	envp = my_get_envp(env);
	if (envp == NULL)
	{
		ft_puterr("Error occured when creating envp");
		return (12);
	}
	my_sort_env(envp);
	while (envp[i] != NULL)
	{
		loc_print_formalized(envp[i]);	
	i++;
	}
	ft_strsdel(&envp);
	return (0);
}

static t_success	loc_update_env(t_env *env, char *var)
{
	t_env	*new;

	new = my_env_create(var);
	if (new == NULL)
	{
		ft_puterr("error occured when creating env var");
		return (FAILURE);
	}
	my_env_addback(&env, new);
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
		else
		{
			if (loc_update_env(env, args[i]) == FAILURE)
				return (12);
		}
		i++;
	}
	return (error_status);
}
