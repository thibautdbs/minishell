/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_dbl_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:31:07 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/12 17:51:05 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include <stddef.h>

#include "libft.h"
#include "minishell/toks.h"

static void			loc_puterr(void);
static t_maybe_toks	loc_lex_qtd_word(char const **str);
static t_maybe_toks	loc_lex_qtd_var(char const **str);

t_maybe_toks	my_lex_dbl_quotes(char const **str)
{
	t_toks			*toks;
	t_maybe_toks	new;

	toks = NULL;
	while (**str != '\"' && **str != '\0')
	{
		if (**str == '$')
			new = loc_lex_qtd_var(str);
		else
			new = loc_lex_qtd_word(str);
		if (new.err != NO_ERR)
		{
			my_toks_del(&toks);
			return (new);
		}
		my_toks_add_back(&toks, new.toks);
	}
	if (**str == '\0')
	{
		my_toks_del(&toks);
		loc_puterr();
		return ((t_maybe_toks){.err = LEX_ERR, .toks = NULL});
	}
	return ((t_maybe_toks){.err = NO_ERR, .toks = toks});
}

static void	loc_puterr(void)
{
	ft_puterr_endl(
		"minishell: unexpected EOF while looking for matching `\"\'");
	ft_puterr_endl(
		"minishell: syntax error: unexpected end of file");
}

static t_maybe_toks	loc_lex_qtd_word(char const **str)
{
	t_toks	*tok;
	int		len;

	len = ft_strcspn(*str, "$\"");
	tok = my_toks_create(WORD, *str, len);
	*str += len;
	if (tok == NULL)
		return ((t_maybe_toks){.err = MEM_ERR, .toks = NULL});
	return ((t_maybe_toks){.err = NO_ERR, .toks = tok});
}

static t_maybe_toks	loc_lex_qtd_var(char const **str)
{
	t_maybe_toks	tok;

	tok = my_lex_dollar(str);
	if (tok.err == NO_ERR)
		tok.toks->type = QTD_VAR;
	return (tok);
}
