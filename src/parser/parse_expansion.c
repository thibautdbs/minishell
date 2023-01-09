/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:01:15 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/09 12:08:18 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/arg.h"
#include "minishell/token.h"

t_arg	*my_parse_expansion(t_token *toks)
{
	t_token	*garbage;

	


	if (toks->type == SPACES || toks->type == LEFTAGBRACKET
		|| toks->type == RIGHTAGBRACKET)
		return (NULL);
	if (toks->type == WORD)
		return (my_parse_word(toks));
	if (toks->type == DOLLAR)
		return (my_parse_var(toks));
	if (toks->type == WILDCARD)	
		return (my_parse_wildcard(toks));
	if (toks->type == DOUBLEQUOTE)
		return (my_parse_doublequote(toks));
	if (toks->type == SINGLEQUOTE)
		return (my_parse_singlequote(toks));
}
