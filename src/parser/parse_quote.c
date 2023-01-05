/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:41:29 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/05 14:51:55 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include "minishell/token.h"
#include "libft.h"

static t_success	loc_parse_doublequote(t_token *toks);
static t_success	loc_parse_singlequote(t_token *toks);

/**
 *	switch types tokens surrounded by quotes to word
 */
t_success			my_parse_quote(t_token *toks)
{
	while (toks != NULL)
	{
		if (toks->type == SINGLEQUOTE)
			return (loc_parse_singlequote(toks->next));
		else if (toks->type == DOUBLEQUOTE)
			return (loc_parse_doublequote(toks->next));
		toks = toks->next;
	}
	return (success);
}

static t_success	loc_parse_doublequote(t_token *toks)
{
	while (toks != NULL)
	{
		if (toks->type == DOUBLEQUOTE)
			return (my_parse_quote(toks->next));
		toks->type = WORD;
		toks = toks->next;
	}
	return (failure);
}

static t_success	loc_parse_singlequote(t_token *toks)
{
	while (toks != NULL)
	{
		if (toks->type == SINGLEQUOTE)
			return (my_parse_quote(toks->next));
		toks->type = WORD;
		toks = toks->next;
	}
	return (failure);
}
