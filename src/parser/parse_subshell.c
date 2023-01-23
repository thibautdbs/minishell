/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:51:17 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/23 18:52:21 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <errno.h>//ENOMEM
#include <stddef.h>//NULL

#include "minishell/cmd.h"
#include "minishell/toks.h"

static t_cmd_or_err		loc_extract_subcmd(t_toks const **ptoks);
static t_redirs_or_err	loc_extract_redirs(t_toks const **ptoks);

/**
 * Parses subshell.
 *
 * calls my_parse_cmd on tokens between parenthesis.
 * returns error if didn't find matching parenthesis.
 *
 * e.g. input `( t_cmd )` returns t_subshell,
 * whereas input `(t_cmd` returns error.
 */
t_subshell_or_err	my_parse_subshell(t_toks const **ptoks)
{
	t_subshell		*subshell;
	t_cmd_or_err	cmd;
	t_redirs_or_err	redirs;

	subshell = my_cmd_create_subshell();
	if (subshell == NULL)
		return ((t_subshell_or_err){.err = ENOMEM, .subshell = NULL});
	redirs = my_parse_redirs(ptoks);
	if (redirs.err != 0)
		return ((t_subshell_or_err){.err = redirs.err, .subshell = NULL});
	my_redirs_add_back(&subshell->redirs, redirs.redirs);
	cmd = loc_extract_subcmd(ptoks);
	if (cmd.err != 0)
	{
		my_cmd_destroy_subshell(&subshell);
		return ((t_subshell_or_err){.err = cmd.err, .subshell = NULL});
	}
	redirs = my_parse_redirs(ptoks);
	if (redirs.err != 0)
	{
		my_cmd_destroy_subshell(&subshell);
		return ((t_subshell_or_err){.err = redirs.err, .subshell = NULL});
	}
	my_redirs_add_back(&subshell->redirs, redirs.redirs);
	return ((t_subshell_or_err){.err = 0, .subshell = subshell});
}

static t_cmd_or_err	loc_extract_subcmd(t_toks const **ptoks)
{
	t_cmd_or_err	cmd;

	my_parse_skip_blanks(ptoks);
	if ((*ptoks)->type != LPAR)
		return ((t_cmd_or_err){.err = LEX_ERR, .cmd = NULL});
	(*ptoks)++;
	cmd = my_parse_cmd(ptoks);
	if (cmd.err != 0)
		return ((t_cmd_or_err){.err = cmd.err, .cmd = NULL});
	my_parse_skip_blanks(ptoks);
	if ((*ptoks)->type != RPAR)
	{
		//put err near unexpected token *ptoks;
		my_cmd_destroy(&cmd.cmd);
		return ((t_cmd_or_err){.err = LEX_ERR, .cmd = NULL});
	}
	(*ptoks)++;
	return (cmd);
}

static	t_redirs_or_err	loc_extract_redirs(t_toks const **ptoks)
{
	t_redirs_or_err	redir;
	t_redirs		*redirs;

	redirs = NULL;
	my_parse_skip_blanks(ptoks);
	while (my_toks_isredir(*ptoks))
	{
		redir = my_parse_redir(ptoks);
		if (redir.err != 0)
		{
			my_redirs_destroy(&redirs);
			return ((t_redirs_or_err){.err = redir.err, .redirs = NULL});
		}
		my_redirs_add_back(&redirs, redir.redirs);
		my_parse_skip_blanks(ptoks);
	}
	return ((t_redirs_or_err){.err = 0, .redirs = redirs});
}
