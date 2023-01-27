/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:31:44 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/27 17:57:31 by tdubois          ###   ########.fr       */
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

	if (my_tok_is_redir(pstr))
	{
		leading_redir = loc_parse_redirs(pstr);
		if (leading_redir == NULL)
		{
			my_cmdlst_del(&cmd);
			return (NULL);
		}
		my_redir_add_back(&cmd->redirs, leading_redir);
	}
	if (my_tok_type(*pstr) == LPAR)
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
//parse all redirs
}

static t_redirlst	*loc_parse_subshell(char const **pstr)
{
//parse all redirs
}

static t_redirlst	*loc_parse_simple_cmd(char const **pstr)
{
//parse all redirs
}
