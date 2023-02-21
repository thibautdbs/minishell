/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:24:57 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/21 08:19:58 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <stddef.h>//NULL

#include "minishell/cmd.h"
#include "minishell/redirlst.h"
#include "minishell/tok.h"
#include "minishell/wordlst.h"

static t_redirlst_t	loc_parse_redir_type(char const **pstr);

t_redirlst	*my_parse_redir(char const **pstr)
{
	t_redirlst	*redir;

	redir = my_redirlst_new(loc_parse_redir_type(pstr));
	if (redir == NULL)
		return (NULL);
	if (my_tok_type(*pstr) != WORD)
	{
		my_redirlst_del(&redir);
		return (NULL);
	}
	redir->word = my_parse_word(pstr);
	if (redir->word == NULL)
	{
		my_redirlst_del(&redir);
		return (NULL);
	}
	return (redir);
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
