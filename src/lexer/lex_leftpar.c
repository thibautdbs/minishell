/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_leftpar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:31:13 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/10 11:46:40 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include <stddef.h>

#include "minishell/token.h"

t_tok	*my_lex_leftpar(char const *input)
{
	if (input[0] == '(')
		return (my_tok_extract(input, 1, TOK_LPAR));
	return (NULL);
}
