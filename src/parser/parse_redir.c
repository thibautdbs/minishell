/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:24:57 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/30 16:48:39 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <stddef.h>//NULL

#include "minishell/cmd.h"
#include "minishell/redirlst.h"
#include "minishell/wordlst.h"

static t_redirlst_t	loc_parse_redir_type(char const **pstr);

t_redirlst	*my_parse_redir(char const **pstr)
{
	t_redirlst	*redir;

	redir = my_redirlst_new();
	if (redir == NULL)
		return (NULL);
	redir->type = loc_parse_redir_type(pstr);
	if (!my_tok_is_word(*pstr))
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
	if (ft_strcmp(*pstr, "<<") == 0)
	{
		pstr += 2;
		return (HEREDOC);
	}
	if (ft_strcmp(*pstr, ">>") == 0)
	{
		pstr += 2;
		return (APPND);
	}
	if (ft_strcmp(*pstr, "<") == 0)
	{
		pstr += 1;
		return (INFILE);
	}
	pstr += 1;
	return (OUTFILE);
}
