/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:44:19 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/06 17:00:40 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "libft.h"
#include "token.h"
#include "cmd.h"

typedef t_success   t_parse_cb(t_redir **, t_arg *, t_token *);

t_success   my_parse_quote(t_token *toks);
t_cmd		*my_parse_split(t_token *toks);

#endif //PARSER_H
