/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:11:22 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/23 14:35:03 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <stddef.h>//NULL

#include "minishell/cmd.h"
#include "minishell/toks.h"

/**
 * Parses whole command line.
 */
t_cmd_or_err	my_parse(t_toks const *toks)
{
	t_cmd_or_err	cmd;

	cmd = my_parse_cmd(&toks);
	if (cmd.err != NO_ERR)
		return ((t_cmd_or_err){.err = cmd.err, .cmd = NULL});
	if (toks != NULL)
	{
		//put error near token *toks;
		return ((t_cmd_or_err){.err = LEX_ERR, .cmd = NULL});
	}
	return (cmd);
}