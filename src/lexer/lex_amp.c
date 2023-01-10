/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_amp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:14:48 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/10 17:51:47 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include "libft.h"
#include "minishell/ctx.h"
#include "minishell/token.h"

t_tok	*my_lex_amp(char const **input)
{
	if (ft_strncmp("&&", *input, 2) == 0)
	{
		*input += 2;
		return (my_tok_create(TOK_AND, "&&", 2));
	}
	ft_puterr_endl("minishell: syntax error near token `&'");
	g_ctx->exitcode = 2;
	return (NULL);
}
