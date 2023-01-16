/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_skip_blanks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:51:31 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/16 07:53:25 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/parser.h"

#include <stddef.h>//NULL

#include "minishell/toks.h"

void	my_parse_skip_blanks(t_toks const **toks)
{
	while (*toks != NULL && (*toks)->type == BLANKS)
		*toks = (*toks)->next;
}
