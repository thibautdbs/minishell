/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:00:14 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/04 18:10:35 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include <stddef.h>//NULL

t_token	*my_lex_pipe(char const *input)
{
	if (input[0] == '|')
		return (my_tok_extract(input, 1, PIPE));
	return (NULL);
}
