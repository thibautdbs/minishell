/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:30:50 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/02/06 12:31:08 by ffeaugas         ###   ########.fr       */
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

void	my_skip_blanks(char const **pstr);

#endif //PARSER_H
