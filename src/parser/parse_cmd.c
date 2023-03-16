/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:31:44 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/09 03:09:43 by tdubois          ###   ########.fr       */
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

static int	loc_parse_simple_cmd(char const **pstr, t_cmdlst **ret_cmdlst);

static int	loc_parse_subshell(char const **pstr, t_cmdlst **pcmdlst);
static int	loc_parse_redirs(char const **pstr, t_redirlst **ret_redirlst);

int	my_parse_cmd(char const **pstr, t_cmdlst **ret_cmdlst)
{
	if (my_tok_is_redir_word_or_lpar(*pstr) == false)
	{
		*ret_cmdlst = NULL;
		return (LEX_ERR);
	}
	if (my_tok_type(*pstr) == LPAR)
		return (loc_parse_subshell(pstr, ret_cmdlst));
	return (loc_parse_simple_cmd(pstr, ret_cmdlst));
}

static int	loc_parse_simple_cmd(char const **pstr, t_cmdlst **ret_cmdlst)
{
	int			res;
	t_wordlst	*new_word;
	t_redirlst	*new_redir;

	*ret_cmdlst = my_cmdlst_new(SIMPLECMD);
	if (*ret_cmdlst == NULL)
		return (ENOMEM);
	while (my_tok_is_redir_or_word(*pstr))
	{
		if (my_tok_type(*pstr) == WORD)
		{
			res = my_parse_word(pstr, &new_word);
			my_wordlst_add_back(&(*ret_cmdlst)->words, new_word);
		}
		else
		{
			res = my_parse_redir(pstr, &new_redir);
			my_redirlst_add_back(&(*ret_cmdlst)->redirs, new_redir);
		}
		if (res != 0)
			return (res);
	}
	return (EXIT_SUCCESS);
}

static int	loc_parse_subshell(char const **pstr, t_cmdlst **ret_cmdlst)
{
	int			res;

	*ret_cmdlst = my_cmdlst_new(SUBSHELL);
	if (*ret_cmdlst == NULL)
		return (ENOMEM);
	my_tok_skip_blanks_plus(pstr, 1);
	res = my_parse_cmdtree(pstr, &(*ret_cmdlst)->subcmd);
	if (res != 0)
		return (res);
	if (my_tok_type(*pstr) != RPAR)
		return (LEX_ERR);
	my_tok_skip_blanks_plus(pstr, 1);
	res = loc_parse_redirs(pstr, &(*ret_cmdlst)->redirs);
	if (res != 0)
		return (res);
	return (EXIT_SUCCESS);
}

static int	loc_parse_redirs(char const **pstr, t_redirlst **ret_redirlst)
{
	int			res;
	t_redirlst	*new_redir;

	*ret_redirlst = NULL;
	while (my_tok_is_redir(*pstr))
	{
		res = my_parse_redir(pstr, &new_redir);
		my_redirlst_add_back(ret_redirlst, new_redir);
		if (res != 0)
			return (res);
	}
	return (EXIT_SUCCESS);
}
