/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:31:44 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/28 02:32:38 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <stddef.h>//NULL

#include "minishell/cmd.h"
#include "minishell/redirlst.h"
#include "minishell/wordlst.h"

static t_redirlst	*loc_parse_redirs(char const **pstr);
static t_redirlst	*loc_parse_subshell(char const **pstr);
static t_redirlst	*loc_parse_simple_cmd(char const **pstr);

t_cmdlst	*my_parse_cmd(char const **pstr)
{
	t_cmdlst	*cmd;
	t_redirlst	*leading_redirs;

	if (my_tok_is_control_operator(*pstr))
		return (NULL);
	if (my_tok_is_redir(*pstr))
	{
		leading_redirs = loc_parse_redirs(pstr);
		if (leading_redirs == NULL)
			return (NULL);
	}
	if (my_tok_is_lpar(*pstr))
		cmd = loc_parse_subshell(pstr);
	else
	 	cmd = loc_parse_simple_cmd(pstr);
	if (cmd == NULL)
	{
		my_redirlst_del(&leading_redirs);
		return (NULL);
	}
	my_redirlst_add_front(&cmd->redirs, leading_redirs);
	return (cmd);
}

static t_redirlst	*loc_parse_redirs(char const **pstr)
{
	t_redirlst	*lst;
	t_redirlst	*new_redir;

	lst == NULL;
	while (my_tok_is_redir(*pstr))
	{
		new_redir = my_parse_redir(pstr);
		if (new_redir == NULL)
		{
			my_redirlst_del(&lst);
			return (NULL);
		}
		my_redirlst_add_back(&lst, new_redir);
	}
	return (lst);
}

static t_cmdlst	*loc_parse_subshell(char const **pstr)
{
//parse all redirs
}

static t_cmdlst	*loc_parse_simple_cmd(char const **pstr)
{
	t_cmdlst	*cmd;
	t_wordlst	*new_word;
	t_redirlst	*new_redir;

	cmd == my_cmdlst_new(SIMPLECMD);
	if (cmd == NULL)
		return (NULL);
	while (my_tok_is_control_operator(*pstr))
	{
		if (my_tok_is_par(*pstr))
		{
			my_cmdlst_del(&lst);
			return (NULL);
		}
		if (my_tok_is_redir(*pstr))
		{
			new_redir = my_parse_redir(pstr);
			if (new_redir == NULL)
			{
				my_cmdlst_del(&cmd);
				return (NULL);
			}
			my_redirlst_add_back(&cmd->redirs, new_redir);
			continue ;
		}
		new_word = my_parse_word(pstr);
		if (new_word == NULL)
		{
			my_cmdlst_del(&cmd);
			return (NULL);
		}
		my_wordlst_add_back(&cmd->words, new_word);
	}
	return (lst);
}
