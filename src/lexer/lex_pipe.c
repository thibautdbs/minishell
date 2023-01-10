/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:00:14 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 11:47:36 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include <stddef.h>//NULL

#include "minishell/token.h"

t_tok	*my_lex_pipe(char const *input)
{
	if (input[0] == '|')
		return (my_tok_extract(input, 1, TOK_PIPE));
	return (NULL);
}
