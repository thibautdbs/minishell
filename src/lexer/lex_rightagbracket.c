/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_rightagbracket.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:31:13 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/04 20:19:43 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include <stddef.h>

#include "minishell/token.h"

t_token	*my_lex_rightagbracket(char const *input)
{
	if (input[0] == '>')
		return (my_tok_extract(input, 1, RIGHTAGBRACKET));
	return (NULL);
}
