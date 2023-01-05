/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:31:43 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/05 17:43:05 by tdubois          ###   ########.fr       */
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

////////////////////////////////////////////////////////////////////////////////
/// parse_split

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
	int	i;

	toks = toks->next;
	i = 1;
	while (toks != NULL)
	{
		if (toks->type == LEFTPAR)
		{
			i += loc_skip_pars(toks + 1);
			continue ;
		}
		i++;
		if (toks->type == RIGHTPAR)
			break ;
	}
	return (i);
}

static t_cmd	*my_parse_split(t_token *toks)
{
	int	i;

	i = 0;
	while (toks != NULL)
	{
		if (toks->type == LEFTPAR)
			i += loc_skip_pars(toks);
		toks = my_tok_at(toks, i);
		if (toks == NULL)
			return (NULL);
		if (toks->type == AND && toks->next != NULL && toks->next->type == AND)
			return (loc_create(toks, i, 2, CMD_AND));
		if (toks->type == PIPE && toks->next != NULL && toks->next->type == PIPE)
			return (loc_create(toks, i, 2, CMD_OR));
		if (toks->type == PIPE)
			return (loc_create(toks, i, 1, CMD_PIPE));
		toks = toks->next;
	}
	return (NULL);
}


/// end parse_split
////////////////////////////////////////////////////////////////////////////////

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
