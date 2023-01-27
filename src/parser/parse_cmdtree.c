/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmdtree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:44:58 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/27 15:30:14 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/cmd.h"
#include "minishell/parser.h"

#include <stddef.h>//NULL

static t_cmdtree	*loc_create_connection_from_tok(char const **pstr);

t_cmdtree	*my_parse_cmdtree(char const **pstr)
{
	t_cmdtree	*tree;
	t_cmdtree	*new_parent;

	tree = my_parse_pipeline(pstr);
	if (tree == NULL)
		return (NULL);
	while (my_tok_type(*pstr) != EOF && my_tok_type(*pstr) != RPAR)
	{
		new_parent = loc_create_connection_from_tok(pstr);
		if (new_parent == NULL)
		{
			my_cmdtree_del(&tree);
			return (NULL);
		}
		new_parent->left = tree;
		tree = new_parent;
		tree->right = my_parse_pipeline(pstr);
		if (tree->right == NULL)
		{
			my_cmdtree_del(&tree);
			return (NULL);
		}
	}
	return (tree);
}

static t_cmdtree	*loc_create_connection_from_tok(char const **pstr)
{
	if (my_tok_type(*pstr) == BARBAR)
		return (my_cmdtree_new(OR));
	else if (my_tok_type(*pstr) == AMPAMP)
		return (my_cmdtree_new(AND));
	return (NULL);
}
