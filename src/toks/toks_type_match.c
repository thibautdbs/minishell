/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toks_type_match.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:12:05 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/12 13:17:51 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/toks.h"

#include <stdbool.h>

bool	my_toks_type_match(t_toks const *tok, t_tok_t const *types, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tok->type == types[i])
			return (true);
		i++;
	}
	return (false);
}
