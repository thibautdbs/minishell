/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:28:44 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/06 17:39:38 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include "libft.h"
#include "minishell/cmd.h"
#include "minishell/arg.h"

t_cmd	*my_parse_exec(t_token *toks)
{
	t_cmd		*cmd;
	t_arg		*args;	
	t_success	res;

	cmd = ft_calloc(sizeof(t_cmd), 1);
	if (cmd == NULL)
		return (NULL);
	res = my_parse_extract(toks, &args, &cmd->redirs);
	if (res == failure)
	{
		ft_memdel(&cmd);
		return (NULL);
	}
	// fill args
	// free args	
}
