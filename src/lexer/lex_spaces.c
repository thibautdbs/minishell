/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_spaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:57:36 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 11:48:52 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include <stddef.h>

#include "libft.h"
#include "minishell/token.h"

t_tok	*my_lex_spaces(char const *input)
{
	size_t	len;

	len = ft_strspn(input, " ");
	if (len == 0)
		return (NULL);
	return (my_tok_extract(input, len, TOK_SPACES));
}
