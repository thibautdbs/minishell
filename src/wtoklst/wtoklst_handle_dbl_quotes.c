/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_handle_dbl_quotes.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:00:04 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/09 17:00:31 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wtoklst.h"

#include <stddef.h>//NULL

static t_wtoklst	*loc_handle_qtd_var(char const **pstr);

t_wtoklst	*my_wtoklst_handle_dbl_quotes(char const **pstr)
{
	t_wtoklst	*toks;
	t_wtoklst	*tmp;

	toks = NULL;
	*pstr += 1;
	while (**pstr != '\"' && **pstr != '\0')
	{
		if (**pstr == '$')
			tmp = loc_handle_qtd_var(pstr);
		else
			tmp = my_wtoklst_handle_word(pstr);
		if (tmp == NULL)
		{
			my_wtoklst_del(&toks);
			return (tmp);
		}
		my_wtoklst_add_back(&toks, tmp);
	}
	*pstr += 1;
	return (toks);
}

static t_wtoklst	*loc_handle_qtd_var(char const **pstr)
{
	t_wtoklst	*tok;

	tok = my_wtoklst_handle_dollar(pstr);
	if (tok != NULL)
		tok->type = QTD_VAR;
	return (tok);
}
