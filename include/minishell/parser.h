/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:44:19 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 11:29:02 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "token.h"
# include "cmd.h"

////////////////////////////////////////////////////////////////////////////////
/// PUBLIC

t_cmd		*my_parse(t_tok *toks);

////////////////////////////////////////////////////////////////////////////////
/// PRIVATE

/**
 *	Constructs command tree.
 *	Consumes *toks.
 */
t_success	my_parse_cmd(t_cmd **cmd, t_tok **toks);

t_success	my_parse_cmd_group(t_cmd **cmd, t_tok **toks);
t_success	my_parse_split(t_cmd **cmd, t_tok **toks);
t_success	my_parse_args(t_cmd	**cmd, t_tok **toks);

void		my_parse_skip_spaces(t_tok **toks);

#endif //PARSER_H
