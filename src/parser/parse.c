/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:11:22 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/14 03:27:05 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <stddef.h>

#include "minishell/cmd.h"
#include "minishell/toks.h"

t_cmd	*my_parse(t_toks const *toks)
{
	t_cmd	*cmd;

	cmd = my_parse_cmd(&toks);
	if (toks != NULL)
		return (error);
	return (cmd);
}

t_cmd	*my_parse_cmd(t_toks const **toks)
{
	t_cmd	*cmd;

	my_parse_skip_blanks(toks);
	if (my_toks_has_type(*toks, (t_tok_t[]){PIPE, AND, OR, RPAR}), 4)
		//RETURN ERROR	
	cmd = my_parse_subshell_or_smpl_cmd();
	//return if error.
	my_parse_skip_blanks(toks);
	if (*toks == NULL)
		return (cmd);
	return (my_parse_cmd_lst(toks, cmd, (*toks)->type));
}

t_cmd	*my_parse_cmd_lst(t_toks **toks, t_cmd *first_cmd, t_tok_t type)
{
	t_cmd	*cmd_lst;
	t_cmd	*cmd;

	cmd_lst = my_cmd_create_lst(type);
	//return if err;
	my_cmd_lst_add_back(cmd_lst, first_cmd);
	while ((*toks)->type == type)
	{
		*toks = (*toks)->next;
		cmd = my_parse_subshell_or_smpl_cmd(toks);
		//return if error
		my_cmd_lst_add_back(cmd_lst, cmd);
		my_parse_skip_blanks(toks);
	}
	if (*toks == NULL)
		return (cmd);
	return (my_parse_cmd_lst(toks, cmd, (*toks)->type));
}
