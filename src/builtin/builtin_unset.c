/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/24 12:09:22 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <stddef.h> //NULL

#include "libft.h" //ft_strchr, ft_puterr, ft_putstr_fd
#include "minishell/env.h"

static void	loc_pop_var(t_env *env, char *var);
static int	loc_varcmp(char	*str, char *var);

int	my_builtin_unset(t_env *env, char **args)
{
	int	error_status;
	int	i;

	error_status = 0;
	i = 1;
	while (args[i] != NULL)
	{
		if (my_check_varname(args[i], '\0') == FAILURE)
		{
			ft_puterr(args[i]);
			ft_puterr(" : not a valid identifier");
			error_status = 1;
		}
		loc_pop_var(env, args[i]);
		i++;
	}
	return (error_status);
}

static int	loc_varcmp(char	*str, char *var)
{
	size_t const	len = ft_strlen(var);

	if (ft_strncmp(str, var, len) == 0 && (str[len] == '\0' || str[len] == '='))
		return (0);
	return (1);
}

static void	loc_pop_var(t_env *env, char *var)
{
	t_env	*curr;
	t_env	*tmp;

	curr = env;
	if (curr != NULL && curr->next == NULL
		&& loc_varcmp(curr->next->content, var) == 0)
	{
		ft_memdel(&curr->content);
		ft_memdel(&curr->next);
		curr->next = NULL;
	}
	while (curr != NULL && curr->next != NULL)
	{
		if (loc_varcmp(curr->next->content, var) == 0)
		{
			tmp = curr->next;
			curr->next = tmp->next;
			ft_memdel(&tmp->content);
			ft_memdel(&tmp);
		}
		curr = curr->next;
	}
}
