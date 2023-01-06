/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:31:43 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/06 08:58:26 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <errno.h>

#include "libft.h"
#include "minishell/cmd.h"
#include "minishell/token.h"

// static t_cmd	*my_parse_exec(t_token *toks)
// {
// 	t_token_type const	reject[4] = {PIPE, AND, LEFTPAR, RIGHTPAR};
//
// 	if (my_tok_contains(toks, reject, 4))
// 		return (NULL);
//
// }


t_cmd	*my_parse(t_token *toks)
{
	t_cmd	*cmd = ft_calloc(1,sizeof(t_cmd));
	(void)toks;
	return (cmd);
}

// t_cmd	*my_parse(t_token *toks)
// {
// 	t_cmd	*cmd;
//
// 	cmd = my_parse_exec(toks);
// 	if (cmd != NULL)
// 		return (cmd);
// 	cmd = my_parse_split(toks);
// 	if (cmd != NULL)
// 		return (cmd);
// 	if (my_tok_at(toks, 0)->type == LEFTPAR && my_tok_at(toks, -1)->type == RIGHTPAR)
// 	{
// 		my_tok_pop_front(&toks);
// 		my_tok_pop_back(&toks);
// 		return (my_parse(toks));
// 	}
// 	errno = MY_ENOPARSE;
// 	return (NULL);
// }
