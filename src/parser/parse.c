/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:11:22 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/16 16:37:19 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <stddef.h>

#include "minishell/cmd.h"
#include "minishell/toks.h"

t_cmd_or_err	my_parse(t_toks const *toks)
{
	t_cmd_or_err	cmd;

	cmd = my_parse_cmd(&toks);
	if (cmd.err != NO_ERR)//free?
		return ((t_cmd_or_err){.err = cmd.err, .cmd = NULL});
	if (toks != NULL)//perror?
		return ((t_cmd_or_err){.err = LEX_ERR, .cmd = NULL});
	return (cmd);
}

/**
 * Parses simple command or subshell til eof or closing bracket.
 * Then puts it in command list if necessary.
 */
t_cmd_or_err	my_parse_cmd(t_toks const **toks)
{
	t_cmd_or_err	cmd;

	my_parse_skip_blanks(toks);
	if (my_toks_has_type(*toks, (t_tok_t[]){PIPE, AND, OR, RPAR}, 4))
		return ((t_cmd_or_err){.err = LEX_ERR, .cmd = NULL});//free?
	cmd = my_parse_subshell_or_smpl_cmd();
	if (cmd.err != NO_ERR)
		return ((t_cmd_or_err){.err = cmd.err, .cmd = NULL});//free?
	my_parse_skip_blanks(toks);
	if (*toks == NULL || (*toks)->type == RPAR)
		return (cmd);
	return (my_parse_cmd_lst(toks, cmd.cmd, (*toks)->type));
}
