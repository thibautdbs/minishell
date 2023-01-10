/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_and.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:22:14 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/10 11:40:54 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include <stddef.h>

#include "minishell/token.h"

t_tok	*my_lex_and(char const *input)
{
	if (input[0] == '&')
		return (my_tok_extract(input, 1, TOK_AMP));
	return (NULL);
}
