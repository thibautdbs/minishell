/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:48:17 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/26 19:27:50 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <stddef.h>//NULL

t_cmdtree_or_err	my_parse(char const *str)
{
	t_cmdtree_or_err	res;

	res = my_parse_cmdtree(&str);
	if (res.err != 0)
		return ((t_cmdtree_or_err){ .err = res.err, .cmdtree = NULL});
	if (my_tok_type(str) != EOF)
	{
		//put error near token my_tok_type(inputline)
		my_cmdtree_del(&res.cmdtree);
		return ((t_cmdtree_or_err){ .err = LEX_ERR, .cmdtree = NULL});
	}
	return (res);
}
