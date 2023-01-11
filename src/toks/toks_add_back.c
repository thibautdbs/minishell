/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toks_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:15:55 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/11 23:28:30 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/toks.h"

#include <stddef.h>//NULL

void	my_toks_add_back(t_toks **toks, t_toks *new_tok)
{
	if (*toks == NULL)
		*toks = new_tok;
	my_toks_last(*toks)->next = new_tok;
}
