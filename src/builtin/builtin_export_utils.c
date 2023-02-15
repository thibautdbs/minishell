/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:37:44 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/15 18:58:52 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <unistd.h> //write
#include <stddef.h> //NULL

#include "libft.h" //ft_strlen, ft_strchr, ft_putstr_fd, ...
#include "minishell/envlst.h"

static void	loc_print_formalized(char *str);

int	my_print_export(t_envlst *envlst)
{
	char	**envp;
	int		i;

	i = 0;
	envp = my_envlst_to_envp(envlst);
	if (envp == NULL)
	{
		ft_puterr("Error occured when creating envp");
		return (12);
	}
	my_sort_envp(envp);
	while (envp[i] != NULL)
	{
		loc_print_formalized(envp[i]);
		i++;
	}
	ft_strsdel(&envp);
	return (0);
}

t_success	my_add_var(char *var, t_envlst *penvlst)
{
	t_envlst	*new;

	new = my_envlst_new(var);
	if (new == NULL)
	{
		ft_puterr("error occured when creating env var");
		return (FAILURE);
	}
	my_envlst_addback(&penvlst, new);
	return (SUCCESS);
}

t_success	my_append_var(char *var, t_envlst *penvlst)
{
	char	*new_content;

	new_content = ft_strjoin(penvlst->content, ft_strchr(var, '=') + 1);
	if (new_content == NULL)
	{
		ft_puterr("error occured when growing env var");
		return (FAILURE);
	}
	ft_memdel(&penvlst->content);
	penvlst->content = new_content;
	return (SUCCESS);
}

t_success	my_overwrite_var(char *var, t_envlst *penvlst)
{
	char	*new_content;

	new_content = ft_strdup(ft_strchr(var, '=') + 1);
	if (new_content == NULL)
	{
		ft_puterr("error occured when overwritting env var");
		return (FAILURE);
	}
	ft_memdel(&penvlst->content);
	penvlst->content = new_content;
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
