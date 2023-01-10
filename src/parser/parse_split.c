/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:43:33 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/09 17:45:05 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include "libft.h"
#include "minishell/cmd.h"
#include "minishell/token.h"

static t_success	loc_parse_or_token(t_token **toks);
static t_success	loc_parse_and_token(t_token **toks);
static t_success	loc_parse_pipe_token(t_token **toks);

t_success	my_parse_split(t_cmd **cmd, t_token **toks)
{
	t_cmd		*parent;
	t_cmd_type	type;

	if (loc_parse_or_token(toks) == success)
		type = CMD_OR;
	else if (loc_parse_and_token(toks) == success)
		type = CMD_AND;
	else if (loc_parse_pipe_token(toks) == success)
		type = CMD_PIPE;
	else//perror
		return (failure);
	parent = my_cmd_create(type);
	if (parent == NULL)
		return (failure);
	parent->left = *cmd;
	*cmd = parent;
	return (my_parse_cmd(&parent->right, toks));
}
