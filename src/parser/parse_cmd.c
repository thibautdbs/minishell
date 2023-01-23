/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:45:44 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/23 14:47:47 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <stddef.h>//NULL

#include "minishell/cmd.h"
#include "minishell/toks.h"

/**
 * Parses simple command or subshell til eof or closing bracket.
 * Then puts it in command list if necessary.
 */
t_cmd_or_err	my_parse_cmd(t_toks const **ptoks)
{
	t_cmd_or_err	res;

	my_parse_skip_blanks(ptoks);
	if (my_toks_has_type(*ptoks, (t_tok_t[]){PIPE, AND, OR, RPAR}, 4))
		return ((t_cmd_or_err){.err = LEX_ERR, .cmd = NULL});
	res = my_parse_subshell_or_smpl_cmd();
	if (res.err != NO_ERR)
		return ((t_cmd_or_err){.err = res.err, .cmd = NULL});
	my_parse_skip_blanks(ptoks);
	if (*ptoks == NULL || (*ptoks)->type == RPAR)
		return (res);
	return (my_parse_cmd_lst(ptoks, res.cmd, (*ptoks)->type));
}
