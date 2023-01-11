/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toks_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:38:11 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/11 23:51:21 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/toks.h"

#include "libft.h"

static void	loc_del_tok(t_toks **tok);

void	my_toks_destroy(t_toks	**toks)
{
	t_toks	**curr;
	t_toks	**next;

	curr = toks;
	while (*curr != NULL)
	{
		next = &(*curr)->next;
		loc_del_tok(curr);
		curr = next;
	}
}

static void	loc_del_tok(t_toks **tok)
{
	if ((*tok)->type == WORD)
		ft_memdel(&(*tok)->content);
	ft_memdel(tok);
}
