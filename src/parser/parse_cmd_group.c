/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_group.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:41:54 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 12:00:59 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include "libft.h"
#include "minishell/cmd.h"
#include "minishell/token.h"

t_success	loc_parse_cmd_group(t_cmd **cmd, t_tok **toks)
{
	*toks = (*toks)->next;
	if (*toks == NULL)//perror
		return (FAILURE);
	if (my_parse_cmd(cmd, toks) == FAILURE)
		return (FAILURE);
	my_parse_skip_spaces(toks);
	if (*toks == NULL || (*toks)->type != TOK_RPAR)
		return (FAILURE);
	*toks = (*toks)->next;
	return (SUCCESS);
}
