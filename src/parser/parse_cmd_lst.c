/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:39:58 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/16 17:46:15 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <stddef.h>//NULL

#include "minishell/cmd.h"
#include "minishell/toks.h"

static t_cmd_or_err	loc_create_list(t_tok_t type, t_cmd *first_cmd);

t_cmd_or_err	my_parse_cmd_lst(t_toks const **toks, t_cmd *first_cmd,
					t_tok_t type)
{
	t_cmd_or_err	cmd_lst;
	t_cmd_lst		*next_cmd;

	cmd_lst = loc_create_list(type, first_cmd);
	//return if err;
	while (*toks != NULL && (*toks)->type == type)
	{
		*toks = (*toks)->next;
		next_cmd = my_parse_subshell_or_smpl_cmd_as_lst(toks);
		//return if error
		my_cmd_lst_add_back(&cmd_lst.cmd->val.as_cmd_lst, next_cmd);
		my_parse_skip_blanks(toks);
	}
	if (*toks == NULL)
		return (cmd_lst);
	return (my_parse_cmd_lst(toks, cmd_lst.cmd, (*toks)->type));
}

static t_cmd_lst	*loc_parse_subshell_or_smpl_cmd_as_lst(t_toks const **toks)
{
	t_cmd_or_err	cmd;

	cmd = my_parse_subshell_or_smpl_cmd(toks);
	if (cmd.err != NO_ERR)
}

static t_cmd_or_err	loc_create_list(t_tok_t type, t_cmd *first_cmd)
{
	t_cmd			*cmd_lst;
	t_cmd_lst		*first_node;

	if (type == OR)
		cmd_lst = my_cmd_create(CMD_ORLST);
	else if (type == AND)
		cmd_lst = my_cmd_create(CMD_ANDLST);
	else
		cmd_lst = my_cmd_create(CMD_PIPELST);
	if (cmd_lst == NULL)
		return ((t_cmd_or_err){.err = MEM_ERR, .cmd = NULL});
	first_node = my_cmd_lst_create(first_cmd);
	my_cmd_lst_add_back(&cmd_lst->val.as_cmd_lst, first_node);
	return ((t_cmd_or_err){.err = NO_ERR, .cmd = cmd_lst});
}
