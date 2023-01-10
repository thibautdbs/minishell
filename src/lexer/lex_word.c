/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:57:36 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 11:49:04 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include <stddef.h>//size_t, NULL

#include "libft.h"
#include "minishell/token.h"

t_tok	*my_lex_word(char const *input)
{
	size_t	len;

	len = ft_strcspn(input, "()|<> &\'\"");
	if (len == 0)
		return (NULL);
	return (my_tok_extract(input, len, TOK_WORD));
}
