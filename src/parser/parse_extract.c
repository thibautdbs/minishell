/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_extract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:49:36 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/06 16:51:51 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include "minishell/arg.h"

#define NCBS 1

t_success	*my_parse_extract(t_token *toks, t_arg **args, t_redir **redir)
{
	int			i
	t_succes	res;
	t_parse_cb 	parse_cbs[NCBS];

	loc_init_parse_cbs(parse_cbs);
	i = 0;
	while (i < NCBS)
	{
		res = parse_cbs[i](toks, args, redir);
		if (res == success)
			return (success);
		i++;
	}
	return (failure);
}

void	loc_init_parse_cbs(t_parse_cb *parse_cbs)
{
//	parce_cbs[0] = my_parse_args;
//	parce_cbs[1] = my_parse_input;
//	parce_cbs[2] = my_parse_heredoc;
//	parce_cbs[3] = my_parse_output;
//	parce_cbs[4] = my_parse_append;
}
