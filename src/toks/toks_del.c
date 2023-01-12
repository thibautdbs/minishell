/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toks_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:48:49 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/12 13:01:22 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/toks.h"

#include <stddef.h>//NULL

void	my_toks_del(t_toks **toks)
{
	t_toks	**next;

	while (*toks != NULL)
	{
		next = &(*toks)->next;
		my_toks_del_one(toks);
		toks = next;
	}
}
