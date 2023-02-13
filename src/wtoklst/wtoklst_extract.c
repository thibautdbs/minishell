/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_extract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:00:35 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/06 17:24:43 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wtoklst.h"

#include <stddef.h>//NULL

#define NTOKENIZER 4

static t_wtoklst	*loc_extract_wtok(char const **pstr);

t_wtoklst	*my_wtoklst_extract(char const *word)
{
	t_wtoklst	*toks;
	t_wtoklst	*new;

	toks = NULL;
	while (*word != '\0')
	{
		new = loc_extract_wtok(&word);
		if (new == NULL)
		{
			my_wtoklst_del(&toks);
			return (NULL);
		}
		my_wtoklst_add_back(&toks, new);
	}
	return (toks);
}

static t_wtoklst	*loc_extract_wtok(char const **pword)
{
	if (**pword == '$')
		return (my_wtoklst_handle_dollar(pword));
	if (**pword == '*')
		return (my_wtoklst_handle_ast(pword));
	if (**pword == '\"')
		return (my_wtoklst_handle_dbl_quotes(pword));
	if (**pword == '\'')
		return (my_wtoklst_handle_dbl_quotes(pword));
	return (my_wtoklst_handle_chars(pword));
}
