/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_left_angle_bracket.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:41:27 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 17:46:34 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include "libft.h"
#include "minishell/ctx.h"
#include "minishell/token.h"

t_tok	*my_lex_left_angle_bracket(char const **input)
{
	int const	nchar = ft_strspn(*input, "<");

	if (nchar == 1)
	{
		*input += 1;
		return (my_tok_create(TOK_INPT, "<", 1));
	}
	if (nchar == 2)
	{
		*input += 2;
		return (my_tok_create(TOK_HRDOC, "<<", 2));
	}
	ft_puterr_endl("minishell: syntax error near token `<'");
	g_ctx->exitcode = 2;
	return (NULL);
}
