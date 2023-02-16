/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:23:38 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/16 19:06:51 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/builtin.h"

#include <stddef.h> //NULL

#include "libft.h" //t_success, ft_strlen, ft_strchr
#include "minishell/envlst.h"
#include "minishell/wordlst.h"

static int	loc_update_env(char *str, t_envlst **penvlst);

int	my_builtin_export(t_wordlst *words, t_envlst **penvlst)
{
	int	res;

	if (words == NULL)
		return (my_print_export(*penvlst));
	words = words->next;
	res = 0;
	while (words != NULL)
	{
		if (my_is_valid_identifier(words->content, '=') == FAILURE)
		{
			ft_puterr("minishell: export: not a valid identifier");
			res = 1;
		}
		else 
			res = loc_update_env(words->content, penvlst);
		if (res > 1)
			return (res);
		words = words->next;
	}
	return (res);
}

static int	loc_update_env(char *str, t_envlst **penvlst)
{
	t_envlst	*env_var;

	env_var = my_envlst_find_var(*penvlst, str);
	if (env_var == NULL)
		return (my_add_var(str, penvlst));
	if (ft_strlen(ft_strchr(str, '=')) - ft_strlen(ft_strchr(str, '+')) == 1)
		return (my_append_var(str, &env_var));
	if (ft_strchr(str, '=') != NULL)
		return (my_overwrite_var(str, &env_var));
	return (SUCCESS);
}
