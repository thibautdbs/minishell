/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:41:56 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/02 17:03:15 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell/expand.h"

#include <stddef.h>//NULL

#include "minishell/env.h"
#include "minishell/wtoklst.h"

static t_wtoklst	*loc_expand_var(char const *str, t_env *env);

void	my_expand_vars(t_wtoklst **ptoks, t_env *env)
{
	t_wtoklst	*new;

	while ((*ptoks) != NULL)
	{
		if ((*ptoks)->type == VAR)
		{
			new = loc_expand_var((*ptoks)->content, env);
			my_wtoklst_add_back(&new, (*ptoks)->next);
			my_wtoklst_delone(ptoks);
			*ptoks = new;
		}
		ptoks = &(*ptoks)->next;
	}
}

static t_wtoklst	*loc_expand_var(char const *varname, t_env *env)
{
	t_wtoklst	*toks;
	char		**args;
	char		*value;
	char		*sep;

	sep = my_env_get_value(env, "IFS");
	value = my_env_get_value(env, varname);
	args = NULL;
	toks = NULL;
	if (value != NULL && sep != NULL)
		args = ft_split(value, sep);
	if (args != NULL)
		toks = loc_strs_to_wtoklst(args);
	ft_memdel(&sep);
	ft_memdel(&value);
	ft_strsdel(&args);
	return (toks);
}
return ("");
