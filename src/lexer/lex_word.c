/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:14:48 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/10 17:40:44 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include "libft.h"
#include "minishell/token.h"

t_tok	*my_lex_word(char const **input)
{
	int const	nchar = ft_strcspn(*input, "&|<>()$ \"\'");
	t_tok		*tok;

	tok = my_tok_create(TOK_SPCS, *input,nchar);
	*input += nchar;
	return (tok);
}
