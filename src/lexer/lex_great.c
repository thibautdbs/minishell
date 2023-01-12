/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_great.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:31:07 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/12 17:48:37 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include <stddef.h>

#include "libft.h"
#include "minishell/toks.h"

t_maybe_toks	my_lex_great(char const **str)
{
	t_toks	*tok;

	if (ft_strncmp(">>", *str, 2) == 0)
	{
		*str += 2;
		tok = my_toks_create(APPNDFILE, ">>", 2);
	}
	else
	{
		*str += 1;
		tok = my_toks_create(OUTFILE, ">", 1);
	}
	if (tok == NULL)
		return ((t_maybe_toks){.err = MEM_ERR, .toks = NULL});
	return ((t_maybe_toks){.err = NO_ERR, .toks = tok});
}
