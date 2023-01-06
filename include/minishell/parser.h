/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:44:19 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/06 08:50:31 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "libft.h"
#include "token.h"
#include "cmd.h"

t_success   my_parse_quote(t_token *toks);
t_cmd		*my_parse_split(t_token *toks);

#endif //PARSER_H
