/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_leftpar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:31:13 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/04 20:19:17 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include <stddef.h>

#include "minishell/token.h"

t_token	*my_lex_leftpar(char const *input)
{
	if (input[0] == '(')
		return (my_tok_extract(input, 1, LEFTPAR));
	return (NULL);
}
