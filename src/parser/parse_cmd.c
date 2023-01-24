/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:45:44 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/24 17:42:13 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <stddef.h>//NULL

#include "minishell/cmd.h"
#include "minishell/toks.h"

/**
 * Parses compound command.
 *
 * recursively extracts subshell or simple command and adds it in
 * cmd_list if encounters metachar afterward.
 * Stops on EOF and RPAR.
 *
 * e.g. would consume whole "(cmd1 | cmd2 || cmd3) && cmd4",
 * but would consume "(cmd1 | cmd2 || cmd3) && cmd4 ) | cmd5" only til
 * second closing parenthesis.
 */
t_cmd_or_err	my_parse_cmd(t_toks const **ptoks)
{
	t_cmd_or_err	res;

	my_parse_skip_blanks(ptoks);
	if ((*ptoks)->type == LPAR)//is_subshell: iterate over toks til EOF or CONTROL_CHAR
		res = my_parse_subshell(ptoks);
	else
	 	res = my_parse_smpl_cmd(ptoks);
	if (res.err != NO_ERR)
		return ((t_cmd_or_err){.err = res.err, .cmd = NULL});
	my_parse_skip_blanks(ptoks);
	if (*ptoks == NULL || (*ptoks)->type == RPAR)
		return (res);
	return (my_parse_cmd_lst(ptoks, res.cmd, (*ptoks)->type));
}
