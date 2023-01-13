/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toks_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:48:49 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/13 17:14:06 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/toks.h"

#include <stddef.h>//NULL

#include "libft.h"

void	my_toks_del(t_toks **toks)
{
	t_toks	*curr;
	t_toks	*next;

	curr = *toks;
	while (curr != NULL)
	{
		next = curr->next;
		ft_memdel(&curr->content);
		ft_memdel(&curr);
		curr = next;
	}
	*toks = NULL;
}
