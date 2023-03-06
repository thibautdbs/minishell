/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:30:50 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/03/06 17:14:05 by ffeaugas         ###   ########.fr       */
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

t_cmdtree_or_err	my_parse(char const *str);
t_cmdtree			*my_parse_cmdtree(char const **pstr);
t_cmdtree			*my_parse_pipeline(char const **pstr);
t_cmdlst			*my_parse_cmd(char const **pstr);
t_wordlst			*my_parse_word(char const **pstr);
t_redirlst			*my_parse_redir(char const **pstr);

int					my_parse_heredoc(t_cmdtree *cmd);

void				my_skip_blanks(char const **pstr);

#endif //PARSER_H
