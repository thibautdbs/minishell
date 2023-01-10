/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:33:57 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 11:29:02 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include "libft.h"
#include "minishell/cmd.h"
#include "minishell/token.h"

t_cmd	*my_parse(t_tok *toks)
{
	t_cmd	*cmd;

	if (my_parse_cmd(&cmd, &toks) == FAILURE)
	{
		my_cmd_destroy(&cmd);
		return (NULL);
	}
	my_parse_skip_spaces(&toks);
	if (toks != NULL)//perror
	{
		my_cmd_destroy(&cmd);
		return (NULL);
	}
	return (cmd);
}

