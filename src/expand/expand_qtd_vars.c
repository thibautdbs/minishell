/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_qtd_vars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 07:47:55 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/06 17:40:57 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/expand.h"

#include <stddef.h>//NULL

#include "libft.h"
#include "minishell/envlst.h"
#include "minishell/wtoklst.h"

void	my_expand_qtd_vars(t_wtoklst *toks, t_envlst *env)
{
	char	*value;

	while (toks != NULL)
	{
		if (toks->type == QTD_VAR)
		{
			toks->type = CHARS;
			value = my_envlst_get_value(env, toks->content);
			ft_memdel(&toks->content);
			toks->content = value;
		}
		toks = toks->next;
	}
}
