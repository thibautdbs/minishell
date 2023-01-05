/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:31:43 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/05 14:12:28 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <errno.h>

#include "libft.h"
#include "minishell/cmd.h"
#include "minishell/token.h"

t_cmd	*my_parse(t_token *toks)
{
	t_cmd		cmd;
	t_token		*left;
	t_token		*right;
	t_success	res;

	if (my_parse_is_exec(toks))
		return (my_parse_exec(toks));
	res = my_tok_split(toks, &cmd->left, &right);
	if (res == success)
	{
		cmd.type = ...;
		cmd.left = my_parse(left);
		cmd.right = my_parse(right);
		return (cmd);
	}
	else if (my_tok_at(toks, 0)->type == LEFTPAR && my_tok_at(toks, -1)->type == RIGHTPAR)
	{
		return (my_parse(my_tok_slice(toks, 1, -1)));
	}
	errno = MY_ENOPARSE;
	return (NULL);
}
