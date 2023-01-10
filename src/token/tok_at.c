/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_at.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:37:29 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/10 11:29:02 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/token.h"

#include <stddef.h>//NULL,size_t

t_tok	*my_tok_at(t_tok *toks, int idx)
{
	size_t const	size = my_tok_size(toks);
	int				i;

	if (idx < 0)
		idx = size + idx;
	i = 0;
	while (toks != NULL)
	{
		if (i == idx)
			return (toks);
		i++;
		toks = toks->next;
	}
	return (NULL);
}
