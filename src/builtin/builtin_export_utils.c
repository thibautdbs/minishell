/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:37:44 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/24 12:06:43 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <unistd.h> //write
#include <stddef.h> //NULL

#include "libft.h" //ft_strlen, ft_strchr, ft_putstr_fd, ...
#include "minishell/env.h"

static void	loc_print_formalized(char *str);

int	my_print_export(t_env *env)
{
	char	**envp;
	int		i;

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

t_success	my_add_var(t_env *env, char *var)
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

t_success	my_append_var(t_env *env, char *var)
{
	char	*new_content;

	new_content = ft_strjoin(env->content, ft_strchr(var, '=') + 1);
	if (new_content == NULL)
	{
		ft_puterr("error occured when growing env var");
		return (FAILURE);
	}
	ft_memdel(&env->content);
	env->content = new_content;
	return (SUCCESS);
}

t_success	my_overwrite_var(t_env *env, char *var)
{
	char	*new_content;

	new_content = ft_strdup(ft_strchr(var, '=') + 1);
	if (new_content == NULL)
	{
		ft_puterr("error occured when overwritting env var");
		return (FAILURE);
	}
	ft_memdel(&env->content);
	env->content = new_content;
	return (SUCCESS);
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
