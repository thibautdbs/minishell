/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toks_has_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:26:05 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/16 08:28:17 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/toks.h"

#include <stdbool.h>

bool	my_toks_has_type(t_toks const *tok, t_tok_t *types, int nmemb)
{
	int	i;

	i = 0;
	while (i < nmemb)
	{
		if (tok->type == types[i])
			return (true);
		i++;
	}
	return (false);
}
