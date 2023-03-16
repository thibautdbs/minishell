/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:00:22 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/03 13:00:57 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wtoklst.h"

#include <stddef.h>//NULL

t_wtoklst	*my_wtoklst_last(t_wtoklst *toks)
{
	while (toks->next != NULL)
		toks = toks->next;
	return (toks);
}
