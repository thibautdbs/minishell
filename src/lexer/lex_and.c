/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_and.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:22:14 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/04 19:49:07 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include <stddef.h>

t_token	*my_lex_and(char const *input)
{
	if (input[0] == '&')
		return (my_tok_extract(input, 1, AND));
	return (NULL);
}
