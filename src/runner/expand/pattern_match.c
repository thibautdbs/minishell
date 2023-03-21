/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_match.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:23:22 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/20 16:04:44 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include <stdbool.h>

#include "minishell/wtoklst.h"

static bool	loc_begin_with(char const *prefix, char const *str);

bool	my_pattern_match(t_wtoklst *toks, char const *str)
{
	if (toks->type == WILDCARD && *str == '.')
		return (false);
	while (*str != '\0')
	{
		if (toks == NULL)
			return (false);
		if (toks->type == WILDCARD)
		{
			if (toks->next == NULL)
				return (true);
			if (loc_begin_with(toks->next->content, str)
				&& (toks->next->next != NULL
					|| ft_strlen(toks->next->content) == ft_strlen(str)))
				toks = toks->next;
			else
				str++;
			continue ;
		}
		if (loc_begin_with(toks->content, str) == false)
			return (false);
		str += ft_strlen(toks->content);
		toks = toks->next;
	}
	return (toks == NULL || (toks->type == WILDCARD && toks->next == NULL));
}

static bool	loc_begin_with(char const *prefix, char const *str)
{
	return (ft_strncmp(str, prefix, ft_strlen(prefix)) == 0);
}
