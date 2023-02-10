/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:40:25 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/10 12:52:36 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <stddef.h>//NULL

#include "minishell/cmd.h"
#include "minishell/tok.h"

t_cmdtree	*my_parse_pipeline(char const **pstr)
{
	t_cmdtree	*pipeline;
	t_cmdlst	*new_cmd;

	pipeline = my_cmdtree_new(PIPELINE);
	if (pipeline == NULL)
		return (NULL);
	while (1)
	{
		new_cmd = my_parse_cmd(pstr);
		if (new_cmd == NULL)
		{
			my_cmdtree_del(&pipeline);
			return (NULL);
		}
		my_cmdlst_add_back(&pipeline->pipeline, new_cmd);
		if (my_tok_type(*pstr) != BAR)
			break ;
		my_tok_skip_blanks_plus(pstr, 1);
	}
	return (pipeline);
}
