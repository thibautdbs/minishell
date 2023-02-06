/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_extract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:00:35 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/06 15:41:08 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wtoklst.h"

#include <stddef.h>//NULL

#define NTOKENIZER 4

static t_wtoklst	*loc_extract_wtok(char const **pstr);
static void			loc_register_special_chars_tokenizers(
						t_wtokenizer **look_up_tab);

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
	char const		*special_chars = "$*\"\'";
	t_wtokenizer	*special_chars_tokenizers[NTOKENIZER];
	int				i;

	loc_register_special_chars_tokenizers(special_chars_tokenizers);
	i = 0;
	while (i < NTOKENIZER)
	{
		if ((*pword)[0] == special_chars[i])
			return (special_chars_tokenizers[i](pword));
		i++;
	}
	return (my_wtok_handle_chars(pword));
}

static void	loc_register_special_chars_tokenizers(t_wtokenizer **look_up_tab)
{
	look_up_tab[0] = my_wtok_handle_dollar;
	look_up_tab[1] = my_wtok_handle_ast;
	look_up_tab[2] = my_wtok_handle_dbl_quotes;
	look_up_tab[3] = my_wtok_handle_sgl_quotes;
}
