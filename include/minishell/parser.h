/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:49:44 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/27 15:39:04 by tdubois          ###   ########.fr       */
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

typedef struct	s_cmdtree_or_err
{
	int			err;
	t_cmdtree	*cmdtree;
}	t_cmdtree_or_err;

////////////////////////////////////////////////////////////////////////////////
/// FUNCTIONS

t_cmdtree_or_err	my_parse(char const *str);
t_cmdtree			*my_parse_cmdtree(char const **pstr);

#endif //PARSER_H
