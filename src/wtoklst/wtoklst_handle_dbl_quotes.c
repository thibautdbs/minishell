/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_handle_dbl_quotes.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:00:04 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/10 12:38:10 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wtoklst.h"

#include <stddef.h>//NULL

#include "libft.h"

static t_wtoklst	*loc_handle_qtd_var(char const **pstr);
static t_wtoklst	*loc_handle_chars(char const **pstr);

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
			tmp = loc_handle_chars(pstr);
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

static t_wtoklst	*loc_handle_chars(char const **pstr)
{
	return (my_wtoklst_new(CHARS, *pstr, ft_strcspn(*pstr, "\"")));
}
