/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:40:25 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/09 01:09:19 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <stddef.h>//NULL
#include <errno.h>//ENOMEM
#include <stdlib.h>//EXIT_SUCCESS

#include "minishell/cmd.h"
#include "minishell/tok.h"

int	my_parse_pipeline(char const **pstr, t_cmdtree **ret_cmdtree)
{
	int			res;
	t_cmdlst	*new_cmd;

	*ret_cmdtree = my_cmdtree_new(PIPELINE);
	if (*ret_cmdtree == NULL)
		return (ENOMEM);
	while (1)
	{
		res = my_parse_cmd(pstr, &new_cmd);
		my_cmdlst_add_back(&(*ret_cmdtree)->pipeline, new_cmd);
		if (res != EXIT_SUCCESS)
			return (res);
		if (my_tok_type(*pstr) != BAR)
			break ;
		my_tok_skip_blanks_plus(pstr, 1);
	}
	return (EXIT_SUCCESS);
}
