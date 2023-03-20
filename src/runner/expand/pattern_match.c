/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_match.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:23:22 by tdubois           #+#    #+#             */
/*   Updated: 2023/03/20 13:50:35 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/runner.h"

#include <stdbool.h>

#include "minishell/wtoklst.h"

bool	my_pattern_match(t_wtoklst *toks, char const *str)
{
	size_t	len;

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
			len = ft_strlen(toks->next->content);
			if ((toks->next->next != NULL || len == ft_strlen(str)) &&
					ft_strncmp(toks->next->content, str, len) == 0)
				toks = toks->next;
			else
				str++;
			continue ;
		}
		len = ft_strlen(toks->content);
		if (ft_strncmp(toks->content, str, len) != 0)
			return (false);
		toks = toks->next;
		str += len;
	}
	return (toks == NULL || (toks->type == WILDCARD && toks->next == NULL));
}
