/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:51:17 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/23 15:07:12 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <stddef.h>//NULL

#include "minishell/cmd.h"
#include "minishell/toks.h"

/**
 * Parses subshell.
 *
 * calls my_parse_cmd on tokens between parenthesis.
 * returns error if didn't find matching parenthesis.
 *
 * e.g. input `( t_cmd )` returns t_cmd,
 * whereas input `(t_cmd` returns error.
 */
t_cmd_or_err	my_parse_subshell(t_toks const **ptoks)
{
	t_cmd_or_err	res;

	my_parse_skip_blanks(ptoks);
	if ((*ptoks)->type != LPAR)
		return ((t_cmd_or_err){.err = LEX_ERR, .cmd = NULL});
	(*ptoks)++;
	res = my_parse_cmd(ptoks);
	if (res.err != NO_ERR)
		return ((t_cmd_or_err){.err = res.err, .cmd = NULL});
	my_parse_skip_blanks(ptoks);
	if ((*ptoks)->type != RPAR)
	{
		//put err near unexpected token *ptoks;
		my_cmd_destroy(&res.cmd);
		return ((t_cmd_or_err){.err = LEX_ERR, .cmd = NULL});
	}
	(*ptoks)++;
	return (res);
}
