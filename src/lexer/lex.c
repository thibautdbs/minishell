/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:14:02 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/12 00:41:42 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/lexer.h"

#include <stddef.h>

#include "libft.h"
#include "minishell/toks.h"

static t_toks	*loc_extract_tok(char const **str);

t_toks	*my_lex(char const *str)
{
	t_toks	*toks;
	t_toks	*tok;

	toks = NULL;
	while (*str != '\0')
	{
		tok = loc_extract_tok(&str);
		if (tok == NULL)
		{
			my_toks_destroy(&toks);
			return (NULL);
		}
		my_toks_add_back(&toks, tok);
	}
	return (toks);
}

static t_toks	*loc_extract_tok(char const **str)
{
	*str += ft_strspn(*str, " \t");
	if (ft_strncmp("(", *str, 1) == 0)
		return (my_lex_extract_metachars(str, LPAR, 1));
	if (ft_strncmp(")", *str, 1) == 0)
		return (my_lex_extract_metachars(str, RPAR, 1));
	if (ft_strncmp("<<", *str, 2) == 0)
		return (my_lex_extract_metachars(str, LESSLESS, 2));
	if (ft_strncmp("<", *str, 1) == 0)
		return (my_lex_extract_metachars(str, LESS, 1));
	if (ft_strncmp(">>", *str, 2) == 0)
		return (my_lex_extract_metachars(str, GREATGREAT, 2));
	if (ft_strncmp(">", *str, 1) == 0)
		return (my_lex_extract_metachars(str, GREAT, 1));
	if (ft_strncmp("&&", *str, 2) == 0)
		return (my_lex_extract_metachars(str, ANDAND, 2));
	if (ft_strncmp("||", *str, 2) == 0)
		return (my_lex_extract_metachars(str, BARBAR, 2));
	if (ft_strncmp("|", *str, 1) == 0)
		return (my_lex_extract_metachars(str, BAR, 1));
	return (my_lex_extract_word(str));
}
