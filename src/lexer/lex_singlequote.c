/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_singlequote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:31:13 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/10 11:48:39 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include <stddef.h>

#include "minishell/token.h"

t_tok	*my_lex_singlequote(char const *input)
{
	if (input[0] == '\'')
		return (my_tok_extract(input, 1, TOK_SGLQT));
	return (NULL);
}
