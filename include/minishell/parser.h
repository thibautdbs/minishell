/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:44:19 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/06 17:41:57 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "libft.h"
#include "token.h"
#include "arg.h"
#include "cmd.h"

typedef t_success   t_parse_cb(t_token *, t_redir **, t_arg **);

t_success   my_parse_quote(t_token *toks);
t_cmd		*my_parse_split(t_token *toks);
t_success	my_parse_extract(t_token *toks, t_arg **args, t_redir **redir);

#endif //PARSER_H
