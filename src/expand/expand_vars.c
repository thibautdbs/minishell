/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:41:56 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/17 17:26:59 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/expand.h"

#include <stddef.h>//NULL

#include "minishell/envlst.h"
#include "minishell/wtoklst.h"

static t_wtoklst	*loc_expand_var(char const *str, t_envlst *envlst);

void	my_expand_vars(t_wtoklst **ptoks, t_envlst *envlst)
{
	t_wtoklst	*new;

	while ((*ptoks) != NULL)
	{
		if ((*ptoks)->type == VAR)
		{
			new = loc_expand_var((*ptoks)->content, envlst);
			my_wtoklst_add_back(&new, (*ptoks)->next);
			my_wtoklst_del_one(ptoks);
			*ptoks = new;
		}
		ptoks = &(*ptoks)->next;
	}
}

static t_wtoklst	*loc_expand_var(char const *varname, t_envlst *envlst)
{
	t_wtoklst	*toks;
	char		*value;
	char		*sep;

	value = my_envlst_get_value((char *) varname, envlst);
	if (value == NULL)
		return (NULL);
	sep = my_envlst_get_value("IFS", envlst);
	if (sep == NULL)
		sep = " \t\n";
	toks = my_do_word_split(value, sep);
	return (toks);
}
