/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_qtd_vars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 07:47:55 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/06 07:54:17 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/expand.h"

#include <stddef.h>//NULL

#include "libft.h"
#include "minishell/env.h"
#include "minishell/wtoklst.h"

void	my_expand_qtd_vars(t_wtoklst *toks, t_env *env)
{
	while (toks != NULL)
	{
		if (toks->type == QTD_VAR)
		{
			toks->type = CHARS;
			toks->content = my_env_get_value(env, toks->content);
			if (toks->content == NULL)
				toks->content = ft_strdup("");
		}
		toks = toks->next;
	}
}
