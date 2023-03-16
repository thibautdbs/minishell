/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:24:57 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/09 01:49:06 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <stddef.h>//NULL
#include <errno.h>//ENOMEM
#include <stdlib.h>//EXIT_SUCCESS

#include "minishell/cmd.h"
#include "minishell/redirlst.h"
#include "minishell/tok.h"
#include "minishell/wordlst.h"

static t_redirlst_t	loc_parse_redir_type(char const **pstr);

int	my_parse_redir(char const **pstr, t_redirlst **ret_redirlst)
{
	int	res;

	*ret_redirlst = my_redirlst_new(loc_parse_redir_type(pstr));
	if (*ret_redirlst == NULL)
		return (ENOMEM);
	if (my_tok_type(*pstr) != WORD)
	{
		my_redirlst_del(ret_redirlst);
		return (LEX_ERR);
	}
	res = my_parse_word(pstr, &(*ret_redirlst)->word);
	if (res != EXIT_SUCCESS)
	{
		my_redirlst_del(ret_redirlst);
		return (res);
	}
	return (EXIT_SUCCESS);
}

static t_redirlst_t	loc_parse_redir_type(char const **pstr)
{
	t_tok_t const	type = my_tok_type(*pstr);

	my_tok_skip_blanks(pstr);
	if (type == LESSLESS)
	{
		*pstr += 2;
		return (HEREDOC);
	}
	if (type == GREATGREAT)
	{
		*pstr += 2;
		return (APPND);
	}
	if (type == LESS)
	{
		*pstr += 1;
		return (INFILE);
	}
	*pstr += 1;
	return (OUTFILE);
}
