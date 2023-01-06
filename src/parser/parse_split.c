/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 08:48:04 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/06 13:59:26 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <stddef.h>//NULL

#include "minishell/cmd.h"
#include "minishell/token.h"

static t_cmd	*loc_create(t_token *toks, int idx, int size, t_cmd_type type);
static int		loc_skip_pars(t_token *toks);

t_cmd	*my_parse_split(t_token *toks)
{
	int		i;
	t_token	*curr;

	i = 0;
	curr = toks;
	while (curr != NULL)
	{
		if (curr->type == LEFTPAR)
			i += loc_skip_pars(curr);
		curr = my_tok_at(toks, i);
		if (curr == NULL)
			return (NULL);
		if (curr->type == AND && curr->next != NULL && curr->next->type == AND)
			return (loc_create(toks, i, 2, CMD_AND));
		if (curr->type == PIPE && curr->next != NULL && curr->next->type == PIPE)
			return (loc_create(toks, i, 2, CMD_OR));
		if (curr->type == PIPE)
			return (loc_create(toks, i, 1, CMD_PIPE));
		curr = curr->next;
		i++;
	}
	return (NULL);
}

static t_cmd	*loc_create(t_token *toks, int idx, int size, t_cmd_type type)
{
	t_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->type = type;
	cmd->right = my_parse(my_tok_at(toks, idx + size));
	my_tok_at(toks, idx - 1)->next = NULL;
	cmd->left = my_parse(toks);
	return (cmd);
}

static int	loc_skip_pars(t_token *toks)
{
	int		i;
	t_token	*curr;

	curr = toks->next;
	i = 1;
	while (curr != NULL)
	{
		if (curr->type == LEFTPAR)
		{
			i += loc_skip_pars(curr);
			curr = my_tok_at(toks, i);
			continue ;
		}
		i++;
		if (curr->type == RIGHTPAR)
			break ;
		curr = curr->next;
	}
	return (i);
}
