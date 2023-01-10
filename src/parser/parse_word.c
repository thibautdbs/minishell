/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffeaugas <ffeaugas@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:41:07 by ffeaugas          #+#    #+#             */
/*   Updated: 2023/01/09 10:03:05 by ffeaugas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <stddef.h>

#include "minishell/arg.h"

t_arg *my_parse_word(t_token *toks)
{
	t_arg	*arg;
	char	*content;

	content = ft_strdup(toks->content);
	if (content == NULL)
		return (NULL);
	arg = my_arg_create();
	if (arg == NULL)
	{
		ft_memdel(&content);
		return (NULL);
	}
	my_arg_addback(my_parse_expansion(toks->next));
	return (arg);
}
