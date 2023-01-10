/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:40:48 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/09 17:41:45 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include "libft.h"
#include "minishell/cmd.h"
#include "minishell/token.h"

t_success	my_parse_cmd(t_cmd **cmd, t_token **toks)
{
	t_success	res;
 
	my_parse_skip_spaces(toks);
	if ((*toks)->type == LEFTPAR)
		res = my_parse_cmd_group(cmd, toks);
	else
	 	res = my_parse_args(cmd, toks);
	if (res == failure)
		return (failure);
	my_parse_skip_spaces(toks);
	if (*toks == NULL)
		return (success);
	return (my_parse_split(cmd, toks));
}
