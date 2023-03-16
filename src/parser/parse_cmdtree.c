/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmdtree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:44:58 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/09 01:13:42 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <asm-generic/errno-base.h>
#include <stddef.h>//NULL
#include <stdlib.h>//EXIT_SUCCESS

#include "minishell/cmd.h"
#include "minishell/tok.h"

static int	loc_parse_connection(char const **pstr, t_cmdtree **ret_cmdtree);

int	my_parse_cmdtree(char const **pstr, t_cmdtree **ret_cmdtree)
{
	int			res;
	t_cmdtree	*new_parent;

	*ret_cmdtree = NULL;
	res = my_parse_pipeline(pstr, ret_cmdtree);
	if (res != 0)
		return (res);
	while (my_tok_type(*pstr) != EOS && my_tok_type(*pstr) != RPAR)
	{
		res = loc_parse_connection(pstr, &new_parent);
		if (res != EXIT_SUCCESS)
			return (res);
		new_parent->left = *ret_cmdtree;
		*ret_cmdtree = new_parent;
		res = my_parse_pipeline(pstr, &(*ret_cmdtree)->right);
		if (res != EXIT_SUCCESS)
			return (res);
	}
	return (EXIT_SUCCESS);
}

static int	loc_parse_connection(char const **pstr, t_cmdtree **ret_cmdtree)
{
	*ret_cmdtree = NULL;
	if (my_tok_type(*pstr) == BARBAR)
	{
		my_tok_skip_blanks_plus(pstr, 2);
		*ret_cmdtree = my_cmdtree_new(OR);
	}
	else if (my_tok_type(*pstr) == AMPAMP)
	{
		my_tok_skip_blanks_plus(pstr, 2);
		*ret_cmdtree = my_cmdtree_new(AND);
	}
	else
	{
		return (LEX_ERR);
	}
	if (*ret_cmdtree == NULL)
		return (ENOMEM);
	return (EXIT_SUCCESS);
}
