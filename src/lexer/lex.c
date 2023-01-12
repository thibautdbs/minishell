/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:31:47 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/12 16:16:45 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include <stddef.h>//NULL
#include <limits.h>//CHAR_MAX

#include "libft.h"
#include "minishell/toks.h"

static t_maybe_toks	loc_extract_tok(char const **str);
static void			loc_register_meta_chars_lexers(t_lexer **lexers);

t_maybe_toks	my_lex(char const *str)
{
	t_toks			*toks;
	t_maybe_toks	new;

	toks = NULL;
	while (*str != '\0')
	{
		new = loc_extract_tok(&str);
		if (new.err == NO_ERR)
		{
			my_toks_add_back(&toks, new.toks);
			continue ;
		}
		my_toks_del(&toks);
		return ((t_maybe_toks){.err = new.err, .toks = NULL});
	}
	return ((t_maybe_toks){.err = NO_ERR, .toks = toks});
}

static t_maybe_toks	loc_extract_tok(char const **str)
{
	char const	*meta_chars = "()<>&|$* \t\"\'";
	t_lexer		*meta_chars_lexers[CHAR_MAX];

	loc_register_meta_chars_lexers(meta_chars_lexers);
	if (ft_strchr(meta_chars, **str) != NULL)
		return (meta_chars_lexers[(int)**str](str));
	return (my_lex_word(str));
}

static void	loc_register_meta_chars_lexers(t_lexer **look_up_tab)
{
	look_up_tab['('] = my_lex_lpar;
	look_up_tab[')'] = my_lex_rpar;
	look_up_tab['<'] = my_lex_less;
	look_up_tab['>'] = my_lex_great;
	look_up_tab['&'] = my_lex_amp;
	look_up_tab['|'] = my_lex_bar;
	look_up_tab['$'] = my_lex_dollar;
	look_up_tab['*'] = my_lex_ast;
	look_up_tab[' '] = my_lex_blanks;
	look_up_tab['\t'] = my_lex_blanks;
	look_up_tab['\"'] = my_lex_dbl_quotes;
	look_up_tab['\''] = my_lex_sgl_quotes;
}
