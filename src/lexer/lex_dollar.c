/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_dollar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:31:07 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/12 17:48:27 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include <stddef.h>

#include "libft.h"
#include "minishell/toks.h"

static int	loc_get_name_len(char const *str);

t_maybe_toks	my_lex_dollar(char const **str)
{
	t_toks	*tok;
	int		len;

	*str += 1;
	if (**str == '?')
	{
		*str += 1;
		tok = my_toks_create(VAR, "?", 1);
	}
	else if (!ft_isalpha(**str) && **str != '_')
	{
		tok = my_toks_create(WORD, "$", 1);
	}
	else
	{
		len = loc_get_name_len(*str);
		tok = my_toks_create(VAR, *str, len);
		*str += len;
	}
	if (tok == NULL)
		return ((t_maybe_toks){.err = MEM_ERR, .toks = NULL});
	return ((t_maybe_toks){.err = NO_ERR, .toks = tok});
}

static int	loc_get_name_len(char const *str)
{
	int		len;

	len = 0;
	while (ft_isdigit(*str) || ft_isalpha(*str) || *str == '_')
	{
		str++;
		len++;
	}
	return (len);
}
