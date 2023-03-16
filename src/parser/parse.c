/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:48:17 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/16 09:42:55 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <errno.h>//errno
#include <stdio.h>//perror
#include <stddef.h>//NULL
#include <stdlib.h>//EXIT_SUCCESS

#include "libft.h"
#include "minishell/tok.h"
#include "minishell/cmd.h"

static void	loc_puterr(t_tok_t type);

/** my_parse:
 *	 Parses str as a t_cmdtree into ret_cmdtree. return exit status.
 */
int	my_parse(char const *str, t_cmdtree **ret_cmdtree)
{
	int	res;

	*ret_cmdtree = NULL;
	if (my_tok_type(str) == EOS)
		return (EXIT_SUCCESS);
	res = my_parse_cmdtree(&str, ret_cmdtree);
	if (res != 0 && res != LEX_ERR)
	{
		perror("minishell");
		my_cmdtree_del(ret_cmdtree);
		return (res);
	}
	if (res == LEX_ERR || my_tok_type(str) != EOS)
	{
		loc_puterr(my_tok_type(str));
		return (LEX_ERR);
	}
	return (EXIT_SUCCESS);
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
