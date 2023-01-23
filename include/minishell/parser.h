/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:53:40 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/23 18:53:52 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "toks.h"
# include "cmd.h"

# define LEX_ERR -1

////////////////////////////////////////////////////////////////////////////////
/// TYPES

typedef struct s_cmd_or_err
{
	int			err;
	t_cmd		*cmd;
}	t_cmd_or_err;

typedef struct s_redirs_or_err
{
	int			err;
	t_redirs	*redirs;
}	t_redirs_or_err;

typedef struct s_subshell_or_err
{
	int			err;
	t_subshell	*subshell;
}	t_subshell_or_err;

////////////////////////////////////////////////////////////////////////////////
/// FUNCTIONS

t_cmd_or_err		my_parse(t_toks const *toks);

t_cmd_or_err		my_parse_cmd(t_toks const **ptoks);

t_subshell_or_err	my_parse_subshell(t_toks const **ptoks);
t_cmd_or_err		my_parse_cmd_lst(t_toks const **toks, t_cmd *first_cmd,
						t_tok_t type);

void				my_parse_skip_blanks(t_toks const **toks);

#endif
