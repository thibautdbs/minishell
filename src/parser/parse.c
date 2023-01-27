/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:48:17 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/27 15:35:12 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <errno.h>//errno
#include <stdio.h>//perror
#include <stddef.h>//NULL

t_cmdtree_or_err	my_parse(char const *str)
{
	t_cmdtree	*tree;

	if (my_tok_type(str) == EOF)
		return ((t_cmdtree_or_err){.err = 0, .cmdtree = NULL});
	errno = 0;
	tree = my_parse_cmdtree(&str);
	if (errno != 0)
	{
		perror("minishell:");
		my_cmdtree_del(&tree);
		return ((t_cmdtree_or_err){.err = errno, .cmdtree = NULL});
	}
	if (tree == NULL || my_tok_type(str) != EOF)
	{
		//put error near token my_tok_type(inputline)
		my_cmdtree_del(&tree);
		return ((t_cmdtree_or_err){.err = LEX_ERR, .cmdtree = NULL});
	}
	return ((t_cmdtree_or_err){.err = 0, .cmdtree = tree});
}
