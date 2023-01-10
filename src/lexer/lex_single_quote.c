/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_single_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:14:48 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/10 17:29:50 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include "libft.h"
#include "minishell/ctx.h"
#include "minishell/token.h"

t_tok	*my_lex_single_quote(char const **input)
{
	int		nchar;
	t_tok	*tok;

	*input += 1;
	nchar = ft_strcspn(*input, "'");
	if (*input[nchar - 1] != '\0' && *input[nchar] == '\'')
	{
		tok = my_tok_create(TOK_WORD, *input, nchar);
		*input += nchar + 1;
		return (tok);
	}
	ft_puterr("minishell: unexpected EOF while looking for matching `''");
	g_ctx->exitcode = 2;
	return (NULL);
}
