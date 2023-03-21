/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_handle_dbl_quotes.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:00:04 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/21 15:01:51 by tdubois          ###   ########.fr       */
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

	toks = my_wtoklst_new(CHARS, "", 0);
	if (toks == NULL)
		return (NULL);
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
	if (tok != NULL
		&& tok->type == CHARS
		&& (tok->content == NULL || ft_strlen(tok->content) == 0))
	{
		ft_memdel(&tok->content);
		tok->content = ft_strdup("$");
	}
	if (tok != NULL && tok->type == VAR)
		tok->type = QTD_VAR;
	return (tok);
}

static t_wtoklst	*loc_handle_chars(char const **pstr)
{
	int			len;
	t_wtoklst	*tmp;

	len = ft_strcspn(*pstr, "\"$");
	tmp = my_wtoklst_new(CHARS, *pstr, len);
	*pstr += len;
	return (tmp);
}
