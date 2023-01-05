/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_contains.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:41:38 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/05 15:51:36 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/token.h"

#include <stdbool.h>//bool
#include <stddef.h>//NULL

bool	my_tok_contains(t_token const *toks, t_token_type const *refs, size_t size)
{
	size_t	i;

	while (toks != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (toks->type == refs[i])
				return (true);
			i++;
		}
		toks = toks->next;
	}
	return (false);
}
