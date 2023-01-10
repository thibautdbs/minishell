/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_double_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:14:48 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/10 17:29:52 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include "libft.h"
#include "minishell/ctx.h"
#include "minishell/token.h"

t_tok	*my_lex_double_quote(char const **input)
{
	int		nchar;
	t_tok	*toks;

	*input += 1;
	while (*input[0] != '\0' && *input[0] != '"')
	{
		if (*input[0] == '$')
		{
			my_tok_add_back(&toks, my_lex_dollar(input));
			continue ;
		}
		nchar = ft_strcspn(*input, "$\"");
		my_tok_add_back(&toks, my_tok_create(TOK_WORD, *input, nchar));
		*input += nchar;
	}
	if (*input[0] == '"')
	{
		*input += 1;
		return (toks);
	}
	ft_puterr_endl("minishell: unexpected EOF while looking for matching `\"'");
	g_ctx->exitcode = 2;
	return (NULL);
}
