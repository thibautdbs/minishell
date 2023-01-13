/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_blanks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:31:07 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/13 19:06:12 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include <stddef.h>

#include "libft.h"
#include "minishell/toks.h"

t_maybe_toks	my_lex_blanks(char const **str)
{
	t_toks	*tok;
	int		len;

	len = ft_strspn(*str, " \t");
	*str += len;
	tok = my_toks_create(BLANKS, " ", 1);
	if (tok == NULL)
		return ((t_maybe_toks){.err = MEM_ERR, .toks = NULL});
	return ((t_maybe_toks){.err = NO_ERR, .toks = tok});
}
