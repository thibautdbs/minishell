/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toks_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:19:47 by tdubois           #+#    #+#             */
/*   Updated: 2023/01/12 13:21:04 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/toks.h"

#include <stddef.h>//NULL

t_toks	*my_toks_last(t_toks *toks)
{
	while (toks->next != NULL)
		toks = toks->next;
	return (toks);
}
