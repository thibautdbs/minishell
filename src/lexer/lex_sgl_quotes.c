/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_sgl_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:31:07 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/12 17:47:29 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include <stddef.h>

#include "libft.h"
#include "minishell/toks.h"

static void	loc_puterr(void);

t_maybe_toks	my_lex_sgl_quotes(char const **str)
{
	t_toks	*tok;
	int		len;

	*str += 1;
	len = ft_strcspn(*str, "\'");
	if (*str[len] == '\0')
	{
		loc_puterr();
		return ((t_maybe_toks){.err = LEX_ERR, .toks = NULL});
	}
	tok = my_toks_create(WORD, *str, len);
	*str += len + 1;
	if (tok == NULL)
		return ((t_maybe_toks){.err = MEM_ERR, .toks = NULL});
	return ((t_maybe_toks){.err = NO_ERR, .toks = tok});
}

static void	loc_puterr(void)
{
	ft_puterr_endl(
		"minishell: unexpected EOF while looking for matching `\'\'");
	ft_puterr_endl(
		"minishell: syntax error: unexpected end of file");
}
