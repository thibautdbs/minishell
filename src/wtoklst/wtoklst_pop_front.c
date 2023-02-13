/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wtoklst_pop_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdubois <tdubois@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 02:20:55 by tdubois           #+#    #+#             */
/*   Updated: 2023/02/04 02:24:09 by tdubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/wtoklst.h"

#include <stddef.h>//NULL

t_wtoklst	*my_wtoklst_pop_front(t_wtoklst **ptoks)
{
	t_wtoklst	*first;

	if (*ptoks == NULL)
		return (NULL);
	first = *ptoks;
	*ptoks = first->next;
	first->next = NULL;
	return (first);
}
