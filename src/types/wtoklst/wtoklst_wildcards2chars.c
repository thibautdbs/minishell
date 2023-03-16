/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_wildcards2chars.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:43:03 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/06 11:46:26 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wtoklst.h"

#include <stddef.h>//NULL

void	my_wtoklst_convert(t_wtoklst *toks, t_wtoklst_t from, t_wtoklst_t to)
{
	while (toks != NULL)
	{
		if (toks->type == from)
			toks->type = to;
		toks = toks->next;
	}
}
