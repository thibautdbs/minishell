/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_dollar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:14:48 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/10 17:12:33 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include "libft.h"
#include "minishell/ctx.h"
#include "minishell/token.h"

t_tok	*my_lex_dollar(char const **input)
{
	int 	nchar;
	t_tok	*tok;

	*input += 1;
	if (*input[0] == '?')
		nchar = 1;
	else
		nchar = ft_strcspn(*input, "()<>*'? &|$\"");
	if (nchar > 0)
	{
		*input += nchar;
		tok = my_tok_create(TOK_VAR, *input, nchar);
		return (tok);
	}
	return (my_tok_create(TOK_WORD, "$", 1));
}
