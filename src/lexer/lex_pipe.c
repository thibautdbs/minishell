/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:14:48 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/10 17:50:43 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include "libft.h"
#include "minishell/ctx.h"
#include "minishell/token.h"

t_tok	*my_lex_pipe(char const **input)
{
	int const	npipe = ft_strspn(*input, "|");

	if (npipe == 1)
	{
		*input += 1;
		return (my_tok_create(TOK_PIPE, "|", 1));
	}
	if (npipe == 2)
	{
		*input += 2;
		return (my_tok_create(TOK_OR, "||", 2));
	}
	ft_puterr_endl("minishell: syntax error near token `|'");
	g_ctx->exitcode = 2;
	return (NULL);
}
