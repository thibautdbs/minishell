/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:48:17 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/21 14:41:01 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <errno.h>//errno
#include <stdio.h>//perror
#include <stddef.h>//NULL

#include "libft.h"
#include "minishell/tok.h"

static void	loc_puterr(t_tok_t type);

t_cmdtree_or_err	my_parse(char const *str)
{
	t_cmdtree	*tree;

	if (my_tok_type(str) == EOS)
		return ((t_cmdtree_or_err){.err = 0, .cmdtree = NULL});
	errno = 0;
	tree = my_parse_cmdtree(&str);
	if (errno != 0)
	{
		perror("minishell:");
		my_cmdtree_del(&tree);
		return ((t_cmdtree_or_err){.err = errno, .cmdtree = NULL});
	}
	if (tree == NULL || my_tok_type(str) != EOS)
	{
		loc_puterr(my_tok_type(str));
		my_cmdtree_del(&tree);
		return ((t_cmdtree_or_err){.err = LEX_ERR, .cmdtree = NULL});
	}
	return ((t_cmdtree_or_err){.err = 0, .cmdtree = tree});
}

static void	loc_puterr(t_tok_t type)
{
	if (type == EOS)
	{
		ft_puterr_endl("minishell: syntax error: unexpected end of file");
		return ;
	}
	ft_puterr("minishell: syntax error near unexpected token `");
	if (type == LESS)
		ft_puterr("<");
	else if (type == LESSLESS)
		ft_puterr("<<");
	else if (type == GREAT)
		ft_puterr(">");
	else if (type == GREATGREAT)
		ft_puterr(">>");
	else if (type == BAR)
		ft_puterr("|");
	else if (type == BARBAR)
		ft_puterr("||");
	else if (type == AMPAMP)
		ft_puterr("&&");
	else if (type == LPAR)
		ft_puterr("(");
	else if (type == RPAR)
		ft_puterr(")");
	ft_puterr_endl("'");
}
