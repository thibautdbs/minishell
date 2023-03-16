/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:30:50 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/16 13:44:24 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

////////////////////////////////////////////////////////////////////////////////
/// INCLUDE

# include "cmd.h"

////////////////////////////////////////////////////////////////////////////////
/// EXITCODES MACROS

# define LEX_ERR 2

////////////////////////////////////////////////////////////////////////////////
/// SECURE TYPES

typedef struct s_cmdtree_or_err
{
	int			err;
	t_cmdtree	*cmdtree;
}	t_cmdtree_or_err;

////////////////////////////////////////////////////////////////////////////////
/// FUNCTIONS

int		my_parse(char const *str, t_cmdtree **ret_cmdtree);

int		my_parse_cmdtree(char const **pstr, t_cmdtree **ret_cmdtree);
int		my_parse_pipeline(char const **pstr, t_cmdtree **ret_cmdtree);
int		my_parse_cmd(char const **pstr, t_cmdlst **ret_cmdlst);
int		my_parse_word(char const **pstr, t_wordlst **ret_wordlst);
int		my_parse_redir(char const **pstr, t_redirlst **ret_redirlst);

void	my_skip_blanks(char const **pstr);

int		my_parse_heredoc(t_cmdtree *cmd);

#endif //PARSER_H
